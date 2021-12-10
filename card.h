#pragma once
#include <string>
using namespace std;


class Card{
    public:
  string suit;
  int value;
  Card(string s, int v){
      suit = s;
      value =v;
  }

};
