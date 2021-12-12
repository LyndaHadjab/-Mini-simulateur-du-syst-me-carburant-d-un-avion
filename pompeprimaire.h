#ifndef POMPEPRIMAIRE_H
#define POMPEPRIMAIRE_H
#include "pompe.h"
#include<iostream>
#include<string.h>
using namespace  std;
class Pompeprimaire :public Pompe
{
private:

    bool marche;//vrai pompe en marche ssinon

public:

    Pompeprimaire(string nom);//le constructeur de pompe primaire

    Pompeprimaire(Pompeprimaire*p);

   Pompeprimaire(bool etat1,bool etat2,string nom);

   friend istream&operator>>(istream&flux,Pompeprimaire *p);

   friend ostream&operator<<(ostream&flux,const Pompeprimaire *p);

     ~Pompeprimaire();//destructeur

    void afficherpompe();//redefinie la fonction afficher du pompe

   Pompeprimaire &operator=(const Pompeprimaire& pm);




};

#endif // POMPEPRIMAIRE_H
