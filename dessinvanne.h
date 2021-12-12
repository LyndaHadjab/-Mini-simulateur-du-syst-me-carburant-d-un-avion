#ifndef DESSINVANNE_H
#define DESSINVANNE_H
#include <QPainter>
#include <QRectF>
#include <QVector>

#include "Graphegenerale.h"
#include "canalgraphe.h"
#include<iostream>
using namespace  std;
class vannedessin : public graphegenerale
{
public:
    vannedessin(QString nom, qreal x, qreal y, int brush = 0);

    bool estouvert() ;

    void setOpen(bool op);

    QPointF centre() ;

    QBrush carbColor() ;

    void setCarbColor(const QBrush &carbColor);

    void addObserver(canaldessin *canal);

    QRectF boundingRect() const  ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    ~vannedessin();


    bool bcirculer();
    void setBcirculer(bool bcirculer);

private:
    QPointF _dp;
    bool ouvert;
    bool _bcirculer;
    QString nom;

    QBrush _carbColor;

    QVector <canaldessin*> _canalObserver;
};

#endif // DESSINVANNE_H
