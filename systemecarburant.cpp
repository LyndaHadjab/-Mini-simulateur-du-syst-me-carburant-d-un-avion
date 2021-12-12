#include "systemecarburant.h"



SystemCarburant::SystemCarburant() : reservoires(), moteurs(), vannesReservoire(), 
vanneReservoiremoteur()
{
    // initialisation des reservoirs
    reservoires.reserve(3);
     Reservoire r1("TANK1",0);

     Reservoire r2("TANK2",0);

     Reservoire r3("TANK3",0);

    reservoires.push_back(r1);

    reservoires.push_back(r2);

    reservoires.push_back(r3);

    // initialisation des moteurs
    moteurs.reserve(3);

    moteur m1("M1",1);
     moteur m2("M2",1);
      moteur m3("M3",1);

    moteurs.push_back(m1);

    moteurs.push_back(m2);

    moteurs.push_back(m3);

    // On ajoute les observers des res dans les moteurs

    for (int i = 0; i <(int) moteurs.size(); i++)
         moteurs[i].modifierReservoirealimentant(&getreservoire(i));

    // initialisation des vannes entre reservoires
//deux vannereservoire car entre chaque 2 reservoire  on a une vanne et dans notre cas on a 3 vanne
    vannesReservoire.reserve(2);
    Vanne v1("VT12");

    Vanne v2("VT23");

    vannesReservoire.push_back(v1);

    vannesReservoire.push_back(v2);

}






void SystemCarburant::openvannereservoire(int i)
{
    //avant que on ouvre la vanne qui est entre reservoire i et reservoire i+1 il faut bien
    //bien vérifier que cet indice existe
    if(i>=0 && i<(int)vannesReservoire.size())
    {
        vannesReservoire[i].SetOuvert(true);

        cout << "*** ouverture vanne : " << vannesReservoire[i].getNom() << endl;
    }
}
//dans le cas ou on fermer la vanne on fait le transfert du carburant

void SystemCarburant::closevannereservoire(int i)
{
    //fermer vanne
    if (i>=0 && i<(int)vannesReservoire.size())
    {
        vannesReservoire[i].SetOuvert(false);

        cout << "*** fermeture vanne : " << vannesReservoire[i].getNom() << endl;

        transferecarburant();           // transfert après fermeture de vanne
    }
}

//ouvrire vanne qui est entre reservoire et moteur

void SystemCarburant::openvannereservoiremoteur(int i)
{
      vanneReservoiremoteur.openvanne(i);
}

//fermer vanne qui est entre reservoire et moteur
void SystemCarburant::closevannereservoiremoteur(int i)
{
    vanneReservoiremoteur.closevanne(i);
}


// Demarrage et arrêt des pompes de secours

void SystemCarburant::openpompesecour(int i)
{
    if (i>=0 && i<(int)reservoires.size())
    {
        reservoires[i].demarrePompesecour();

        cout << "*** demarrage pompe secours : " << reservoires[i].getNom() << endl;
    }
}

void SystemCarburant::closepompesecour(int i)
{
    if (i>=0 && i<(int)reservoires.size())
    {
        reservoires[i].arreterPompesecour();

        cout << "*** arret pompe secours : " << reservoires[i].getNom() << endl;
    }
}




void SystemCarburant::viderreservoire(int i)
{
    if (i>=0 && i<(int) reservoires.size())
    {
        reservoires[i].viderreservoire();

        cout << "*** vidange du reservoir : " << reservoires[i].getNom() << endl;

        // alerter le controleur de panne que y a un vidange de carburant
        getreservoire(i).setpannecarburant(true);
    }
}
// Panne de la pompe primaire

void SystemCarburant::mettreenpannepprimaire(int i)
{
    if (i>=0 && i<(int)reservoires.size())
    {
        //cout<<"nooooooooooooooooooooooo"<<endl;
        getreservoire(i).InjecterPannePompeprimaire() ;


        // on signale la panne au reservoir
        getreservoire(i).setPompepanne(true);
        getreservoire(i).supprimermotsuppl() ;

        // on parcout tous les moteurs qui observent ce reservoir et on signale la panne
        for (int j = 0; j <(int) moteurs.size(); j++)
        {
            if (  moteurs[j].AdresseSonreservoire() == &(reservoires[i]))
            {
                getMoteur(j).activeControlePanne();

                // Mise à jour de la couleur de la vanne
                int v =vanneindice(i, j);
                vanneReservoiremoteur.getVanne(v).changercoleur(QBrush(), false);
            }
        }
    }
}

void SystemCarburant::mettreenpannepsecours(int i)
{
    if (i>=0 && i<(int)reservoires.size())
    {
        getreservoire(i).InjecterPannePompesecour();

        cout << "*** panne pompe secours : " << getreservoire(i).getNom() << endl;

        // on signale la panne au reservoir
        getreservoire(i).setPompepanne(true);
        // signaler le reservoir qu'il n'alimente plus le moteur
        getreservoire(i).supprimermotsuppl();

        // on parcout tous les moteurs qui observent ce reservoir et on signale la panne
        for (int j = 0; j <(int) moteurs.size(); j++)
        {
            if (moteurs[j].AdresseSonreservoire() == &(reservoires[i]))
            {
               getMoteur(j).activeControlePanne();

                // Mise à jour de la couleur de la vanne
                int v = vanneindice(i, j);
                vanneReservoiremoteur.getVanne(v).changercoleur(QBrush(), false);
            }
        }
    }
}



moteur &SystemCarburant::getMoteur(int i)
{
    if (i>=0 && i<(int)moteurs.size())
        return moteurs[i];

    else
    {
        cout << "hors bornes du tableau de moteurs // : " << i << endl;
        exit(0);
    }
}

Reservoire &SystemCarburant::getreservoire(int i)
{
    if (i>=0 && i<(int)reservoires.size())
       return reservoires[i];

    else
    {
        cout << "hors bornes du tableau de reservoirs // : " << i << endl;
       // exit(0);
    }
}

Vanne &SystemCarburant::getvanneresres(int i)
{
    if (i>=0 && i<vannesReservoire.size())
        return vannesReservoire[i];

    else
    {
        cout << "hors bornes du tableau de vannes RES // : " << i << endl;
        exit(0);
    }
}

Vanneresmoteur &SystemCarburant::getResMot()
{
    return vanneReservoiremoteur;
}




bool SystemCarburant::reservoirediffuse()
{
    int b = false;

    for (int i = 0; i < reservoires.size(); i++)
    {
        if (!getreservoire(i).getPompeprimaire().estPanne() || !getreservoire(i).getPompesecour().estPanne())
        {
            b = true;
        }
    }

    return b;
}





//fonction de consommation

bool SystemCarburant::consommation()
{


 if ((reservoires[0].estVide() && reservoires[1].estVide() && reservoires[2].estVide())
            || !reservoirediffuse())     // si tous les réservoires sont vide vides ou si on peut encore diffuser
    {

         //pour chaque moteur on supprime son reservoire alimentant
     for (int i = 0; i <(int) moteurs.size(); i++)

      {
                 moteurs[i].supprimerReservoirealimentant();
     }


        for (int i = 0; i <(int) vannesReservoire.size(); i++)
         {

            vannesReservoire[i].changercoleur(QBrush(), false);
        }

        for (int i = 0; i < (int)vanneReservoiremoteur.vannes().size(); i++)
          {

            vanneReservoiremoteur.getVanne(i).changercoleur(QBrush(), false);
        }


        return false;
    }

    else
    {
     //on parcour les réservoires et les moteurs

        for (int i = 0; i < (int) reservoires.size(); i++)
        {
            for (int j = 0; j < (int) moteurs.size(); j++)
            {

                if (vanneReservoiremoteur.getinfor(i, j) > 0)
                {

                    if (i == j)
                    {
                      //le cas ou chaque reservoire peut alimenter son propre moteur

            if (reservoires[i].PeutdiffuserCarb())  // si peut diffuser

            {

    double temp = reservoires[i].getQuantite()-5;

        reservoires[i].setQuantite(temp);           // update de la qte de carburant

            moteurs[j].modifierReservoirealimentant(&(reservoires[i]));       // update observer

            }

               else
                        {
                //si il peut pas lui diffuser du carburant on le supprime

             if (&(reservoires[i]) == moteurs[j].AdresseSonreservoire())

            moteurs[j].supprimerReservoirealimentant();
                        }
                    }


                    else
                    {
                        if (reservoires[i].EtatPompeDiffuser())
                        {

                     // si le moteur n'est pas déjà alimenté et que le reservoir alimente un seul moteur
                  if (!moteurs[j].estalimenter()   && !reservoires[i] .alimenteMoteurSup()  )
                            {
   double temp = reservoires[i].getQuantite()-5;

              reservoires[i].setQuantite(temp);

                moteurs[j].modifierReservoirealimentant(&(reservoires[i]));

                 reservoires[i].updateMoteurSup(moteurs[j].getName());

                                // update de la couleur des vannes selon le reservoir qui alimente

                                int v = vanneindice(i, j);
                                vanneReservoiremoteur.getVanne(v).changercoleur(getreservoire(i).resgraphique()->carbColor(), true);
                            }

                            // alimente le moteur sup qu'il alimente déjà
                            else if (reservoires[i].alimenteMoteurSup() && (reservoires[i].moteurautre()  == moteurs[j].getName()))
                            {
        double temp = reservoires[i].getQuantite() -5;
                                reservoires[i].setQuantite(temp);
                            }


                        }

                        else
                        {
                            if (&(reservoires[i]) == moteurs[j].AdresseSonreservoire())
                            {
                                moteurs[j].supprimerReservoirealimentant()  ;
                                reservoires[i].supprimermotsuppl()   ;

                                int v = vanneindice(i, j);
                                vanneReservoiremoteur.getVanne(v).changercoleur(QBrush(), false);
                            }
                        }

                    }

                }



                else
                {
                    if (&(reservoires[i]) == moteurs[j].AdresseSonreservoire())
                    {
                        moteurs[j].supprimerReservoirealimentant();

                        int v = vanneindice(i, j);
                        vanneReservoiremoteur.getVanne(v).changercoleur(QBrush(), false);
                    }
                }

            }

        }


        transferecarburant();
        updateDisplay();

        return true;
    }

}







// on vérifie s'il y a des vannes fermées et on équilibre le niveau de carburant dans les réservoirs

void SystemCarburant::transferecarburant()
{
    // si les deux vannes sont fermées et qu'au moins 1 res non vide
   //si la vanne 0 et 1 sont ouvert et au moins un reservoire est non vide

    if ((!vannesReservoire[0].estOuvert()) && (!vannesReservoire[1].estOuvert()) &&
            (!reservoires[0].estVide() || !reservoires[1].estVide() || !reservoires[2].estVide()))
    {
        double temp = (reservoires[0].getQuantite() + reservoires[1].getQuantite()
                + reservoires[2].getQuantite()) / 3;

        // update des reserves
        double qRes = reservoires[1].setQuantite(temp);
        reservoires[0].setQuantite(temp + qRes/2);      // on répartit le reste dans les deux autres reservoirs
        reservoires[2].setQuantite(temp + qRes/2);


        getvanneresres(0).vannegraphe()->setBcirculer(true);
        getvanneresres(1).vannegraphe()->setBcirculer(true);
    }

    // si seule la vanne VT12 est fermée et res1 ou res2 non vide

    else if (!vannesReservoire[0].estOuvert() && (!reservoires[0].estVide() || !reservoires[1].estVide()))
    {
        double temp = (reservoires[0].getQuantite() + reservoires[1].getQuantite()) / 2;

        // update des reserves
        double qRes = reservoires[1].setQuantite(temp);
        reservoires[0].setQuantite(temp + qRes);

        cout << "*** transfert de carburant entre " << reservoires[0].getNom() << " et "
                  << reservoires[1].getNom() << endl;

        getvanneresres(0).vannegraphe()->setBcirculer(true);
    }

    // Si seule la vanne VT23 est fermer

    else if (!vannesReservoire[1].estOuvert() && (!reservoires[1].estVide() || !reservoires[2].estVide()))
    {
        double temp = (reservoires[1].getQuantite() + reservoires[2].getQuantite()) / 2;

        // update des reserves
        double qRes = reservoires[1].setQuantite(temp);
        reservoires[2].setQuantite(temp + qRes);

        cout << "*** transfert de carburant entre " << reservoires[1].getNom() << " et "
                  << reservoires[2].getNom() << endl;

        getvanneresres(1).vannegraphe()->setBcirculer(true);
    }

    else
    {
        for (int i = 0; i < (int)vannesReservoire.size(); i++)
            getvanneresres(i).vannegraphe()->setBcirculer(false);
    }

    //
    updateDisplay();

}




// Renvoie l'indice de la vanne V en fonction des moteurs et reservoirs concernées

int SystemCarburant::vanneindice(int i, int j)
{
    if ((i == 0 && j == 1) || (i == 1 && j == 0))
        return 0;

    else if ((i == 0 && j == 2) || (i == 2 && j == 0))
        return 1;

    else
        return 2;
}







// Observers Section

grapherm *SystemCarburant::displayOberserver() const
{
    return _displayOberserver;
}

void SystemCarburant::addDisplayOberserver(grapherm *displayOberserver)
{
    _displayOberserver = displayOberserver;
}

void SystemCarburant::updateDisplay()
{

    int pval1 = pourcentage(getreservoire(0));
    int pval2 = pourcentage(getreservoire(1));
    int pval3 = pourcentage(getreservoire(2));


    QString rm1 = QString::fromStdString(getMoteur(0).getnomreservoirealimentant());
    QString rm2 = QString::fromStdString(getMoteur(1).getnomreservoirealimentant());
    QString rm3 = QString::fromStdString(getMoteur(2).getnomreservoirealimentant());

    _displayOberserver->updateBarValues(pval1, pval2, pval3);
    _displayOberserver->updateResMoteur(rm1, rm2, rm3);

}

//
float SystemCarburant::pourcentage( Reservoire& res)
{
    if (res.estVide())
        return 0;

    else
        return (float)( (res.getQuantite()*100) / res.getCapaciter());
}

// Les paramètres de ces fonctions sont facultatifs

void SystemCarburant::initialiser(double r1, double r2, double r3)
{
    getreservoire(0).initialise(r1);
    getreservoire(1).initialise(r2);
    getreservoire(2).initialise(r3);



    // Fermeture des vannes

    for (int i = 0; i < (int)vannesReservoire.size(); i++)
        vannesReservoire[i].SetOuvert(true);

    for (int i = 0; i <(int) vanneReservoiremoteur.vannes().size(); i++)
        vanneReservoiremoteur.openvanne(i);

    // Mise à jour des couleurs

    for (int i = 0; i < (int)vannesReservoire.size(); i++)
        vannesReservoire[i].changercoleur(QBrush(), false);

    for (int i = 0; i < (int)vanneReservoiremoteur.vannes().size(); i++)
        vanneReservoiremoteur.getVanne(i).changercoleur(QBrush(), false);

    //
    updateDisplay();
}


// Reset le modèle

void SystemCarburant::reinitialisermodele()
{
    initialiser(0, 0, 0);

    getMoteur(0).supprimerReservoirealimentant();
    getMoteur(1).supprimerReservoirealimentant();
    getMoteur(2).supprimerReservoirealimentant();


    updateDisplay();
}



SystemCarburant::~SystemCarburant()
{

}


