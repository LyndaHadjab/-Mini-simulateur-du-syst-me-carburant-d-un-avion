#ifndef MOTEUR_H
#define MOTEUR_H
#include "pompe.h"
#include<QApplication>
#include<QWidget>
#include<QPushButton>
#include<string>
#include<QVector>
#include<iostream>
#include "reservoire.h"
#include "canalgraphe.h"
#include "graphereservoiremoteur.h"
using namespace std;
class moteur
{
       private:
              string nom;//nom du réservoire

              double quantiteconsmm;//quantité de consommation du réservoire

              Reservoire *sonreservoire;//le réservoir alimentant du moteur

              bool verifsialimenter;//pour voir si le moteur est alimenté par l'un des réservoires

              canaldessin *canalmoteur;//adresse du canal graphic reliant le moteur

              bool moteurpanne;//verifier si le moteur a subi une panne c est a dire aucun réservoire ne l'alimente

       public:

              moteur(string nom,double quantitconsmm);//le nom du moteur et la quantite de consommation
              
              moteur(moteur*m);

              friend ostream&operator<<(ostream&flux,moteur*m);

              moteur&operator=(moteur*m);

              ~moteur();//détruit l'objet moteur

              string getName();//recupérer le nom du moteur

              double getQuantite();//récuperer la quantite de consommation du moteur

              void setName(string name);//changer le nom du moteur

              void setQuantite(double quantite);//changer la quantite de consommation du moteur

              void afficher();//afficher le moteur

              bool estalimenter();//verifier si le moteur est alimenter

              Reservoire* AdresseSonreservoire();//adresse du reservoire qui l'alimente

              void initialisermoteur(Reservoire* reser,int quantite=0);//changer la quatiter d consommation

              string getnomreservoirealimentant();//recupere le nom du reservoire alimentant

              void modifierReservoirealimentant(Reservoire *reservoire);//modier le réservoire alimentant de moteur

              void supprimerReservoirealimentant();//supprimer réservoire alimentant

              canaldessin* canalmoteurgraphic() const;//permet recupere la canal du moteur fraphiquement

              void ajoutercanal(canaldessin* canal);//ajouter une autre canal qui relier le moteur graphiquement

              void modifiercanal(bool b);//modifier etat canal

              void activeControlePanne();
};

#endif // MOTEUR_H
