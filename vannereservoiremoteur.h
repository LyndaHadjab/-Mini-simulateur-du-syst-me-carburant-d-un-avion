#ifndef VANNERESMOTEUR_H
#define VANNERESMOTEUR_H

#include"vanne.h"
#include<iostream>
#include<vector>
#include<string>
using namespace  std;

//cette classe permet de présenter les vannes qui sont entre réservoire et moteur
//on les présente sous fourme d'une tbleau a deux dimension //ligne :reservoire colonne moteur

class Vanneresmoteur
{
private:

    int resmot[3][3];//tableau qui contient l'information d'etat de vanne entre reservoire et moteur

    vector <Vanne> mesvannes;//vecteur de vanne //on réaliter on v juste réserver 3 vannes car on a 3 vanner qui
    //permet de relier un moteur a un reservoire


public:

    Vanneresmoteur();//constructeur


    friend ostream&operator<<(ostream&flux,Vanneresmoteur*vm);

    Vanneresmoteur (Vanneresmoteur *v);

    Vanneresmoteur &operator=(Vanneresmoteur *v);

    Vanne&getVanne(int j);

    void afficher();

    void openvanne(int i);//ouvrire la vanne se trouve a l indice i

    void closevanne(int i);//fermer la vanne se trouve a l indice i

   int getinfor(int i,int j);//recuperer si la vanne du reservoir i et moteur j  est fermer ou ouvert

   void setinfo(int i,int j,int inf);//changer l'etat d la vanne du reservoire i et moteur j

   vector<Vanne> vannes();

   ~Vanneresmoteur();


};

#endif // VANNERÉSMOTEUR_H
