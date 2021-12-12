#ifndef pageprincipale_H
#define pageprincipale_H
#include <iostream>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QTimer>

#include "TypeSimulation.h"


#include "widgerconfiguration.h"


#include "ToutLeschema.h"
#include "traiterconnexionregister.h"
#include "TableauBordPILOTE.h"
#include "barreoutils.h"



using namespace std;


class pageprincipale : public QMainWindow
{
    Q_OBJECT

    friend class ClassePrincipale;

public:
    pageprincipale(QWidget *parent = 0);


   ~pageprincipale();

    void interfaceconnexion();

    void schemainterface();



public slots:
    void revenirpagechoix();
    void pageconnexionslot();

    void schemaprin();

signals:
    void modeLibreSignal();



protected:

    QHBoxLayout *boxlayout;

    QWidget *widget;

    monschema *schema;

    connectregister *_loginView;

    Boutil *_toolbar;

    types *choisir;

    configurer *_configurer;






};
#endif // pageprincipale_H
