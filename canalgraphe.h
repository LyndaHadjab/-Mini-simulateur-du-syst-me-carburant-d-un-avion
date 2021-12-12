#ifndef CANALGRAPHE_H
#define CANALGRAPHE_H
#include <QPolygonF>
#include <QPainter>
#include "Graphegenerale.h"

class canaldessin : public graphegenerale
{
public:
    canaldessin(const QPolygonF& polygone);

    ~canaldessin();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void changecolor(const QBrush& color);


    bool getcircule() const;

    void setcircule(bool value);

private:
    QPolygonF _polygone;
    QBrush _carbColor;
    bool circule;
};
#endif // CANALGRAPHE_H
