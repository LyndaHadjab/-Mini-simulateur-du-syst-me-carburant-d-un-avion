#include "TypeSimulation.h"

/*Cette classe concerne la premiere interface c est a dire l inteface qui v etre afficher pour l'utulisateur
pour qu il choisi une action*/
types::types()
{
    setFixedSize(350,250);

    connexion = new QPushButton("ESPACE CLIENT");

      smllibre = new QPushButton("SIMULATION LIBRE");

    connexion->setFixedSize(300, 40);

    connexion->setStyleSheet("border-radius:5px;""padding: 6px 0 6px 0 ;""color:none;""background:#fffafa;"
                           "font:italic 13px Arial;""border:2px solid #bbb;"":hover:background:#f3f3f3 ");

    smllibre->setFixedSize(300, 40);

    smllibre->setStyleSheet("border-radius:5px;""padding: 6px 0 6px 0 ;""color:none;""background:#fffafa;"
                             "font:italic 13px Arial;""border:2px solid #bbb;"":hover:background:#f3f3f3;"
                            "color:#478bf9;""border:2px solid #478bf9");

    QVBoxLayout *cadre = new QVBoxLayout;//verticalement par contre QHBoxLayout horizontalement

    QSpacerItem *spacer = new QSpacerItem(this->width(), 30);//espace entre les deux label




    cadre->addSpacerItem(spacer);


    cadre->addWidget(smllibre);

    QSpacerItem *spacer1=new QSpacerItem(this->width(),20);

    cadre->addSpacerItem(spacer1);

      cadre->addWidget(connexion);

    setLayout(cadre);

}




types::~types()
{

    delete connexion;
    delete smllibre;

}
