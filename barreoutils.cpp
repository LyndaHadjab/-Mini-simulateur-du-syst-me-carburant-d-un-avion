#include "barreoutils.h"

Boutil::Boutil() {
  setMovable(false);//elle peut pas etre déplacer(move)
  setFixedHeight(40);

  // initialisation des composants
  QMenu *mymenu = new QMenu;

  buttonconfig = new QPushButton("Configuration");
  buttonconfig->setFixedSize(100, 22);

  menureservoire = new QComboBox;

  menureservoire->addItem("TANK1");

  menureservoire->addItem("TANK2");

  menureservoire->addItem("TANK3");

  menureservoire->setFixedSize(90, 20);


  // initialisations des actions

  log_out = new QPushButton("Quitter");

  log_out->setFixedSize(80,20);

  start = new QPushButton("start");
  start->setFixedSize(80,20);
  start->setEnabled(false);
  restart=new QPushButton("restart");
  restart->setFixedSize(80,20);
  restart->setEnabled(false);
  
  actionpanneprimaire = new QPushButton("pannePP");
  actionpanneprimaire->setFixedSize(80, 20);
  actionpannesecours = new QPushButton("pannePS");
  actionpannesecours->setFixedSize(80, 20);
  
  actionviderRes = new QPushButton("ViderRes");
  actionviderRes->setFixedSize(80, 20);
  
  choix = new QPushButton("Options");
  
  actionidf = new QPushButton("");
  actionidf->setHidden(true);
  actionidf->setFixedSize(80,20);
  actionidf->setEnabled(false);

  QWidget *configWidget = new QWidget;
  QHBoxLayout *hlayout = new QHBoxLayout;

  hlayout->addSpacerItem(new QSpacerItem(10, 32));
  hlayout->addWidget(menureservoire);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(buttonconfig);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(actionpanneprimaire);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(actionpannesecours);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(actionviderRes);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(start);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(restart);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(log_out);
  hlayout->addSpacerItem(new QSpacerItem(5, 32));
  hlayout->addWidget(actionidf);

  configWidget->setLayout(hlayout);

  actionidf->setMenu(mymenu);

  addWidget(configWidget);

  actionidf->setVisible(false);
  menureservoire->setEnabled(false);
  buttonconfig->setEnabled(false);
  actionpanneprimaire->setEnabled(false);
  actionpannesecours->setEnabled(false);
  actionviderRes->setEnabled(false);
}

// initialisation des composants de la barre d'outils

void Boutil::reset() {
  pause = true;

  start->setText("Start");

  start->setToolTip("Lancer la simulation");
}

Boutil::~Boutil() {

  delete choix;
  delete log_out;
  delete actionpanneprimaire;
  delete actionpannesecours;
  delete actionviderRes;
  delete menureservoire;
  delete buttonconfig;
  delete  actionidf;
}

