#pragma once

#include <string>
#include <string_view>

#include "data.h"
enum class Language {
  TRANSLIT,    // Транслитерация в оба языка
  TO_RUSSIAN,  // Транслитерация с английского на русский
  TO_ENGLISH   // Транслитерация с русского на английский
};
class Translate {
 private:
  std::string query_text;   // input text
  std::string result_text;  // output text(translated text)
  Data data_;               // storage for transliteration map

 public:
  void GetQueryText(const std::string& text) {
    query_text = text;
  }

  std::string GetResultText() const {
    return result_text;
  }

  void Transliterate(Language lang = Language::TRANSLIT) {
    auto transliterate = [this, lang](std::string_view view_text) -> std::string {
      std::string result;
      for (size_t i = 0; i < view_text.size();) {
        bool found = false;
        switch (lang) {
          case Language::TRANSLIT: {
            for (const auto& [key, value] : data_.transliteration_map) {
              if (i + key.size() <= view_text.size() &&
                  view_text.substr(i, key.size()) == key) {
                result += value;
                i += key.size();
                found = true;
                break;
              }
            }
            break;
          }
          case Language::TO_RUSSIAN: {
            for (const auto& [key, value] : data_.eng_transliteration_map) {
              if (i + key.size() <= view_text.size() &&
                  view_text.substr(i, key.size()) == key) {
                result += value;
                i += key.size();
                found = true;
                break;
              }
            }
            break;
          }
          case Language::TO_ENGLISH: {
            for (const auto& [key, value] : data_.rus_transliteration_map) {
              if (i + key.size() <= view_text.size() &&
                  view_text.substr(i, key.size()) == key) {
                result += value;
                i += key.size();
                found = true;
                break;
              }
            }
            break;
          }
        };

        if (!found) {
          result += view_text[i];
          ++i;
        }
      }
      return result;
    };

    result_text = transliterate(query_text);
  }
};
