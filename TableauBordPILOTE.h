#ifndef TABLEAUBORDPILOTE_H
#define TABLEAUBORDPILOTE_H
#include <iostream>



using namespace std;

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolBar>




class TableauBord : public QWidget
{
    Q_OBJECT


    friend class ClassePrincipale;

public:
    TableauBord();

    void annulerinit();
    ~TableauBord();

public slots:

    void VT12Slot();
    void VT23Slot();
    void V12Slot();
    void V13Slot();
    void V23Slot();

    void ps12Slot();
    void ps22Slot();
    void ps32Slot();


signals:

    void VT12Signal(int);
    void VT23Signal(int);
    void V12Signal(int);
    void V13Signal(int);
    void V23Signal(int);
    void ps12Signal(int);
    void ps22Signal(int);
    void ps32Signal(int);

private:
    QPushButton *VT12button;
    QPushButton *VT23button;
        QPushButton *P12button;
        QPushButton *P22button;
        QPushButton *P32button;
        QPushButton *V12button;
        QPushButton *V13button;
        QPushButton *V23button;

};

#endif // TABLEAUBORDPILOTE_H
