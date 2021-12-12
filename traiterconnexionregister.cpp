#include "traiterconnexionregister.h"

connectregister::connectregister()
{
    setFixedSize(370,400);


    _connexion = true;


    loginLayout = new QVBoxLayout;//un layout verticalement

    setLayout(loginLayout);//pour l'affichage de QVBoxLayout

//deux cas le cas ou je suis dans etapes connexion et inscription
    connexion = new Loginregister(true);

    registert = new Loginregister(false);


    if (_connexion)
    {
        loginLayout->addWidget(connexion);
    }

    else
    {
        loginLayout->addWidget(registert);
    }


    QObject::connect(connexion->creerCompte, SIGNAL(triggered()), this, SLOT(registerConfigSlot()));

      QObject::connect(connexion->buttonconnexion, SIGNAL(clicked()), this, SLOT(connexionIdSlot()));

    QObject::connect(registert->connecter, SIGNAL(triggered()), this, SLOT(connexionConfigSlot()));

      QObject::connect(registert->buttoninscription, SIGNAL(clicked()), this, SLOT(registerIdSlot()));


}


connectregister::~connectregister()
{

    delete loginLayout;
    delete connexion;
    delete registert;


}




void connectregister::resetComps()
{
    //supprimer la page avec setParent(Null):aucun parent
    connexion->setParent(NULL);
    registert->setParent(NULL);
}

void connectregister::viderChamps()
{
    // réinitialiser les widgets
    connexion->identifiant->setText("");
    connexion->motdepasse->setText("");
    connexion->incorrectidf->setText("");
    registert->identifiant->setText("");
    registert->motdepasse->setText("");
    registert->incorrectidf->setText("");
}




void connectregister::registerWarnings(const QString &msg)
{
    registert->incorrectidf->setText(msg);
}



void connectregister::connexionWarnings(const QString &msg)
{
    connexion->incorrectidf->setText(msg);
}


void connectregister::connexionConfigSlot()
{


    registert->setParent(NULL);
    registert->identifiant->setText("");
    registert->motdepasse->setText("");
    registert->incorrectidf->setText("");

    _connexion = true;
    if (_connexion)
    {
        loginLayout->addWidget(connexion);
    }

    else
    {
        loginLayout->addWidget(registert);
    }
}

void connectregister::registerConfigSlot()
{
    connexion->setParent(NULL);
    connexion->identifiant->setText("");
    connexion->motdepasse->setText("");
    connexion->incorrectidf->setText("");

    _connexion = false;
    if (_connexion)
    {
        loginLayout->addWidget(connexion);
    }

    else
    {
        loginLayout->addWidget(registert);
    }
}
// la connexion et la création génèrent chacun un signal qui envoie à son tour les valeurs des champs id et mdp

void connectregister::connexionIdSlot()
{

    // récupération et conversion des champs QString en string
    string id = connexion->identifiant->text().toStdString();
    string mdp = connexion->motdepasse->text().toStdString();


    if (id != "" && mdp != "")
    {
        emit connexionIdSignal(id, mdp);
    }

    else
    {
        if(id=="" && mdp!="")
        {
        connexionWarnings("Veuillez remplir le champ identifiant: obligatoires!");    // affichage du msg d'erreur
        }
        else
        {
            if(id!="" && mdp=="")
            {
               connexionWarnings("Veuillez remplir le champ mot de passe: obligatoires!");
            }
            else

            {
                if(id=="" && mdp=="")
                {
                    connexionWarnings("Veuillez remplir tous les champs: obligatoires!");

                }
            }
        }
    }

}

void connectregister::registerIdSlot()
{
    // récupération et conversion des champs QString en string
    string id = registert->identifiant->text().toStdString();
    string mdp = registert->motdepasse->text().toStdString();

    if (id != "" && mdp != "")
    {
        emit registerIdSignal(id, mdp);
    }

    else
    {

        if(id=="" && mdp!="")
        {
        connexionWarnings("Veuillez remplir le champ identifiant: obligatoires!");    // affichage du msg d'erreur
        }
        else
        {
            if(id!="" && mdp=="")
            {
               connexionWarnings("Veuillez remplir le champ mot de passe: obligatoires!");
            }
            else

            {
                if(id=="" && mdp=="")
                {
                    connexionWarnings("Veuillez remplir tous les champs: obligatoires!");

                }
            }
        }
    }
}







