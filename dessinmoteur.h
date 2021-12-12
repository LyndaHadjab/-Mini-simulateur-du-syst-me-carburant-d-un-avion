#ifndef DESSINMOTEUR_H
#define DESSINMOTEUR_H
#include "Graphegenerale.h"
class moteurgraphe : public graphegenerale
{
public:
    moteurgraphe(QString nom, qreal x, qreal y);
     ~moteurgraphe();
    QPointF centre() ;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



private:
    QPointF _dp;
    QString _nom;

};

#endif // DESSINMOTEUR_H
