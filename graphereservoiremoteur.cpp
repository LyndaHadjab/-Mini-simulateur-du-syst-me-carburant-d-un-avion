#include "graphereservoiremoteur.h"

grapherm::grapherm(const qreal& x, const qreal& y): graphegenerale(), _pointDepart(x, y),Mres1("--"), Mres2("--"),
    Mres3("--")
{

    //represente les bares qui indique la quantite du carburant dans chaque réservoire
    res1progbar = new QProgressBar;
    res1progbar->setOrientation(Qt::Horizontal);
    res1progbar->setTextVisible(false);
    res1progbar->setValue(0);

    res2progbar = new QProgressBar;
    res2progbar->setOrientation(Qt::Horizontal);
    res2progbar->setTextVisible(false);
    res2progbar->setValue(0);

    res3progbar = new QProgressBar;
    res3progbar->setOrientation(Qt::Horizontal);
    res3progbar->setTextVisible(false);
    res3progbar->setValue(0);

    res1progbar->setFixedSize(70, 13);
    res2progbar->setFixedSize(70, 13);
    res3progbar->setFixedSize(70, 13);


}


// Updates

void grapherm::updateBarValues(int val1, int val2, int val3)
{
    res1progbar->setValue(val1);
    res2progbar->setValue(val2);
    res3progbar->setValue(val3);
}



void grapherm::updateResMoteur(const QString& s1, const QString& s2, const QString& s3)
{
    Mres1 = s1;
    Mres2 = s2;
    Mres3 = s3;
}



// Drawing
QRectF grapherm::boundingRect() const
{
    return QRectF(_pointDepart.x()-90, _pointDepart.y(), 100, 180);
}

void grapherm::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qreal x = _pointDepart.x();
    qreal y = _pointDepart.y();

    qreal z = x+400;


    QRectF rectValues =QRectF(_pointDepart.x()-90, _pointDepart.y(), 100, 180);


    painter->setBrush(brushDefault);
  painter->drawText(QRectF(z+50, y-15, 100, 13), "Etat moteurs", QTextOption(Qt::AlignCenter));
   //la position du texte Carburant Quantité

    painter->drawRoundedRect(rectValues, 5, 4);//cadre autour du texte
      painter->fillRect(QRectF(x-90, y-9, 100, 13), brushDefault);

     painter->drawText(QRectF(x-90, y-9, 100, 13), "Carburant Quantité", QTextOption(Qt::AlignCenter));

    painter->drawText(QRectF(x-90, y+10, 71, 12), "TANK1", QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(x-90, y+60, 71, 12), "TANK2", QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(x-90, y+110, 71, 12), "TANK3", QTextOption(Qt::AlignCenter));

    // Conversion des progressar en pixmap

    QPixmap pixmap = res1progbar->grab();
    painter->drawPixmap(x-85, y+23, 60, 13, pixmap);

    pixmap = res2progbar->grab();
    painter->drawPixmap(x-85, y+75, 60, 13, pixmap);

    pixmap = res3progbar->grab();
    painter->drawPixmap(x-85, y+128, 60, 13, pixmap);

    painter->drawText(QRectF(z+10, y+10, 71, 12), "MOTEUR1", QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(z+83.5, y+10, 71, 12), "MOTEUR2", QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(z+157, y+10, 71, 12), "MOTEUR3", QTextOption(Qt::AlignCenter));

    painter->drawText(QRectF(z+10, y+27, 71, 12), Mres1, QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(z+83.5, y+27, 71, 12), Mres2, QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(z+157, y+27, 71, 12), Mres3, QTextOption(Qt::AlignCenter));



}


grapherm::~grapherm()
{
    delete res1progbar;
    delete res2progbar;
    delete res3progbar;
}

