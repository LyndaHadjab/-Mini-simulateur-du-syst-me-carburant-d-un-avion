#ifndef GRAPHEGENERALE_H
#define GRAPHEGENERALE_H
#include <iostream>
#include <QGraphicsItem>
#include <QPainter>

class graphegenerale: public QGraphicsItem
{

public:

    QBrush brushDefault;

public:

    graphegenerale();
    virtual ~graphegenerale();
};

#endif // GRAPHEGENERALE_H
