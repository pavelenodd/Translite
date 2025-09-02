#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>  

#include "translate.h"

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  Translate translator;
  engine.rootContext()->setContextProperty("translator", &translator);
  engine.loadFromModule(u"Transliterator", u"Main");

  return app.exec();
}