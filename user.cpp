#include "user.h"


using namespace std;


user::user(const string &user, const string &motDePasse): id(user), mdp(motDePasse)
{

}
user::user(user*u)
{
    this->id=u->id;
    this->mdp=u->mdp;
}

string user::getid() const
{
    return id;
}

string user::getmdp() const
{
    return mdp;
}



// Affichage des champs

void user::affiche()
{
    cout << "identifiant : " << id  << endl;
    cout << "mot de passe : " << mdp << endl;
}


user::~user()
{

}
 ostream& operator<<(ostream& flux, const user& user)
 {
       flux<<user.id;
       flux<<user.mdp;
       return  flux;
 }


user::user()
{

}

istream& operator>>(istream&flux,user&user)
{
    cout<<"donner nom user"<<endl;
    flux>>user.id;
    cout<<"donner mot de passe "<<endl;
    flux>>user.mdp;
}

user& user::operator=(const user&user)
{
      this->id=user.id;
    this->mdp=user.mdp;

}

user::user(string &nom)
{
    this->id=nom;
    this->mdp="";

}
