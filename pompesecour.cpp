#include"pompesecour.h"

Pompesecour::Pompesecour(string nom):Pompe(nom)
{
    marche=false;
}

bool Pompesecour:: Enmarche()
{
    return  marche;
}


//destructeur
Pompesecour::~Pompesecour()
{
   cout<<"destruction"<<endl;
}
//redifinition de l'opérateur =
Pompesecour& Pompesecour::operator=(const Pompesecour&ps)
{
   estpanne=ps.estpanne;
   marche=ps.marche;
   nom=ps.nom;
   return *this;
}


void Pompesecour:: setMarche(bool marche)
{
    //avant de la mettre en marcheen verifier si ellen est pas en panne
    if(marche==true)
    {
        if(estpanne==false)
        {
            this->marche=true;
        }
        else
        {
            if(estpanne==true)
           {

                cout<<"la pompe de secour :"<<nom<<"est en panne"<<" on peut pas la mettre en marche" <<endl;
            }
        }
    }
    else
            //si on veut la mettre en arret c est pas la peine de verifier est ce que elle est panne ou non
        //directement on la met en arret
        if(marche==false)
       {
            this->marche=false;
        }

}
void Pompesecour::setPanne(bool panne)
{
    if(panne==true)
    {
        estpanne=true;
      this->marche=false;
    }
    else
        if(panne==false)
       {

            estpanne=panne;
        }
}
void  Pompesecour ::afficherpompe()
{
   cout<<"pompe secour:"<<nom<<endl;
   cout<<"panne"<<estpanne<<endl;
  cout<<"marche"<<marche<<endl;

}
Pompesecour ::Pompesecour(Pompesecour*p):Pompe(p->nom)
{
   this->estpanne=p->estpanne;
   this->marche=p->marche;

}

Pompesecour ::Pompesecour(bool etat1,bool etat2,string nom):Pompe(nom)
{
    this->estpanne=etat1;
    this->marche=etat2;
}


istream& operator>>(istream&flux,Pompesecour*p)
{
     cout<<"donner un nom"<<endl;
     flux>>p->nom;
      cout<<"donner etat"<<endl;
      flux>>p->estpanne;
      cout<<"donner etat"<<endl;
      flux>>p->marche;
      return flux;

}

ostream& operator<<(ostream&flux,Pompesecour*p)
{
    flux<<"le nom de la pompe primaire est "<<p->nom<<" en panne=:"<<p->estpanne<<"  en marche="<<p->marche
       <<endl;
    return flux;
}

