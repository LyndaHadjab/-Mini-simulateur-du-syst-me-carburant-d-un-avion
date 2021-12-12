#include "vanne.h"

Vanne::Vanne(string nom)
{
    this->nom=nom;
    ouvert=true;//par defaut tous les vannes sont ouverts
}

  Vanne::~Vanne()
 {
   cout<<"destruction"<<endl;
 }
  string Vanne::getNom()
{
    return this->nom;
}
bool Vanne::estOuvert()
{
return ouvert;
}
void Vanne::setNom(string nom)
{
    this->nom=nom;
}
void Vanne::SetOuvert(bool ouvert)
{
   this->ouvert=ouvert;
    metajour();
}
void Vanne::AfficherVanne()
{
cout<<"\t Vanne:"<<nom<<endl;
cout<<"\t ouvert"<<ouvert<<endl;
}

Vanne::Vanne(Vanne*v)
{
   this->nom=v->nom;
    this->ouvert=v->ouvert;
}

Vanne::Vanne(bool etat,string nom)
{
 this->nom=nom;
    this->ouvert=etat;
}
 ostream&operator<<(ostream&flux,Vanne*v)
 {
     flux<<"la vanne est "<<v->nom<<" etat ouvertµ?:"<<v->ouvert<<endl;
     return flux;
 }
istream&operator>>(istream&flux,Vanne*v)
{
    cout<<"donner un nom"<<endl;
    flux>>v->nom;
    cout<<"donner etat de la vanne"<<endl;
    flux>>v->ouvert;
    return flux;
}

 void Vanne::metajour()
 {
     graphevanne->setOpen(ouvert);
 }


 vannedessin* Vanne::vannegraphe()
 {
 return this->graphevanne;
 }

 void Vanne:: setvanne(vannedessin *graphevanne)
 {
    this->graphevanne=graphevanne;
 }

 void  Vanne:: changercoleur(const QBrush& col, bool b)
 {
     if (b)
         graphevanne->setCarbColor(col);


             graphevanne->setBcirculer(b);

 }
