#include "pompeprimaire.h"

Pompeprimaire::Pompeprimaire(string nom):Pompe(nom)
{

}

void Pompeprimaire:: afficherpompe()
{
    cout<<"Pompe primaire:"<<nom<<endl;
    cout<<"etat pompe:"<<estpanne<<endl;
}

Pompeprimaire & Pompeprimaire::operator=(const Pompeprimaire& pm)
{
   nom = pm.nom;
   estpanne = pm.estpanne;
   return  *this;
}

Pompeprimaire::~Pompeprimaire()
{

}

Pompeprimaire::Pompeprimaire(Pompeprimaire*p)
{
    this->nom = p->nom;
    this->estpanne = p->estpanne;
    this->marche = p->marche;
}

Pompeprimaire::Pompeprimaire(bool etat1,bool etat2,string nom):Pompe(nom)
{
    this->estpanne = etat1;
    this->marche = etat2;
}

istream&operator>>(istream&flux,Pompeprimaire *p)
{
    cout<<"donner un nom"<<endl;
    flux>>p->nom;
    cout<<"donner l'etat:en pane ou non"<<endl;
    flux>>p->estpanne;
    cout<<"donner l'etat :marche ou non"<<endl;
    flux>>p->marche;
    return flux;
}

ostream&operator<<(ostream&flux,const Pompeprimaire *p)
{
    flux<<"le nom de la pompe primaire est "<<p->nom<<" en panne=:"<<p->estpanne<<"  en marche="<<p->marche
    <<endl;
    return flux;
}