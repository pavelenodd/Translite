#pragma once
#include <QDebug>
#include <algorithm>
#include <iostream>
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

  void Transliterate(bool is_russian = true) {
    // подсчёт веса сложных русских букв
    auto count_rus_letters = [this](std::string_view view_text) -> int {
      int count = view_text.size();
      for (const auto& [key, value] : data_.rus_letter_weight) {
        size_t pos = 0;
        while ((pos = view_text.find(key, pos)) != std::string::npos) {
          count += (value - 1);  // -1 потому что буква уже учтена в размере строки
          pos += key.size();
        }
      }
      return count;
    };
    auto count_eng_letters = [this](std::string text) -> int {
      int count = text.size();
      int i = 0;
      for (const auto& [key, value] : data_.eng_letter_weight) {
        ++i;
        size_t pos = 0;
        while ((pos = text.find(key, pos)) != std::string::npos) {
          count += (value + 1);  // -1 потому что буква уже учтена в размере строки
          text.replace(pos, key.size(), "");
          pos += key.size();
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

    int text_count = is_russian ? count_rus_letters(query_text)
                                : count_eng_letters(query_text);

    result_text = transliterate(query_text);
  }
};
