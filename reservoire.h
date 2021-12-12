#ifndef Reservoire_H
#define Reservoire_H
#include <iostream>
#include<string>
#include<QApplication>
#include <QWidget>
#include<QPushButton>

#include"pompeprimaire.h"
#include"pompesecour.h"
#include"dessinerreservoire.h"
using namespace  std;
//cette classe permet de présenter un réservoire

class Reservoire
{

private:


   Pompeprimaire pompeprimaire;//chaque reservoire a deux pompe :primaire et secours

   Pompesecour pompesecour;

   string nom;//le nom du reservoire

   double quantiteC;//quantite du carburant

   double capacite;//capacite du reservoire(quantite maximal qu'il peut contenir

   bool vide;//un boolean qui permet de vérifier si le reservoire est vide ou non

   bool pompepanne;//voir si l'un des pompe du reservoire est n panne

   bool pannevidange;//panne de vidange


   string nomautremoteur;

      reservoiredessin *resdessin;

public:

   Reservoire(string nom,double capaciter);//constructeur qui prend le nom du reservoire et sa capacité//

   Reservoire(Reservoire*r);

   friend ostream& operator<<(ostream&flux, Reservoire*r);//surcharge de l'opérateur <<

   Reservoire&operator=(Reservoire *r);//surcharge de l'opérateur =

   ~Reservoire();//

   string getNom();//recupere le nom du reservoire//

   double getCapaciter();//recupere la capaciter du reservoire//

   double getQuantite();//recupere la quantite du reservoire//

   bool estVide();//verifier si le reservoire est vide//

   Pompesecour getPompesecour();//recupere la pompe de secours//

   Pompeprimaire  getPompeprimaire();//recupere la pompe primaire//

   void setPompeP(Pompeprimaire pp);//

    void setPompeS(Pompesecour ps);//

   void setNom(string nom);//

    double setQuantite(double quantite);//

    void setVide(bool vide);//

    void setCapaciter(double capaciter);//

   void afficher();//

   void viderreservoire();//vider le carburant du reservoire//

   void demarrePompesecour();//mettre en marche la pompe primaire//

   void arreterPompesecour();//arreter la pompe de secour//

   void InjecterPannePompeprimaire();//mettre une panne dans la pompe primaire//

   void InjecterPannePompesecour();//mettre une panne dans la pompe de secour//

   bool PeutdiffuserCarb();//si le réservoire pour diffuser du carburant//

   bool EtatPompeDiffuser();//si les deux pompes diffusent du carburant//

  void setPompepanne(bool b);//changé etat d'une pompe

  void setpannecarburant(bool b);//





  reservoiredessin *resgraphique();//

  void adresseresdessin(reservoiredessin *pp);//

     void update();//

    void supprimermotsuppl();//

    bool alimenteMoteurSup();//

    string moteurautre();//

    void updateMoteurSup(string id);//

    void initialise(int capacite = -1);//


};

#endif // RÉSERVOIRE_H
