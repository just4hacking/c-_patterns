#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace flyweight_custom {

using namespace std;

//insufficient way, lets try to play with ranges
class FormattedText {
private:
  string plain_text;
  bool* caps;

public:
  FormattedText(const string& plain_text) :
    plain_text(plain_text) {
      //insufficient way
    caps = new bool[plain_text.length()];
    memset(caps, 0, plain_text.length());
  }

  ~FormattedText() {
    delete caps;
  }

  void capitalize(int start, int end) {
    for (int i = start; i < end; i++) {
      caps[i] = true;
    }
  }

  friend ostream& operator<<(ostream& os, const FormattedText& text) {
    string s;
    for (int i = 0; i < text.plain_text.length(); i++) {
      char c = text.plain_text[i];
      s += (text.caps[i]? std::toupper(c) : c);
    }
    return os << s;
  }
};

class BetterFormattedText {
public:
  struct TextRange {
    int start, end;
    bool capitalize; //bold, italic ...
    bool covers(int position) const {
      return position >= start && position <= end;
    }
  };

  TextRange& get_range(int start, int end) {
    formatting.emplace_back(TextRange{start, end});
    return *formatting.rbegin();
  }

  BetterFormattedText(const string& plain_text) :
    plain_text(plain_text) {

  }

  friend ostream& operator<<(ostream& os, const BetterFormattedText& text) {
    string s;
    for (int i = 0; i < text.plain_text.length(); i++) {
      auto c = text.plain_text[i];
      for (const auto& rng : text.formatting) {
        if (rng.covers(i) && rng.capitalize) {
          c = toupper(c);
        }

        s += c;
      }
    }
    return os << s;
  }

private:
  string plain_text;
  vector<TextRange> formatting;
};
  
}

/*
EXAMPLE


int main(int argc, char *argv[])
{
  flyweight_custom::FormattedText ft{"This is a brave new world!"};
  ft.capitalize(10, 15);
  cout << ft << endl;

  flyweight_custom::BetterFormattedText bft{"This is a brave new world!"};
  bft.get_range(10, 15).capitalize = true;
  cout << bft << endl;
}

*/