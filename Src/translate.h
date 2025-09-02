#pragma once
#include <string>

#include "data.h"

class Translate {
 private:
  std::string query_text;   // input text
  std::string result_text;  // output text(translated text)
  Data data;                // storage for transliteration map

 public:
  void GetQueryText(const std::string& text) {
    query_text = text;
  }

  std::string GetResultText() const {
    return result_text;
  }

  void Transliterate() {
    std::string L_text = query_text;  // Копируем входной текст в результат

    auto replace_rus_letters = [this](std::string& text) -> int {
      int count = 0;
      size_t i = 0;
      while (i < text.size()) {
        bool found = false;
        for (auto& [c, weight] : data.rus_letter_weight) {
          if (i + c.size() <= text.size() && text.substr(i, c.size()) == c) {
            text.replace(i, c.size(), "");  // Заменяем букву на ""
            count += weight;
            found = true;
            break;
          }
        }
        if (!found) {
          i++;
        }
      }
      return count;
    };

    auto transliterate = [this](char c) -> std::string {};

    int rus_count = replace_rus_letters(L_text);
result_text.reserve(rus_count * 2); // Резервируем память под результат

  }
};