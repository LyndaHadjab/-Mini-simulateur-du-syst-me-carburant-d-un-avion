#include"reservoire.h"

Reservoire::Reservoire(string nom,double capaciter):pompeprimaire("P11"),pompesecour("p12")
{
    this->nom=nom;
   this->capacite=capaciter;
    this->quantiteC=capacite;
   this->vide=false;
    pompepanne=false;
     pannevidange=false;
    nomautremoteur="";
}

Reservoire::~Reservoire()
{

}

Reservoire::Reservoire(Reservoire*r):pompeprimaire(r->getNom()),pompesecour(r->getNom())
{
    this->nom=r->nom;

    this->capacite=r->capacite;
    this->quantiteC=r->quantiteC;
    this->vide=r->vide;
    this->pompepanne=r->pompepanne;
    this->pannevidange=r->pannevidange;
    this->nomautremoteur=r->nomautremoteur;

}


void Reservoire::supprimermotsuppl()
{
    if (!pompepanne)
        nomautremoteur = "";
}

bool Reservoire::alimenteMoteurSup()
{
    if (nomautremoteur != "")
        return true;
    else
        return false;
}



void Reservoire::updateMoteurSup(string id)
{
    nomautremoteur = id;
}

string Reservoire::getNom()
{
    return  this->nom;
}
double Reservoire:: getCapaciter()
{
  return this->capacite;
}
double Reservoire::getQuantite()
{
  return this->quantiteC;
}
bool Reservoire::estVide()
{
return this->vide;
}
Pompesecour Reservoire::getPompesecour()
{
  return this->pompesecour;
}
Pompeprimaire Reservoire:: getPompeprimaire()
{
   return this->pompeprimaire;
}
void Reservoire::setPompeP(Pompeprimaire pp)
{
    this->pompeprimaire=pp;


}
 void Reservoire::setPompeS(Pompesecour ps)
 {
    this->pompesecour=ps;//on a déja redefiné l'opérateur = dans la classe pompe
 }

void Reservoire::setNom(string nom)
{
    this->nom=nom;
}
 double Reservoire::setQuantite(double quantite)//la quantite de carburant ne doit pas dépasse la capacité du réservoire
 {
      double qcarburantRes=0;
      if(quantite<=0.5)//si la quantite donner est inférieur a 0.9 alors on
          //considère que le reservoire est vide
      {
          this->quantiteC=0;
          setVide(true);
      }
 else
      {
          if(quantite>this->capacite)//si la quantite donner supérieur a la capacité du reservoire
              //alors on met la quantite du carburant egale a la capacité du reservoire
          {
              this->quantiteC=this->capacite;
              qcarburantRes=quantite-this->capacite;
          }
          else
                 this->quantiteC=quantite;
          setVide(false);
      }
      if (pannevidange &&  quantiteC> 0)
      {
          pannevidange = false;

      }

      return qcarburantRes;
 }

 void Reservoire::setVide(bool vide)
 {
       this->vide=vide;
     resdessin->setBcirculer(!this->vide);


 }
 void Reservoire::setCapaciter(double capaciter)
 {
     if(capaciter<0)
     {
         capaciter*=-1;
     }
     this->capacite=capaciter;
 }
void Reservoire::afficher()
{
            cout<<"Le réservoire :"<<nom<<endl;

            cout<<"La capacité :"<<capacite<<endl;

            cout<<"La quantite du carburant :"<<quantiteC<<endl;

            cout<<"etat:"<<vide<<endl;

            pompeprimaire.afficherpompe();

            pompesecour.afficherpompe();

}
ostream& operator<<(ostream&flux, Reservoire*r)
{
       flux<<"Le reservoire est:"<<endl;

       flux<<"Le réservoire :"<<r->nom<<endl;
       flux<<"La capacité :"<<r->capacite<<endl;
       flux<<"La quantite du carburant :"<<r->quantiteC<<endl;
       flux<<"etat:"<<r->vide<<endl;
      r->pompeprimaire.afficherpompe();
       r->pompesecour.afficherpompe();
       return  flux;

}

Reservoire& Reservoire::operator=(Reservoire *r)
{
         this->nom=r->nom;
    this->capacite=r->capacite;
    this->quantiteC=r->quantiteC;
    this->vide=r->vide;
    this->pompeprimaire=r->pompeprimaire;
    this->pompesecour=r->pompesecour;
}
reservoiredessin *Reservoire::resgraphique()
{
    return resdessin;
}
void Reservoire::viderreservoire()
{
   this->setQuantite(0);
}
void Reservoire::demarrePompesecour()
{
     pompesecour.setMarche(true);
     resdessin->setsmarche(true);
}
void Reservoire::arreterPompesecour()
{
    pompesecour.setMarche(false);
    resdessin->setsmarche(false);
}
void Reservoire::InjecterPannePompeprimaire()
{
      pompeprimaire.SetPanne(true);
      resdessin->setpmarche(false);
       resdessin->setppanne(true);


}
void Reservoire::InjecterPannePompesecour()
{
     pompesecour.setPanne(true);
     arreterPompesecour();
     resdessin->setspanne(true);
}
bool Reservoire::PeutdiffuserCarb()
{
   if(estVide())

       return false;//si le reservoir est vide alors il peut pas de diffuser du carburant
   if(pompeprimaire.estPanne() && (pompesecour.estPanne()||!pompesecour.Enmarche()))//si les deux pompse sont en panne alors il peut pas
           return false;
   else
       return true;
   }

bool Reservoire::EtatPompeDiffuser()
{
    //si les deux pompe diffusent du carburants
    if(!estVide() && !pompeprimaire.estPanne() && pompesecour.Enmarche())
    {
        return true;
    }
    else
        return false;
}

void Reservoire::setPompepanne(bool b)
{
     this->pompepanne=b;

}
void Reservoire::setpannecarburant(bool b)
{
    pannevidange=b;

}

string Reservoire::moteurautre()
{
    return nomautremoteur;
}
void Reservoire::update()
{
    resdessin->setpmarche(!pompeprimaire.estPanne());    //le contraire de la panne = marche, car marche par défaut
    resdessin->setppanne(pompeprimaire.estPanne());
    resdessin->setsmarche(pompesecour.Enmarche());
    resdessin->setspanne(pompesecour.estPanne());
    resdessin->setBcirculer(!vide);
}


void Reservoire::adresseresdessin(reservoiredessin *pp)
{
    resdessin = pp;
}
void Reservoire::initialise(int capacite)
{
    if (capacite > -1 && this->capacite!= capacite)
        setCapaciter(capacite);
    nomautremoteur = "";
      pompepanne = false;
      pannevidange = false;
    setQuantite(this->capacite);
    pompeprimaire.SetPanne(false);
    pompesecour.setPanne(false);
    pompesecour.setMarche(false);



    update();
}
