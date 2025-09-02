#pragma once

#include <QObject>
#include <QString>
#include <string>

#include "data.h"

enum class Language {
  TRANSLIT,    // Транслитерация в оба языка
  TO_RUSSIAN,  // Транслитерация с английского на русский
  TO_ENGLISH   // Транслитерация с русского на английский
};

class Translate : public QObject {
  Q_OBJECT

 private:
  std::string query_text_;   // input text
  std::string result_text_;  // output text(translated text)
  Data data_;               // storage for transliteration map

 public:
  explicit Translate(QObject* parent = nullptr);
  ~Translate();

  Q_INVOKABLE void SetQueryText(const QString& text) {
    query_text_ = text.toStdString();
  }

  Q_INVOKABLE QString GetResultText() const {
    return QString::fromStdString(result_text_);
  }
 public slots:
  void Transliterate(Language lang = Language::TRANSLIT);
};
