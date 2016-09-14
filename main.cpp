#include <iostream> 
#include <QtGui/QApplication>
#include <QGraphicsScene> 
#include <QGraphicsView>
#include "grobLine.h" 

int main (int argc, char *argv[])
{
//  std::cout << " Hello World!" << std::endl;

  QApplication app(argc, argv);

  QGraphicsScene scene;

  GrobLine *gLine = new GrobLine(QLineF(QPointF(0,0),QPointF(20,20)));

  scene.addItem(gLine);
// scene.addText("Hello World!");
// scene.setBackgroundBrush(Qt::blue);

  QGraphicsView view(&scene);
  view.setRenderHints( QPainter::Antialiasing );
  view.show();


  return app.exec();
}
