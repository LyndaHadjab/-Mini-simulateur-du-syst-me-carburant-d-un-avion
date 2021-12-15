#ifndef LOGINREGISTER_H
#define LOGINREGISTER_H
#include <iostream>

using namespace std;

#include <QLabel>
#include <QAction>
#include <QPushButton>
#include <QComboBox>
#include <QPalette>
#include <QGroupBox>
#include <QToolBar>
#include <QVBoxLayout>
#include <QLineEdit>

class Loginregister : public QWidget
{
    Q_OBJECT

    friend class connectregister ;//pour que la classe coectregister peut acceder au champs privé de cette classe

public:
    Loginregister(bool cnx);
    ~Loginregister();
    void connexion();
    void inscrire();

private:
    QLineEdit *identifiant;
    QLineEdit *motdepasse;

    QPushButton *buttonconnexion;
    QPushButton *buttoninscription;
    QAction *creerCompte;

    QAction *connecter;
    QLabel  *header;

    QLabel *identilabel;
    QLabel *passwordlabel;
    QLabel *incorrectidf;

};
#endif // LOGINREGISTER_H