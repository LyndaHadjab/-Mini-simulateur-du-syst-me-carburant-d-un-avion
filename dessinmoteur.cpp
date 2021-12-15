#include "dessinmoteur.h"

moteurgraphe::moteurgraphe(QString nom, qreal x, qreal y) : graphegenerale(), _dp(x, y), _nom(nom)
{

}

QPointF moteurgraphe::centre()
{
    return QPointF(_dp.x()+20, _dp.y()+24);
}

QRectF moteurgraphe::boundingRect() const
{
    return QRectF(_dp.x(), _dp.y(), 100, 100);
}

void moteurgraphe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF  polygone2;

    polygone2 << QPointF(_dp.x()-15, _dp.y()+28) << QPointF(_dp.x()+55, _dp.y()+28) <<
                 QPointF(_dp.x()+55, _dp.y()+58.5) << QPointF(_dp.x()-15, _dp.y()+58.5);

    painter->drawText(_dp.x()+14, _dp.y()+11, _nom);

    QPainterPath path;
    path.addPolygon(polygone2);

    painter->fillPath(path, brushDefault);
    painter->drawPolygon(polygone2);

}

moteurgraphe::~moteurgraphe()
{

}

