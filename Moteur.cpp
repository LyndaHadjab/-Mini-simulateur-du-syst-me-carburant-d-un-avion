#include"Moteur.h"
moteur::moteur(string nom,double consommation)
{
    this->nom=nom;
    this->quantiteconsmm=consommation;
    verifsialimenter=false;
    sonreservoire=NULL;
    canalmoteur=NULL;
    moteurpanne=false;
}

string moteur::getName()
{
    return nom;
}

double moteur:: getQuantite()//récuperer la quantite de consommation du moteur
{
    return  quantiteconsmm;
}

void moteur::setName(string name)//changer le nom du moteur
{
    this->nom = name;
}

void moteur::setQuantite(double quantite)//changer la quantite de consommation du moteur
{
   this->quantiteconsmm = quantite;
}

moteur::moteur(moteur*m)
{
    this->nom = m->nom;
    this->verifsialimenter = m->verifsialimenter;
    this->quantiteconsmm = m->quantiteconsmm;
    this->sonreservoire = m->sonreservoire;//c'est permet parce que on redifiné l'opérateur = dans la classe réservoire
    this->moteurpanne = m->moteurpanne;
    this->canalmoteur = m->canalmoteur;
}

ostream&operator<<(ostream&flux,moteur*m)
{
    flux<<m->nom;
    m->sonreservoire->afficher();
    flux<< m->verifsialimenter;
    flux<<m->quantiteconsmm;
    flux<<m->canalmoteur;
    return  flux;
}

 moteur&moteur::operator=(moteur*m)
{
    this->nom = m->nom;

    this->sonreservoire = m->sonreservoire;
    this->quantiteconsmm = m->quantiteconsmm;

    this->verifsialimenter = m->verifsialimenter;
    this->moteurpanne = m->moteurpanne;
    this->canalmoteur = m->canalmoteur;
}

void moteur::afficher()//afficher le moteur
{
    std::cout<<"Moteur est :"<<nom<<std::endl;
    std::cout<<"\t la consommation est :"<<quantiteconsmm<<std::endl;

}

moteur::~moteur()//détruit l'objet moteur
{

}

bool moteur::estalimenter()
{
    return verifsialimenter;
}

Reservoire* moteur::AdresseSonreservoire()
{
    return sonreservoire;
}

void moteur::initialisermoteur(Reservoire* reser,int quantite)
{
    if(quantite>=0 && quantite != quantiteconsmm) {
        quantiteconsmm = quantite;
    }

    sonreservoire = reser;
    moteurpanne = false;
}

string moteur::getnomreservoirealimentant()//recupere le nom du reservoire alimentant
{
    if(verifsialimenter)
        return  sonreservoire->getNom();
    else
        return "aucun";
}

canaldessin* moteur::canalmoteurgraphic() const//retourner la canal graphique du moteur(qui les relie)
{
     return this->canalmoteur;
}

void moteur::ajoutercanal(canaldessin *canal)
{
    this->canalmoteur = canal;
}

void moteur::modifierReservoirealimentant(Reservoire *reservoire)//au cas ou son reservoire précedant tombe en panne
{
    if (moteurpanne)//si le moteur etait en panne c est a dire son reservoire ne l'alimente pas
    {
        moteurpanne = false;
    }

    if(sonreservoire!=reservoire)
    {
        if(sonreservoire!=NULL)
        {
            sonreservoire->supprimermotsuppl();
        }

        sonreservoire = reservoire;
    }
     //maintenant le réservoire est alimenté et on remplit le canal(une couleur)

    this->verifsialimenter = true;
    modifiercanal(true);
}

void moteur::supprimerReservoirealimentant()
{
    this->verifsialimenter = false;
    modifiercanal(false);
}

void moteur::activeControlePanne()
{
    supprimerReservoirealimentant();
    moteurpanne = true;
}

void moteur::modifiercanal(bool b)
{
    if (b)
    {
        if (canalmoteur != NULL)
        {
            canalmoteur->changecolor(sonreservoire->resgraphique()->carbColor());
        }
    }

    if (canalmoteur != NULL)
    {
        canalmoteur->setcircule(b);
    }
}


