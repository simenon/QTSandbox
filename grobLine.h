#include <QGraphicsLineItem>
#include <QLineF>
#include <QTimer>

class GrobLine : public QObject, public QGraphicsLineItem
{
  Q_OBJECT

  private:
    QLineF lineF; 
    QColor currentColor;
    QColor ColorOn;
    QColor ColorOff;
    QTimer* timer;

  public:
    GrobLine(QLineF l);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  public slots:
    void changeColor();
};
