#ifndef MONSYSTEM_H
#define MONSYSTEM_h
#include<vector>
#include<iostream>
#include "reservoire.h"
#include "vanne.h"
#include "vannereservoiremoteur.h"
#include"Moteur.h"
#include<string>
#include"graphereservoiremoteur.h"
using namespace std;
class SystemCarburant
{
    friend class ClassePrincipale;
private:
      vector<Reservoire> reservoires;//les reservoires du systeme
      vector<moteur> moteurs;//les moteurs du système
       vector <Vanne> vannesReservoire;//les vannes reser reser
       Vanneresmoteur vanneReservoiremoteur;//les vannes reser moteur
   grapherm *_displayOberserver;

public:


           SystemCarburant();
           ~SystemCarburant();
           void afficher();
           void viderreservoire(int i);
           void mettreenpannepprimaire(int i);
           void mettreenpannepsecours(int i);

           void openvannereservoire(int i);//ouvrir la vanne du l indice i du tableau vanne
           void closevannereservoire(int i);

          void openvannereservoiremoteur(int i);

          void closevannereservoiremoteur(int i);

          void openpompesecour(int i);//ouvrir la pompe de secour de l indice i du tableau reservoire
          void closepompesecour(int i);

          moteur&getMoteur(int i);
          Reservoire&getreservoire(int i);

          Vanne &getvanneresres(int i);
          Vanneresmoteur &getResMot();
          bool reservoirediffuse();

          bool consommation();
          void transferecarburant();

          int vanneindice(int i,int j);

          grapherm *displayOberserver() const;
          void addDisplayOberserver(grapherm *displayOberserver);
          void updateDisplay();
          float pourcentage( Reservoire &res);
        void initialiser(double r1 = -1,
         double r2 = -1, double r3 = -1) ;

        void reinitialisermodele();


};
#endif // VANNERÉSRÉSERVOIRE_H
