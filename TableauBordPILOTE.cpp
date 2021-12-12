#include "TableauBordPILOTE.h"

TableauBord::TableauBord()
{

    setFixedSize(336, 130);
    setWindowTitle("Tableau de bord du pilote");
     setWindowFlags(Qt::WindowStaysOnTopHint);//fixer la fenetre

    VT12button=new QPushButton("VT12");
    VT12button->setFixedSize(90,30);
    VT12button->clicked(false);

    VT23button = new QPushButton("VT23");
    VT23button->setFixedSize(90,30);
    VT23button->clicked(false);

    P12button = new QPushButton( "P12");
    P12button->setFixedSize(90,30);
    P12button->clicked(false);

    P22button = new QPushButton("P22");
    P22button->setFixedSize(90,30);
    P22button->clicked(false);

    P32button = new QPushButton("P32");
    P32button->setFixedSize(90,30);
    P32button->clicked(false);

    V12button = new QPushButton("V12");
    V12button->setFixedSize(90,30);
    V12button->clicked(false);

    V13button = new QPushButton("V13");
    V13button->setFixedSize(90,30);
    V13button->clicked(false);


    V23button = new QPushButton("V23");
    V23button->setFixedSize(90,30);
    V23button->clicked(false);



    QGridLayout *glayout = new QGridLayout;

   //addWidget(button,row,column,rowspa,colspan)
    glayout->addWidget(VT12button, 0, 2, 1, 3);
    glayout->addWidget(VT23button, 0, 6, 1, 3);
    glayout->addWidget(P12button, 1, 0, 1, 3);
    glayout->addWidget(P22button, 1, 4, 1, 3);
    glayout->addWidget(P32button, 1, 8, 1, 3);
    glayout->addWidget(V12button, 2, 0, 1, 3);
    glayout->addWidget(V13button, 2, 4, 1, 3);
    glayout->addWidget(V23button, 2, 8, 1, 3);

    setLayout(glayout);//affichage des button qui va permettre au pilote de controler le systeme carburant

    QObject::connect(VT12button, SIGNAL(clicked()), this, SLOT(VT12Slot()));
    QObject::connect(VT23button, SIGNAL(clicked()), this, SLOT(VT23Slot()));
    QObject::connect(V12button, SIGNAL(clicked()), this, SLOT(V12Slot()));
    QObject::connect(V13button, SIGNAL(clicked()), this, SLOT(V13Slot()));
    QObject::connect(V23button, SIGNAL(clicked()), this, SLOT(V23Slot()));
     QObject::connect(P12button, SIGNAL(clicked()), this, SLOT(ps12Slot()));
    QObject::connect(P22button, SIGNAL(clicked()), this, SLOT(ps22Slot()));
    QObject::connect(P32button, SIGNAL(clicked()), this, SLOT(ps32Slot()));
}




void TableauBord::annulerinit()
{

    VT12button->setFlat(false);


    VT23button->setFlat(false);


    P12button->setFlat(false);


     P22button->setFlat(false);


     P32button->setFlat(false);

     V12button->setFlat(false);

       V13button->setFlat(false);

           V23button->setFlat(false);


}

void TableauBord::VT12Slot()
{

    VT12button->setFlat("true");

    emit VT12Signal(0);
}

void TableauBord::VT23Slot()
{
    VT23button->setFlat(true);

    emit VT23Signal(1);
}

void TableauBord::V12Slot()
{
   V12button->setFlat(true);
    emit V12Signal(0);
}

void TableauBord::V13Slot()
{
   V13button->setFlat(true);
    emit V13Signal(1);
}

void TableauBord::V23Slot()
{
  V23button->setFlat(true);
    emit V23Signal(2);
}

void TableauBord::ps12Slot()
{
    P12button->setFlat(true);
    emit ps12Signal(0);
}

void TableauBord::ps22Slot()
{
   P22button->setFlat(true);
    emit ps22Signal(1);
}

void TableauBord::ps32Slot()
{
   P32button->setFlat(true);
    emit ps32Signal(2);
}



TableauBord::~TableauBord()
{


    delete VT12button;
    delete VT23button;
    delete P12button;
    delete P22button;
    delete P32button;
    delete V12button;
    delete V13button;
    delete V23button;


}

