#include"pompe.h"
Pompe::Pompe(string nom)
{
this->nom=nom;
  estpanne=false;
}
string Pompe:: getNom()
{
return nom;
}
bool Pompe:: estPanne()
{
   return estpanne;
}
void Pompe::SetNom(string nom)
{
 this->nom=nom;
}
void Pompe::SetPanne(bool panne)
{
  estpanne=panne;
}

Pompe::~Pompe()
{
   cout<<"destruction"<<endl;
}

Pompe::Pompe()
{
    this->nom="p";
    this->estpanne=false;
}
Pompe:: Pompe(Pompe *p)
{
    this->nom=p->nom;
    this->estpanne=p->estpanne;
}

Pompe::Pompe(bool etat)
{
    if(etat==true)
    {
        cout<<"interdit etat au debut doit pas etre en panne"<<endl;
    }
    else
    {
        if(etat==false)
        {
            this->estpanne=etat;
        }
    }
}
Pompe::Pompe(bool etat,string nom)
{
    this->nom=nom;
    if(etat==true)
    {
        cout<<"interdit pompe n'est pas en panne"<<endl;
    }
    else
    {
        if(etat==false)
        {
            this->estpanne=etat;
        }
    }
}

 istream&operator>>(istream&flux,Pompe*p)
 {
   cout<<"donner un nom pour la pompe"<<endl;
   flux>>p->nom;
   cout<<"donner son etat initiale"<<endl;

  flux>>p->estpanne;
  return  flux;
 }
 ostream&operator<<(ostream&flux,Pompe*p)
 {
   flux<<"le nom de la pompe est"<<p->nom<<" son etat est: "<<p->estpanne<<endl;
   return  flux;
 }
void Pompe:: afficherpompe()
{
    cout<<"pompe est "<<endl;
    cout<<this->nom;
    cout<<this->estpanne;
}
  Pompe&Pompe:: operator=(Pompe*p)
  {
this->nom=p->nom;
      this->estpanne=p->estpanne;
  }
