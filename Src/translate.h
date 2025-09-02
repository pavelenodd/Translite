#pragma once
#include <algorithm>
#include <string>
#include <string_view>

#include "data.h"

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

  void Transliterate() {
    // подсчёт веса сложных русских букв
    auto count_rus_letters = [this](const std::string& text) -> int {
      int count = text.size();
      for (const auto& pair : data_.rus_letter_weight) {
        const std::string& c = pair.first;
        int weight = pair.second;
        size_t pos = 0;
        while ((pos = text.find(c, pos)) != std::string::npos) {
          count += (weight - 1);  // -1 потому что буква уже учтена в размере строки
          pos += c.size();
        }
      }
      return count;
    };

    auto transliterate = [this](std::string_view view_text) -> std::string {
      std::string result;
      for (size_t i = 0; i < view_text.size();) {
        bool found = false;
        for (const auto& [key, value] : data_.transliteration_map) {
          if (i + key.size() <= view_text.size() && view_text.substr(i, key.size()) == key) {
            result += value;
            i += key.size();
            found = true;
            break;
          }
        }
        if (!found) {
          result += view_text[i];
          ++i;
        }
      }
      return result;
    };

    int rus_count = count_rus_letters(query_text);
    result_text.reserve(rus_count * 2);  // Резервируем память под результат

    result_text = transliterate(query_text);
  }
};
