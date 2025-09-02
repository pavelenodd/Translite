#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "translate.h"

int main(int argc, char *argv[]) {

QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;

Translate translator;
engine.loadFromModule(u"Transliterator", u"Main");

return app.exec();
}