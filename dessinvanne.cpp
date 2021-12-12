#include "dessinvanne.h"

vannedessin::vannedessin(QString nom, qreal x, qreal y, int brush) : graphegenerale(), _dp(x, y), _canalObserver()
{
    ouvert = true;
    _bcirculer = false;

    this->nom = nom;

    _canalObserver.reserve(2);

    // Couleur par défaut

    if (brush == 0)
        _carbColor = brushDefault;

    else
        _carbColor = QBrush(QColor(181, 123, 183));
}

bool vannedessin::estouvert()
{
    return ouvert;
}

void vannedessin::setOpen(bool op)
{
    ouvert = op;
}

// Si le carburant ne circule pas, on remet la valeur par défaut

void vannedessin::setBcirculer(bool bcirculer)
{
    _bcirculer = bcirculer;
    QBrush br;

    if (!_bcirculer)
        br = brushDefault;

    else
        br = _carbColor;

    for (int i = 0; i < _canalObserver.size(); i++)
    {
        _canalObserver[i]->setcircule(_bcirculer);
        _canalObserver[i]->changecolor(br);
    }
}






// Renvoie le point centre de la vanne

QPointF vannedessin::centre()
{
    return QPointF(_dp.x()+10, _dp.y()+10);
}

//
QBrush vannedessin::carbColor()
{
    return _carbColor;
}

void vannedessin::setCarbColor(const QBrush &carbColor)
{
    _carbColor = carbColor;

    for (int i = 0; i < _canalObserver.size(); i++)
    {
        _canalObserver[i]->changecolor(_carbColor);
    }
}

bool vannedessin::bcirculer()
{
    return _bcirculer;
}






void vannedessin::addObserver(canaldessin *canal)
{
    _canalObserver.push_back(canal);
}



// Fonctions de paint

QRectF vannedessin::boundingRect() const//pour dessiner un cercle
{
    return QRectF(_dp.x(), _dp.y(), 20, 20);
}
//procedure permet de dessiner la vanne dans deux cas :
//le cas ou la vanne est fermer et le cas ou la vanne est ouvert
void vannedessin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qreal x = _dp.x();
    qreal y = _dp.y();

    QRectF rect = boundingRect();
    QRectF opcRect;

    QPen extPen(Qt::red, 1.6, Qt::SolidLine);
    QBrush brush;

//deux lignes qui vont etre aparraitre lors que la vanne sera fermer
    QLine extLine1(x, y+6, x+20, y+6);
    QLine extLine2(x, y+13.5, x+20, y+13.5);

    if (!ouvert)
    {
        QRectF r(x-1, y+6.5, 25, 9);
        opcRect = r;

        if (_bcirculer)
            brush = _carbColor;

        else
            brush = brushDefault;
    }

    else
    {
        //si la vanne est ouvert on le dessine vert ||
        QRectF r(x+7.5, y, 5, 20);
        opcRect = r;
        brush = QBrush(Qt::green);
    }

    painter->fillRect(rect, brushDefault);



    painter->drawEllipse(rect);

    painter->fillRect(opcRect, brush);

    painter->drawText(x+0.5, y-3, this->nom);    // nom de la vanne le mettre a une position

    if (!ouvert)
    {
        painter->setPen(extPen);
        painter->drawLine(extLine1);
        painter->drawLine(extLine2);
    }

}



// Destructeur

vannedessin::~vannedessin()
{

}
