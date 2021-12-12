#ifndef VANNE_H
#define VANNE_H
#include<iostream>
#include<string>
#include "dessinvanne.h"
#include<iostream>
using namespace std;

class Vanne
{
private:
         vannedessin *graphevanne;//la vanne graphiquement

        string nom;//nom de la vanne

        bool ouvert;//etat de la vanne si il est ouvert ou non


public:

    Vanne(string nom);//constructeur qui permet d initialiser un objet de type vanne

     Vanne(Vanne*v);//constructeur qui permet de prendre une vanne comme paramètre

     Vanne(bool etat,string nom);

    ~Vanne();//destructeur

     friend ostream&operator<<(ostream&flux,Vanne*v);//redifinition de cout<<

      friend istream&operator>>(istream&flux,Vanne*v);//redifinition de cin>>


   string getNom();//recuperer le nom d'une vanne

   bool estOuvert();//recuperer l'etat de la vanne si elle est fermer ou ouvert

   void setNom(string nom);//changer le nom de la vanne

   void SetOuvert(bool ouvert);//changer l'etat de la vanne

    void AfficherVanne();//l'affichage d'une vanne



    void metajour();//procedure qui permet d'ouvrire ou fermet une vanne

    vannedessin *vannegraphe();//recupere la vanne

    void setvanne(vannedessin *graphevanne);//changer la vanne

    void changercoleur(const QBrush& col, bool b);//changer la color


};

#endif // VANNE_H
