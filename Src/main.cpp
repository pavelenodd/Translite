#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include "translate.h"

int main(int argc, char *argv[]) {

QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;

Translate translator;

std::cerr << "Query text example: \"Щучий хвост\" ";
translator.GetQueryText("Щучий хвост");
translator.Transliterate(true);

std::cerr << "Translated text: " << translator.GetResultText() << std::endl;

std::cerr << "Query text example: \"shchuchiy khvost\" ";
translator.GetQueryText("shchuchiy khvost");
translator.Transliterate(false);
std::cerr << "Translated text: " << translator.GetResultText() << std::endl;
// engine.loadFromModule(u"MinimalQml", u"Main");

return app.exec();
}