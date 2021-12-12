#include <iostream>
#include <string>
#include <vector>
#ifndef USER_H
#define USER_H
using namespace std;

class user
{

private:
    string id;
    string mdp;
public:

    user(const string& user, const string& motDePasse);
         user();

         user(user*u);
      friend ostream& operator<<(ostream& flux, const user& user);

     friend istream&operator>>(istream&flux,user&user);

       user&operator=(const user&user);

       user(string &nom);

        ~user();

    string getid() const;
    string getmdp() const;



    void affiche();








};
#endif // USER_H
