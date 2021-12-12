#ifndef SYSTEMECARBURANTPRINCIPALE_H
#define SYSTEMECARBURANTPRINCIPALE_H
#include <QWidget>
#include <QTimer>

#include "systemecarburant.h"
#include "PRINCIPALEPAGE.h"

#include "GererUser.h"
#include "user.h"


class ClassePrincipale : public QWidget
{
    Q_OBJECT

public:
    ClassePrincipale();

    void refreshSceneView();

    void setModeUserPermissions(bool b);
    void setModeLibrePermissions(bool b);
    void setConfigPermissions(bool b);

    void mettreEnPause();

    ~ClassePrincipale();


public slots:


 void startss();
  void restarts();

    void modeLibreSlot();

    void configWidgetSlot();

    void configModelSlot(double r1, double r2, double r3);


    void VTSlot(int i);
    void VSlot(int i);
    void pompeSecoursSlot(int i);
    void consommationSlot();
    void startPauseSlot(bool EnPause);
    void resetSimulationSlot();


    void pannePrimaireSlot();
    void panneSecoursSlot();
    void panneViderResSlot();


    void stopSimulationSlot();


    void connexionVerificationSlot(string id, string mdp);
    void registerVerificationSlot(string id, string mdp);

    void deconnexionSlot();



signals:
    void signalstart(bool);

void signalrestart();



private:
    QTimer *_consoTimer;


    int _tpLatenceRestant;

    pageprincipale *pagep;
    TableauBord *tablepilote;

    SystemCarburant modele;



    toutuser _baseUsers;//initialisation
    user *usercourant;




    bool slibre;
    bool utilmode;
    bool valideconfig;
 bool activerS;

};
#endif // SYSTEMECARBURANTPRINCIPALE_H
