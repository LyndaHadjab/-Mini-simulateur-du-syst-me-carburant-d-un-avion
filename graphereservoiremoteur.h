#ifndef GRAPHERESERVOIREMOTEUR_H
#define GRAPHERESERVOIREMOTEUR_H
#include "Graphegenerale.h"
#include<iostream>
using namespace std;
#include<string.h>
#include <QProgressBar>

class grapherm : public graphegenerale
{
    friend class SystemeCarburant;

public:
    grapherm(const qreal& x, const qreal& y);

    ~grapherm();

    void updateBarValues(int val1, int val2, int val3);

    void updateResMoteur(const QString& s1, const QString& s2, const QString& s3);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    QPointF _pointDepart;
    QProgressBar *res1progbar;
    QProgressBar *res2progbar;
    QProgressBar *res3progbar;
    QString Mres1;
    QString Mres2;
    QString Mres3;
};
#endif // GRAPHERESERVOIREMOTEUR_H
