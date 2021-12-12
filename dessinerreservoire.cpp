#include "dessinerreservoire.h"

reservoiredessin::reservoiredessin(const qreal& x, const qreal& y, QBrush color, const qreal &hauteur):
    graphegenerale(), _dp(x, y), _carbColor(color)
{
    _hauteur = hauteur;

    _bcirculer = false;
    bPrimMarche = true;
    bSecMarche = false;
    bPrimPanne = false;
    bSecPanne = false;

}

QPointF reservoiredessin::pointDeConnexion()
{
    return QPointF(_dp.x()+15.5, _dp.y()-(_hauteur+20));
}






QRectF reservoiredessin::boundingRect() const
{
    return QRectF(_dp.x(), _dp.y(), 15, 15);
}

void reservoiredessin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qreal x = _dp.x();
    qreal y = _dp.y();

    qreal sx = x+25;

    qreal rx = x+17.5;
    qreal ry = y-13;


    QRectF primRect = boundingRect();
    QRectF secRect = QRectF(sx, y, 15, 15);



    QRectF inRect1 = QRectF(x+5, y+5, 5, 5);
    QRectF inRect2 = QRectF(x+30, y+5, 5, 5);





    QRectF ralRect = QRectF(rx-1, ry-_hauteur, 7, _hauteur);


    QPolygonF polygonePrim, polygoneSec;

    polygonePrim << QPoint(x+5, y)  << QPoint(x+5, ry) << QPoint(rx, ry)
                 << QPoint(rx, ry+5) << QPoint(x+10, ry+5) << QPoint(x+10, y);

    polygoneSec << QPoint(rx+5, ry)  << QPoint(sx+10, ry) << QPoint(sx+10, y)
                 << QPoint(sx+5, y) << QPoint(sx+5, y-5) << QPoint(rx+5, ry+5);




    painter->drawText(x+1, y+28, "P1");
    painter->drawText(x+29, y+28, "P2");

    QPainterPath pathPrim, pathSec;
    pathPrim.addPolygon(polygonePrim);
    pathSec.addPolygon(polygoneSec);

    painter->drawPolygon(polygonePrim);
    painter->drawPolygon(polygoneSec);

    if (bPrimMarche && _bcirculer)
    {
        painter->fillPath(pathPrim, _carbColor);
    }

    else
    {
        painter->fillPath(pathPrim, brushDefault);
    }

    if (bSecMarche && _bcirculer)
    {
        painter->fillPath(pathSec, _carbColor);
    }

    else
    {
        painter->fillPath(pathSec, brushDefault);
    }


    painter->fillRect(primRect, brushDefault);
    painter->fillRect(secRect, brushDefault);


    // points de connexions

    if ((bPrimMarche || bSecMarche) && _bcirculer)
        painter->fillRect(ralRect, _carbColor);

    else
        painter->fillRect(ralRect, brushDefault);

    painter->drawRect(ralRect);







    // coloriage des cercles avec ou sans panne

    if (bPrimPanne)
    {
        painter->setBrush(Qt::red);
        painter->drawEllipse(primRect);
        painter->setBrush(brushDefault);
        painter->drawEllipse(inRect1);
    }

    else
    {
        painter->setBrush(brushDefault);
        painter->drawEllipse(primRect);
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(inRect1);
    }

    if (bSecPanne)
    {
        painter->setBrush(Qt::red);
        painter->drawEllipse(secRect);
        painter->setBrush(brushDefault);
        painter->drawEllipse(inRect2);
    }

    else
    {
        painter->setBrush(brushDefault);
        painter->drawEllipse(secRect);
        painter->setBrush(Qt::blue);
        painter->drawEllipse(inRect2);
    }


}





void reservoiredessin::setpmarche(bool value)
{
    bPrimMarche = value;
}

void reservoiredessin::setsmarche(bool value)
{
    bSecMarche = value;
}


void reservoiredessin::setppanne(bool value)
{

    if (value)
        setpmarche(false);

    bPrimPanne = value;
}


void reservoiredessin::setspanne(bool value)
{
    if (value)
        setsmarche(false);

    bSecPanne = value;
}

bool reservoiredessin::bcirculer()
{
    return _bcirculer;
}

void reservoiredessin::setBcirculer(bool bcirculer)
{
    _bcirculer = bcirculer;
}

QBrush reservoiredessin::carbColor()
{
    return _carbColor;
}

void reservoiredessin::setCarbColor(const QBrush &carbColor)
{
    _carbColor = carbColor;
}





reservoiredessin::~reservoiredessin()
{

}


