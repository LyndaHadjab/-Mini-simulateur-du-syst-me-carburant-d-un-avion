#ifndef TRAITERCONNEXIONREGISTER_H
#define TRAITERCONNEXIONREGISTER_H

#include <iostream>

#include "LOGINREGISTER.h"
#include "TypeSimulation.h"
using namespace std;

#include <QVBoxLayout>



class connectregister : public    QWidget
{
    Q_OBJECT

    friend class pageprincipale;

public:
    connectregister();
     ~connectregister();
    void resetComps();
    void viderChamps();
    void connexionWarnings(const QString &msg);
    void registerWarnings(const QString &msg);



public slots:
    void connexionConfigSlot();
    void registerConfigSlot();
    void connexionIdSlot();
    void registerIdSlot();

signals:
    void connexionIdSignal(string id, string mdp);
    void registerIdSignal(string id, string mdp);


private:
    Loginregister *connexion;
    Loginregister *registert;
    QVBoxLayout *loginLayout;

   bool _connexion;

};


#endif // TRAITERCONNEXIONREGISTER_H
