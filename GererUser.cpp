#include "GererUser.h"


toutuser::toutuser()
{
    //chemin ou on va stocker les utilisateurs

     QFile fichier("C:\\Users\\Adam Mamadou\\Documents\\pro\\projet\\mesuser.txt");

   if(fichier.open(QIODevice::ReadWrite | QIODevice::Text))
   {

       user *user1;
       string identi;
       string mdp;
       string chaine;
       int numligne=1;

      QTextStream flux(&fichier);

      while(!flux.atEnd())
      {
       QString  chaine1 =flux.readLine();
       chaine=chaine1.toStdString();

       if(chaine=="--//--")
        {

             ajouteruser(*user1);

             numligne=1;
             delete user1;
       }
      else
      if(!chaine.empty())
      {
             if(numligne==1)
             {
                 identi=chaine;
             }
             else
                 if(numligne==2)
                 {
                     mdp=chaine;
                     user1=new user(identi,mdp);
                 }

             numligne++;
      }

      else
          cout << " Le fichier a été modifié" << endl;
      }
  fichier.close();
   }
   else
   {
       std::cout<<"Ouverture impossible"<<endl;
   }


}


bool toutuser::ajouteruser(const string& identif, const string& motDePasse)
{


    for (vector<user>::iterator i = listeuser.begin(); i != listeuser.end(); i++)
    {
        if ((*i).getid() == identif)
            return false;
    }


        listeuser.push_back(user(identif, motDePasse));
        return true;

}

void toutuser::ajouteruser(const user &user)
{
    std::cout<<user.getmdp()<<user.getid()<<std::endl;
    listeuser.push_back(user);
}


void toutuser::sauverBase()
{
QString fichier="C:\\Users\\Adam Mamadou\\Documents\\pro\\projet\\mesuser.txt";

QFile file(fichier);


    if(file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        for (vector<user>::iterator u = listeuser.begin(); u != listeuser.end(); u++)
        {
      QTextStream flux(&file);

       string mot=u->getmdp();
       //la conversion de string vers QString

      QString qstr = QString::fromStdString(mot);
        flux<<QString::fromStdString(u->getid())<<"\r\n";

       flux<<qstr<<"\r\n";
       flux<<"--//--"<<"\r\n";




        }


        file.close();
    }

    else
        cerr << "Erreur d'ouverture du fichier" << "C:\\Users\\Adam Mamadou\\Documents\\pro\\projet\\mesuser.txt" << endl;
}




void toutuser::afficher()
{
    for (vector<user>::iterator u = listeuser.begin(); u != listeuser.end(); u++)
    {
        (*u).affiche();
    }
}



user* toutuser::rechercheruser(const string &id, const string &mdp)
{

    QString fichier="C:\\Users\\Adam Mamadou\\Documents\\pro\\projet\\mesuser.txt";

    QFile file(fichier);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&file);

        while(!flux.atEnd())
        {
            QString  chaine1 =flux.readLine();
         string   idf=chaine1.toStdString();

         QString  chaine2 =flux.readLine();
      string   md=chaine2.toStdString();
      if(idf==id && mdp==md)
      {
          user* u=new user(idf,md);
          return &(*u);
      }



        }
    }


    return NULL;
}

toutuser::~toutuser()
{

}



