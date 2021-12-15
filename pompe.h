#ifndef POMPE_H
#define POMPE_H
#include<QString>
#include<QApplication>
#include <QWidget>
#include<QPushButton>
#include<iostream>
#include<string>
using namespace std;
//cette classe permet de présenter la classe pompe :elle est caractériser par le nom de la pompe ,
//et son etat :en panne ou non
class Pompe
{
   public:

    string nom;
    bool estpanne;

  public:

    Pompe(string nom);

    Pompe();

    Pompe(bool etat);

    Pompe(bool etat,string nom);

    Pompe& operator=(Pompe*p);

    friend istream&operator>>(istream&flux,Pompe*p);

    friend ostream&operator<<(ostream&flux,Pompe*p);

    Pompe(Pompe *p);
    
    ~Pompe();

    string getNom();

    bool estPanne();

    void SetNom(string nom);

    void SetPanne(bool panne);

    void afficherpompe();
};

#endif // POMPE_H
