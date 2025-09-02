#include "translate.h"

#include <string_view>

Translate::Translate(QObject* parent) : QObject(parent) {}

Translate::~Translate() {}

void Translate::Transliterate(Language lang) {
  auto transliterate = [this, lang](std::string_view view_text) -> std::string {
    std::string result;
    for (size_t i = 0; i < view_text.size();) {
      bool found = false;
      switch (lang) {
        case Language::TRANSLIT: {
          for (const auto& [key, value] : data_.transliteration_map) {
            if (i + key.size() <= view_text.size() && view_text.substr(i, key.size()) == key) {
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
            if (i + key.size() <= view_text.size() && view_text.substr(i, key.size()) == key) {
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
            if (i + key.size() <= view_text.size() && view_text.substr(i, key.size()) == key) {
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
