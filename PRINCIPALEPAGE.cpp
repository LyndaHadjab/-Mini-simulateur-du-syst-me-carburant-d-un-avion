#include "PRINCIPALEPAGE.h"

//cette classe permet d'initialiser les objet (par exemple des que en exécute cette application la premiere
//fenetre qui va etre afficher est celle de choix :client ou simulation libre
pageprincipale::pageprincipale(QWidget *parent) : QMainWindow(parent)
{
    // initialisations

    setFixedSize(1200, 500);

    setWindowTitle(tr("Avion simulation"));


    // fonctions d'initialisation
    widget = new QWidget;

    boxlayout = new QHBoxLayout;
    boxlayout->setMargin(0);

    widget->setLayout(boxlayout);

    setCentralWidget(widget);

    // Initialisation de la barre d'outils
    _toolbar = new Boutil;
    addToolBar(_toolbar);
    _toolbar->hide();//pour la premiere interface cella elle sera caché



    // initialisation de l'index, au départ on est sur l'Interface index
    //le choix entre simulation libre et espace client
    choisir = new types;
    //au debut on v afficher celui de chois :entre création d'un compte ou simulation libre
  boxlayout->addWidget(choisir);
    // initialisation de l'Interface de connexion
    _loginView = new connectregister;



    // initialisation de la scene
    schema = new monschema;

    // initialisation du widget de configuration
    _configurer = new configurer;


  //si on clique sur le button de connexion on va executer le slot setLoginslot qui permet d'afficher une aure fenetre
    //contenant l'interface de connexion et d'inscription

    QObject::connect(choisir->connexion, SIGNAL(clicked()), this, SLOT(pageconnexionslot()));
    QObject::connect(choisir->smllibre, SIGNAL(clicked()), this, SLOT(schemaprin()));


}







//


void pageprincipale::interfaceconnexion()
{
    //effacer l'interface courrant pour la remplacer par l interface de connexion
    schema->setParent(NULL);//parent null
    _loginView->setParent(NULL);
    choisir->setParent(NULL);


    while (boxlayout->takeAt(0) != NULL)
        delete boxlayout->takeAt(0);
    boxlayout->addWidget(_loginView); //afficher la fenetre de connexion
}



void pageprincipale::schemainterface()
{
    schema->setParent(NULL);//parent null
    _loginView->setParent(NULL);
    choisir->setParent(NULL);


    while (boxlayout->takeAt(0) != NULL)
        delete boxlayout->takeAt(0);

    // On affiche la barre d'outils(configuration et tous)
 _toolbar->show();

//affichage du schéma
    boxlayout->addWidget(schema);
}

void pageprincipale::revenirpagechoix()
{

    _toolbar->hide();

 //supprimer la page
    schema->setParent(NULL);//parent null
    _loginView->setParent(NULL);
    choisir->setParent(NULL);


    while (boxlayout->takeAt(0) != NULL)
        delete boxlayout->takeAt(0);

    //afficherpageoption
     boxlayout->addWidget(choisir);

}

void pageprincipale::pageconnexionslot()
{
    interfaceconnexion();
}


void pageprincipale::schemaprin()
{
    schemainterface();
    emit modeLibreSignal();
}



pageprincipale::~pageprincipale()
{

    delete _toolbar;
    delete choisir;
    delete _loginView;

    delete schema;
    delete _configurer;
delete boxlayout;

    delete widget;



}

