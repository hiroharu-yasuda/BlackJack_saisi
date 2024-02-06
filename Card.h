#pragma once

#include <iostream>
#include "Card.h"

using namespace std;

enum mark {    
   Spade = 0,
   Club,
   Heart,
   Diamond,
   NoMark,
};

class Card final 
{
private:
    int _seqNo = 0;
    int _mark = 0; 
    int _num = 0;  

public:
    Card(int suit, int num);
    Card(int seq);
    Card();

    void show() const { std::cout << toString(); }

    std::string toString() const;

    int getNum() const { return _num; }

    int getSuit() const { return _mark; }

    void setCard(int seq);

};