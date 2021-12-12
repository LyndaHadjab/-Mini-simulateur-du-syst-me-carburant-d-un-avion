#include "widgerconfiguration.h"

configurer::configurer()
{
    setWindowTitle("Systemecarburant");
    setFixedSize(400, 220);


   //des doublespinbox :
    res1config = new QDoubleSpinBox;
    res2config = new QDoubleSpinBox;
    res3config = new QDoubleSpinBox;
    res1label = new QLabel("TANK 1 : ");
    res2label = new QLabel("TANK 2 : ");
     res3label = new QLabel("TANK 3 : ");

    // Valeurs par défaut


    res1config->setMaximum(9000);

    res2config->setRange(0, 8000);

    res3config->setMaximum(9000);

//on augmente a chaque fois de 1

    res1config->setSingleStep(1);

    res2config->setSingleStep(1);

    res3config->setSingleStep(1);




    //deux boutton pour valider ou annuler la configuration



    QGroupBox *groupbox = new QGroupBox("Configuration");

//un QGridLayout pour organiser l emplacement des  button en fonction de colonne et de ligne
    QGridLayout *glayout = new QGridLayout;

    glayout->addWidget(res1label, 0, 2);
    glayout->addWidget(res1config, 0, 3);

    glayout->addWidget(res2label, 1, 2);
    glayout->addWidget(res2config, 1, 3);

    glayout->addWidget(res3label, 2, 2);
    glayout->addWidget(res3config, 2, 3);

    valider = new QPushButton("Valider");
    annuler = new QPushButton("Annuler");

    glayout->addWidget(valider,3,2);
    glayout->addWidget(annuler,3,3);

    groupbox->setLayout(glayout);


    //pour lafficher n utilise un QHBoxLayyout et on fait addwidget
    QHBoxLayout *classlayout = new QHBoxLayout;
    classlayout->setMargin(1);
    classlayout->addWidget(groupbox);

    setLayout(classlayout);


    // Connexion des signaux

    QObject::connect(res2config, SIGNAL(valueChanged(double)), this, SLOT(res2CapaciteSlot(double)));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(cancelSlot()));
    QObject::connect(valider, SIGNAL(clicked()), this, SLOT(validSlot()));

}


void configurer::res2CapaciteSlot(double v)
{
    res1config->setMinimum(v+1);
    res3config->setMinimum(v+1);

}

void configurer::validSlot()
{
    //on va emetrre les signaux et on cache la fenetre de configuration

    emit capacitesignal(res1config->value(), res2config->value(), res3config->value());
//on la cache
    hide();
}

void configurer::cancelSlot()
{
  //on la chache
    hide();
}



configurer::~configurer()
{

    delete res1config;
    delete res2config;
    delete res3config;
   delete  res1label;
    delete res2label;
    delete res3label;
   delete valider;
    delete annuler;
}


