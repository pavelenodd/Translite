#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qdebug.h"
#include "qlogging.h"
#include "translate.h"

int main(int argc, char *argv[]) {

QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;

Translate translator;
qDebug() <<"Query text example: щучий хвост";
translator.GetQueryText("щучий хвост");
translator.Transliterate();
QString result = QString::fromStdString(translator.GetResultText());
qDebug() << "Translated text:" << result;


// engine.loadFromModule(u"MinimalQml", u"Main");





return app.exec();
}