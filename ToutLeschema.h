#ifndef TOUTLEmonschema_H
#define TOUTLEmonschema_H
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QAction>
#include <QProgressBar>
#include <QLabel>

#include <QPainter>
#include <QPolygonF>
#include <QRectF>
#include <QGraphicsTextItem>
#include <QVector>

#include "dessinmoteur.h"
#include "dessinvanne.h"
#include "dessinerreservoire.h"
#include "canalgraphe.h"
#include "Graphegenerale.h"
#include "graphereservoiremoteur.h"

using namespace std;

class monschema : public QGraphicsView
{
    friend class ClassePrincipale;




public:
    monschema();

    moteurgraphe* getMoteur(int i);

    vannedessin* getVanne(int i);

    reservoiredessin *getReservoir(int i);

    canaldessin *getCanal(int i);

    ~monschema();

private:
    QGraphicsScene _monschema;
    QList <graphegenerale*> outils;
    QBrush _brush;

};
#endif // TOUTLEmonschema_H
