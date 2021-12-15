#ifndef GERERUSER_H
#define GERERUSER_H
#include <iostream>
#include <list>
#include <string>
#include <ostream>
#include<QFile>
#include<QString>
#include<QTextStream>
#include "user.h"

using namespace std;

class toutuser
{

private:

    vector<user> listeuser;

public:

    toutuser();

    ~toutuser();

    bool ajouteruser(const string& identif, const string& motDePasse);

    void ajouteruser(const user& user);

    void sauverBase();

    user* rechercheruser(const string& id, const string& mdp);

    void afficher();
};
#endif // GERERUSER_H
