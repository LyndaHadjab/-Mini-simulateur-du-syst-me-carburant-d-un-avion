#include "systemeprincipale.h"

ClassePrincipale::ClassePrincipale():modele(), _baseUsers()
{
    //creer la page principale
   //la premiere interface est celle de choix entre simulation libre et espace client


    pagep = new pageprincipale;

    //l'afficher avec la  show
     pagep->show();

     //creation du tableau du Bord

    tablepilote = new TableauBord;

    tablepilote->setStyleSheet("QPushButton {"
                               "width:70px;"
                               "height:15px;"
                               "padding: 4px 0 4px 0;"
                               "border-radius: 8px;"
                               "background: #f5f5f5;"
                               "border: none;"
                               "color: #555;"
                               "font: bold 12px Arial;"
                               "border: 1px solid #bbb;"
                               "}"

                         "QPushButton:hover {"
                               "color: #3bbd7b;"
                               "border: 2px solid #3bbd7b;"
                               "}");


    usercourant = NULL;

    // Permissions
    slibre = false;
    utilmode = false;
    valideconfig = false;

    activerS = false;

    for (int i = 0; i < 3; i++)
        modele.getreservoire(i).adresseresdessin(pagep->schema->getReservoir(i+8));


    // Les cannaux RM sont en position 14, 15 et 18
//chaque moteur a son propre cannal
    modele.getMoteur(0).ajoutercanal(pagep->schema->getCanal(14));

    modele.getMoteur(1).ajoutercanal(pagep->schema->getCanal(15));

    modele.getMoteur(2).ajoutercanal(pagep->schema->getCanal(18));



    // le tableau d'état se trouve en position 20
    modele.addDisplayOberserver((grapherm*)pagep->schema->outils[20]);

    // les vannes sont compris entre 3-7
    modele.getvanneresres(0).setvanne(pagep->schema->getVanne(3));
    modele.getvanneresres(1).setvanne(pagep->schema->getVanne(4));

    modele.getResMot().getVanne(0).setvanne(pagep->schema->getVanne(5));
    modele.getResMot().getVanne(1).setvanne(pagep->schema->getVanne(6));
    modele.getResMot().getVanne(2).setvanne(pagep->schema->getVanne(7));


    // Initialisation des minuteurs

    _consoTimer = new QTimer;

    _tpLatenceRestant = 0;

    // Connexions des signaux et des slots

    QObject::connect(pagep, SIGNAL(modeLibreSignal()), this, SLOT(modeLibreSlot()));

    QObject::connect(tablepilote, SIGNAL(VT12Signal(int)), this, SLOT(VTSlot(int)));
    QObject::connect(pagep->_toolbar->start, SIGNAL(clicked()), this, SLOT(startss()));
    QObject::connect(pagep->_toolbar->restart, SIGNAL(clicked()), this, SLOT(restarts()));
    QObject::connect(pagep->_toolbar->log_out, SIGNAL(clicked()), this, SLOT(deconnexionSlot()));


    QObject::connect(this,SIGNAL(signalstart(bool)), this, SLOT(startPauseSlot(bool)));

    QObject::connect(this,SIGNAL(signalrestart()), this, SLOT(resetSimulationSlot()));

    QObject::connect(tablepilote, SIGNAL(VT23Signal(int)), this, SLOT(VTSlot(int)));
    QObject::connect(tablepilote, SIGNAL(V12Signal(int)), this, SLOT(VSlot(int)));
    QObject::connect(tablepilote, SIGNAL(V13Signal(int)), this, SLOT(VSlot(int)));
    QObject::connect(tablepilote, SIGNAL(V23Signal(int)), this, SLOT(VSlot(int)));

    QObject::connect(tablepilote, SIGNAL(ps12Signal(int)), this, SLOT(pompeSecoursSlot(int)));
    QObject::connect(tablepilote, SIGNAL(ps22Signal(int)), this, SLOT(pompeSecoursSlot(int)));
    QObject::connect(tablepilote, SIGNAL(ps32Signal(int)), this, SLOT(pompeSecoursSlot(int)));

    QObject::connect(_consoTimer, SIGNAL(timeout()), this, SLOT(consommationSlot()));

     QObject::connect(pagep->_toolbar->actionpanneprimaire, SIGNAL(clicked()), this, SLOT(pannePrimaireSlot()));
    QObject::connect(pagep->_toolbar->actionpannesecours, SIGNAL(clicked()), this, SLOT(panneSecoursSlot()));
    QObject::connect(pagep->_toolbar->actionviderRes,SIGNAL(clicked()), this, SLOT(panneViderResSlot()));


    QObject::connect(pagep->_toolbar->buttonconfig, SIGNAL(clicked()), this, SLOT(configWidgetSlot()));
    QObject::connect(pagep->_configurer, SIGNAL(capacitesignal(double,double,double)), this,
                     SLOT(configModelSlot(double,double,double)));



    QObject::connect(pagep->_loginView, SIGNAL(connexionIdSignal(string, string)), this, SLOT(connexionVerificationSlot(string, string)));
    QObject::connect(pagep->_loginView, SIGNAL(registerIdSignal(string, string)), this, SLOT(registerVerificationSlot(string, string)));




}


void ClassePrincipale::modeLibreSlot()
{
   setModeLibrePermissions(true);
}



void ClassePrincipale::configWidgetSlot()
{
    // mettre en pause si simulation active
    mettreEnPause();

    pagep->_configurer->show();
}

// Configuration du modèle selon les valeurs entrées

void ClassePrincipale::configModelSlot(double r1, double r2, double r3)
{
    resetSimulationSlot();

    modele.initialiser(r1, r2, r3);
    tablepilote->annulerinit();

    if (!valideconfig)
        setConfigPermissions(true);

    refreshSceneView();
}









void ClassePrincipale::VTSlot(int i)
{
    // On inverse la valeur du booléen à chaque clic

    bool nonb = (modele.getvanneresres(i).estOuvert());
    modele.getvanneresres(i).SetOuvert(!nonb);

    refreshSceneView();
}


void ClassePrincipale::VSlot(int i)
{
    bool nonb = !(modele.getResMot().getVanne(i).estOuvert());

    if (nonb)
        modele.getResMot().openvanne(i);

    else
        modele.getResMot().closevanne(i);

    refreshSceneView();
}

void ClassePrincipale::pompeSecoursSlot(int i)
{
    bool nonb = !(modele.getreservoire(i).getPompesecour().Enmarche());

    if (nonb)
        modele.getreservoire(i).demarrePompesecour();

    else
        modele.getreservoire(i).arreterPompesecour();

    refreshSceneView();
}



void ClassePrincipale::pannePrimaireSlot()
{
    // On récupère l'indice du reservoir sélectionné
    int i = pagep->_toolbar->menureservoire->currentIndex();

            modele.mettreenpannepprimaire(i);



    refreshSceneView();
}

void ClassePrincipale::panneSecoursSlot()
{
    int i = pagep->_toolbar->menureservoire->currentIndex();
    modele.mettreenpannepsecours(i);



    refreshSceneView();
}

void ClassePrincipale::panneViderResSlot()
{
    int i = pagep->_toolbar->menureservoire->currentIndex();
    modele.viderreservoire(i);


    refreshSceneView();
}








void ClassePrincipale::consommationSlot()
{
    bool isConso = modele.consommation();

 refreshSceneView();
}

// Démarrage et Pause de la simulation

void ClassePrincipale::startPauseSlot(bool EnPause)
{


    if (!EnPause)
    {
        activerS = true;   // la simulation est en cours

        tablepilote->show();
        _consoTimer->start(500);


    }

    else
    {
        activerS = false;   // la simulation est en pause

        _consoTimer->stop();
        tablepilote->hide();


    }
}


void ClassePrincipale::resetSimulationSlot()
{

    stopSimulationSlot();

    tablepilote->annulerinit();
    modele.initialiser();



    refreshSceneView();
}

void ClassePrincipale::stopSimulationSlot()
{

    _consoTimer->stop();

pagep->_toolbar->reset();


    activerS = false;   // la simulation est arrêté
}



// Les deux fonctions suivantes vérifient la validité des identifiants en paramètres
// Pour la connexion ou la création d'un compte

void ClassePrincipale::connexionVerificationSlot(string id, string mdp)
{
    std::cout<<id<<"    identifiant"<<mdp<<"mot de passe "<<std::endl;
    usercourant = _baseUsers.rechercheruser(id, mdp);

    if (usercourant != NULL)
    {
        // vider les champs
        pagep->_loginView->viderChamps();

        setModeUserPermissions(true);

   pagep->_toolbar->actionidf->setHidden(false);
    pagep->_toolbar->actionidf->setText(QString::fromStdString(usercourant->getid()));  // afficher le pseudo

        pagep->schemainterface();
    }

    else
    {
        pagep->_loginView->connexionWarnings("Identifiants incorrects !");
        cout << " Indentifiants incorrects, veuillez vous enregistrer" << endl;
    }
}


void ClassePrincipale::registerVerificationSlot(string id, string mdp)
{
    bool valid = _baseUsers.ajouteruser(id, mdp);

    if (valid)
    {


        pagep->interfaceconnexion();

        _baseUsers.sauverBase();
        _baseUsers.afficher();

        // vider les champs
        pagep->_loginView->viderChamps();


    }

    else
    {
        pagep->_loginView->registerWarnings("Identifiants invalides !");
    }
}



void ClassePrincipale::deconnexionSlot()
{
    usercourant = NULL;
    resetSimulationSlot();

    // cacher le tableau de bord
    tablepilote->hide();

    // vider tout
    modele.reinitialisermodele() ;

    setModeLibrePermissions(false);
    setModeUserPermissions(false);
    pagep->_toolbar->actionidf->setText("");
    pagep->_toolbar->actionidf->setVisible(false);



    pagep->revenirpagechoix();
}



// met à jour l'affichage des fenêtres, le faire de façon inverse

void ClassePrincipale::refreshSceneView()
{
    modele.updateDisplay();
    pagep->schema->_monschema.update();

}


void ClassePrincipale::mettreEnPause()
{
    if (activerS==true)
      {


        startss();
    }
}




void ClassePrincipale::setModeLibrePermissions(bool b)
{
    if (b==true)
    {
        slibre = true;
        pagep->_toolbar->buttonconfig->setEnabled(true);
    }

    else
    {
        slibre = false;
        setConfigPermissions(false);
        pagep->_toolbar->buttonconfig->setEnabled(false);
    }
}

// Activation des widgets après configuration du modèle

void ClassePrincipale::setConfigPermissions(bool b)
{
    if (b)
    {
  valideconfig = true;


        pagep->_toolbar->menureservoire->setEnabled(true);

        pagep->_toolbar->actionpanneprimaire->setEnabled(true);
        pagep->_toolbar->actionpannesecours->setEnabled(true);
        pagep->_toolbar->actionviderRes->setEnabled(true);
        pagep->_toolbar->start->setEnabled(true);
       pagep->_toolbar->restart->setEnabled(true);
        tablepilote->show();
    }

    else
    {
        valideconfig = false;
        pagep->_toolbar->menureservoire->setEnabled(false);
        pagep->_toolbar->actionpanneprimaire->setEnabled(false);
        pagep->_toolbar->actionpannesecours->setEnabled(false);
        pagep->_toolbar->actionviderRes->setEnabled(false);
        pagep->_toolbar->start->setEnabled(false);
       pagep->_toolbar->restart->setEnabled(false);
        tablepilote->hide();
    }
}


// Mode Utilisateur connecté

void ClassePrincipale::setModeUserPermissions(bool b)
{
    if (b)
    {
        utilmode = true;
        setModeLibrePermissions(true);                  // mode libre inclus

        pagep->_toolbar->actionidf->setVisible(true);

    }

    else
    {
      utilmode = false;
      setModeLibrePermissions(false);

    }
}


ClassePrincipale::~ClassePrincipale()
{
    delete _consoTimer;


    delete tablepilote;
    delete pagep;

}

void ClassePrincipale::startss()
{
    if (pagep->_toolbar->pause)
    {
        pagep->_toolbar->pause = !pagep->_toolbar->pause;
        pagep->_toolbar->start->setText("pause");

         pagep->_toolbar->start->setToolTip("Mettre en pause la simulation");

        emit signalstart(pagep->_toolbar->pause);
    }

    else
    {
        pagep->_toolbar->pause = !pagep->_toolbar->pause;
       pagep->_toolbar->start->setText("start");
        pagep->_toolbar->start->setToolTip("Reprendre la simulation");


        emit signalstart(pagep->_toolbar->pause);
    }
}

void ClassePrincipale:: restarts()
{
       emit signalrestart();
}

