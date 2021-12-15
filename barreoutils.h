#ifndef Boutil_H
#define Boutil_H
#include <iostream>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include <QVBoxLayout>

#include <QWidgetAction>


class Boutil : public QToolBar
{
    friend class pageprincipale;
    friend class ClassePrincipale;

public:
    Boutil();
    ~Boutil();
    void reset();

private:

    QPushButton *actionidf;

    QPushButton *log_out;

    QPushButton *start;
    QPushButton *restart;
    QPushButton *home;

    bool pause;

    QComboBox *menureservoire;
    QPushButton *buttonconfig;

    QPushButton *actionpanneprimaire;
    QPushButton *actionpannesecours;
    QPushButton *actionviderRes;

    QPushButton*choix;
};

#endif // Boutil_H
