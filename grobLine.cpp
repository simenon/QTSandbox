#include <QPen>
#include <QPainter>
#include <QLineF>
#include "grobLine.h"
#include <QTimer>
#include <QBrush>

GrobLine::GrobLine(QLineF l)
{
  this->lineF = l;
  this->currentColor = this->ColorOff;
  this->ColorOn = Qt::yellow;
  this->ColorOff = Qt::black;

  timer = new QTimer();
  QObject::connect(timer, SIGNAL(timeout()), this, SLOT(changeColor()));
  timer->start(1000);
}

QRectF GrobLine::boundingRect() const
{
  return QRectF(this->lineF.p1(),this->lineF.p2());
}

void GrobLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen( QPen( QBrush(this->currentColor,Qt::SolidPattern), 6, Qt::SolidLine ) );
  painter->drawLine( this->lineF );
}

void GrobLine::changeColor()
{
  if (this->currentColor == this->ColorOn)
    this->currentColor = this->ColorOff;
  else
    this->currentColor = this->ColorOn;
  update(this->boundingRect());
}

