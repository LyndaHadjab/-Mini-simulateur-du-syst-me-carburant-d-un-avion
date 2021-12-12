#include "ToutLeschema.h"

monschema::monschema() : _monschema(), outils(), _brush(QColor(220, 220, 220))
{

    outils.reserve(21);

    setScene(&_monschema);//permet d'afficher le schema

    QPolygonF  polygoneCoque;

 //le schema (polygone qui entroure les reservoire/

       polygoneCoque << QPointF(-320, 70) << QPointF(-30, 70) << QPointF(30, 70) << QPointF(320, 70)

                       << QPointF(320, -85) << QPointF(70, -85) << QPointF(-70, -85) << QPointF(-320, -85);


        qreal x = -5;
        qreal y = -5;

        for (int i = 0; i < 3; i++)
        {
            //pour fermer le tuyeux qui relie les reservoire
            if (i == 1)
            {
                x = -280;
                y = 10;
            }

            else if (i == 2)
                x = 260;

    }

  //positionnement des texts des differents reservoire

        QGraphicsTextItem *text1 = _monschema.addText("TANK1", QFont("Arial Black", 8));

        QGraphicsTextItem *text2 = _monschema.addText("TANK2", QFont("Arial Black", 8));

        QGraphicsTextItem *text3 = _monschema.addText("TANK3", QFont("Arial Black", 8));

        text1->setPos(-140, -110);

        text2->setPos(15, -110);

        text3->setPos(110, -110);

        text1->setDefaultTextColor(QColor(0, 66, 50));

        text2->setDefaultTextColor(QColor(93, 20, 193));

        text3->setDefaultTextColor(QColor(93, 66, 77));


        _monschema.addPolygon(polygoneCoque,QPen (QBrush(QColor(93, 66, 77)), 5, Qt::SolidLine));

            //ligne qui separe les reservoire(verticalement)
        _monschema.addLine(QLineF (-71, 71, -70, -270) ,QPen (QBrush(QColor(93, 66, 77)), 5, Qt::SolidLine));
        _monschema.addLine(QLineF (70, 71, 70, -270), QPen (QBrush(QColor(93, 66, 77)), 5, Qt::SolidLine));


        QPolygonF polygoneVT1, polygoneVT2, polygoneVT3, polygoneRM1, polygoneRM2, polygoneRM3;

        QPolygonF polygoneV12, polygoneV13, polygoneV23;

       moteurgraphe *m1=new moteurgraphe("M1", -300, -260);

       moteurgraphe *m2=new moteurgraphe("M2", -20, -300);
        moteurgraphe *m3=new moteurgraphe("M3", 280, -260);

        outils.push_back(m1);//creer une instance du graphe du moteur //0

        outils.push_back(m2);//1

        outils.push_back(m3);//2

    vannedessin *vt12=    new vannedessin("VT12", -100, -32, 1);

    vannedessin *vt23=new vannedessin("VT23", 100, -32, 2);

        outils.push_back(vt12);//3

        outils.push_back(vt23);//4

        vannedessin *v12=new vannedessin("V12", -60, -175);

        vannedessin *v13=   new vannedessin("V13", 80, -135);

      vannedessin *v23=  new vannedessin("V23", 40, -175);

        outils.push_back(v12);//5

        outils.push_back(v13);//6

        outils.push_back(v23);//7

        // initialisation des pompes
    reservoiredessin *r1=new reservoiredessin(-205, -70, QBrush(QColor(237, 201, 56)));

 reservoiredessin *r2=new reservoiredessin(-20, -80, QBrush(QColor(237, 201, 56)), 68);


 reservoiredessin *r3=new reservoiredessin(165, -70, QBrush(QColor(237, 201, 56)));


        outils.push_back(r1);//8

        outils.push_back(r2);//9

        outils.push_back(r3);     //10





        // polygones vannes

        x = -280;
        qreal cx = ((vannedessin *)outils[3])->centre().x();
        y = -10;
        qreal cy = ((vannedessin *)outils[3])->centre().y();

       //ligne qui relie vanne avec le petit cree a la fin d'un reseroire

  polygoneVT1 << QPointF(-269.5, -10) << QPointF(-269.5, -25) << QPointF(cx-18, cy-7.5) << QPointF(cx, cy-7.5)

       << QPointF(cx, cy+7.5) << QPointF(cx-28, cy+7.5) << QPointF(-266.5, -17) << QPointF(-266.5, -10);

            canaldessin *c1=new canaldessin (polygoneVT1);

        outils.push_back(c1);

        x = 10;
        cx = ((vannedessin *)outils[4])->centre().x();

        qreal cxx = ((vannedessin *)outils[3])->centre().x();

        y = -5;
        cy = ((vannedessin *)outils[4])->centre().y();

        qreal cyy = ((vannedessin *)outils[3])->centre().y();

        polygoneVT2 << QPointF(x+20.5, y) << QPointF(x+20.5, cy+8.5) << QPointF(cx, cy+8.5) << QPointF(cx, cy-8.5)
                    << QPointF(cxx, cyy-7.5) << QPointF(cxx, cyy+9.5) << QPointF(x+7.5, cyy+9.5) << QPointF(x+7.5, y);

       canaldessin *c2=new canaldessin (polygoneVT2);
        outils.push_back(c2);

        x = 260;     cx = ((vannedessin *)outils[4])->centre().x();
        y = -10;      cy = ((vannedessin *)outils[4])->centre().y();

        polygoneVT3 << QPointF(x+13.5, y) << QPointF(x+13.5, y-15) << QPointF(cx+18, cy-7.5) << QPointF(cx, cy-7.5)
                    << QPointF(cx, cy+7.5) << QPointF(cx+18, cy+7.5) << QPointF(x+7.5, y-7) << QPointF(x+7.5, y);

          canaldessin *c3=new canaldessin (polygoneVT3);
        outils.push_back(c3);    //13


        // polygones canaux reservoirs - moteurs reliés aux pompes

        cx = ((vannedessin *)outils[5])->centre().x();

        cy = ((vannedessin *)outils[5])->centre().y();

        x = ((vannedessin *)outils[6])->centre().x();

        y = ((vannedessin *)outils[6])->centre().y();

        qreal dx = ((reservoiredessin *)outils[8])->pointDeConnexion().x();

        qreal dy = ((reservoiredessin *)outils[8])->pointDeConnexion().y();

        qreal mx = ((moteurgraphe *)outils[0])->centre().x();

        qreal my = ((moteurgraphe *)outils[0])->centre().y();

        polygoneRM1 << QPointF(dx, dy+9) << QPointF(mx-5.5, dy+9) << QPointF(mx-7.5, my)
                    << QPointF(mx+7.5, my) << QPointF(mx+7.5, y-9.5) << QPointF(-70, cy-5.5) << QPointF(cx, cy-7.5)
                    << QPointF(cx, cy+9.5) << QPointF(-50, cy+7.5) << QPointF(mx+7.5, y-3.5)
                    << QPointF(mx+9.5, dy) << QPointF(dx+20, dy);

      canaldessin  *rm1=  new canaldessin(polygoneRM1);
        outils.push_back(rm1);    //14

        // Les cannaux reliant les moteurs aux pompes

        dx = ((reservoiredessin *)outils[9])->pointDeConnexion().x();
        dy = ((reservoiredessin *)outils[9])->pointDeConnexion().y();
        mx = ((moteurgraphe *)outils[1])->centre().x();
        my = ((moteurgraphe *)outils[1])->centre().y();

        polygoneRM2 << QPointF(mx-5.5, dy) << QPointF(mx-5.5, my) << QPointF(mx+5.5, my) << QPointF(mx+5.5, dy);
canaldessin  *rm2=  new canaldessin(polygoneRM2);
        outils.push_back(rm2);    //15

                // ajouts du canal traversant la vanne V12

                polygoneV12 << QPointF(cx, cy-5.5) << QPointF(cx, cy+5.5) << QPointF(dx, dy+9) << QPointF(dx, dy);
                canaldessin  *V12=  new canaldessin(polygoneV12);
                outils.push_back(V12);    //16

        // **********

        cx = ((vannedessin *)outils[6])->centre().x();
        cy = ((vannedessin *)outils[6])->centre().y();
        x = ((vannedessin *)outils[7])->centre().x();
        y = ((vannedessin *)outils[7])->centre().y();

                polygoneV23 << QPointF(x, y-5.5) << QPointF(x, y+5.5) << QPointF(dx+11, dy+9) << QPointF(dx+11, dy);
           canaldessin*V23       =  new canaldessin(polygoneV23);

                outils.push_back(V23);    //17

        dx = ((reservoiredessin *)outils[10])->pointDeConnexion().x();
        dy = ((reservoiredessin *)outils[10])->pointDeConnexion().y();
        mx = ((moteurgraphe *)outils[2])->centre().x();
        my = ((moteurgraphe *)outils[2])->centre().y();

        //canal de reservoire 3
        polygoneRM3 << QPointF(dx+11, dy) << QPointF(mx-5.5, dy)
                    << QPointF(mx-7.5, cy+5.5) << QPointF(70, y+5.5) << QPointF(x, y+5.5) << QPointF(x, y-7.5)
                    << QPointF(70, y-5.5) << QPointF(mx-5.5, cy-5.5) << QPointF(mx-3, my) << QPointF(mx+7.5, my)
                    << QPointF(mx+5.5, dy+7) << QPointF(dx, dy+7);

  canaldessin*RM3    =   new canaldessin(polygoneRM3);
        outils.push_back(RM3);    //18

                // Ajout du canal de la vanne 13

                x = ((reservoiredessin *)outils[8])->pointDeConnexion().x();
                y = ((reservoiredessin *)outils[8])->pointDeConnexion().y();
                dx = ((reservoiredessin *)outils[10])->pointDeConnexion().x();
                dy =((reservoiredessin *) outils[10])->pointDeConnexion().y();

                polygoneV13 << QPointF(x+11, y+7) << QPointF(x+11, y) << QPointF(x+19, y) << QPointF(-70, cy-5.5)
                            << QPointF (70, cy-5.5) << QPointF (dx-10, dy) << QPointF (dx, dy) << QPointF (dx, dy+7)
                            << QPointF (dx-10, dy+7) << QPointF (70, cy+3.5) << QPointF(-70, cy+3.5)
                            << QPointF(x+19, dy+7);

         canaldessin*V13      = new canaldessin(polygoneV13);
                outils.push_back(V13);    //19


        // Ajouts des tableaux des états du système
                grapherm *grm=new grapherm(-350,-320);
        outils.push_back(grm);    //20

        //affichage du schéma des moteurs des vannes et ceux des pompes
        for (int i = outils.size()-1; i >=0; i--)
        {


            if (i >= 11 && i <= 13)
                outils[i]->setZValue(2);

            else
                outils[i]->setZValue(3);

            _monschema.addItem(outils[i]);
        }




       ((vannedessin*)outils[3])->addObserver((canaldessin*)outils[11]);  //VT12

        ((vannedessin*)outils[3])->addObserver((canaldessin*)outils[12]);  //VT12

        ((vannedessin*)outils[4])->addObserver((canaldessin*)outils[12]);  //VT23
        ((vannedessin*)outils[4])->addObserver((canaldessin*)outils[13]);  //VT23

        ((vannedessin*)outils[5])->addObserver((canaldessin*)outils[16]);  //V12
        ((vannedessin*)outils[6])->addObserver((canaldessin*)outils[19]);  //V13
        ((vannedessin*)outils[7])->addObserver((canaldessin*)outils[17]);  //V23



    // couleur de fond

    setBackgroundBrush(_brush);

    // Antialliage
    setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
}





//moteur de 0 a 2:3moteur

moteurgraphe *monschema::getMoteur(int i)
{
    if (i >= 0 && i <= 2)
        return (moteurgraphe*)outils[i];
}

vannedessin *monschema::getVanne(int i)
{
    if (i >= 3 && i <= 7)
        return (vannedessin*)outils[i];
}

reservoiredessin *monschema::getReservoir(int i)
{
    if (i >= 8 && i <= 10)
        return (reservoiredessin*)outils[i];
}

canaldessin *monschema::getCanal(int i)
{
    if (i >= 11 && i <= 19)
        return (canaldessin*)outils[i];
}

// Destructeur

monschema::~monschema()
{


    for (int i = outils.size()-1; i >= 0; i--)
    {
        delete outils[i];
    }


}

