#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>

#include "Card.h"
#include "Shoe.h"

using namespace std;

void Shoe::shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;

		Card tmp = _cardShoe[a];
		_cardShoe[a] = _cardShoe[b];
		_cardShoe[b] = tmp;
	}
}

Shoe::Shoe() {

	_initCardShoe();
}
Shoe::~Shoe()
{
}

void Shoe::_initCardShoe()
{
	_cardNum = CARD_NUM; 
	for (int i = 0; i < _cardNum; i++)
	{
		_cardShoe[i].setCard(i);
	}

	shuffle();
}
void Shoe::show(SHOW_TYPE type) const
{
	int roopCnt = CARD_NUM;
	if (type == CARD_ONLY) {
		roopCnt = _cardNum;
	}

	for (int i = 0; i < roopCnt; i++) {
		cout << _cardShoe[i].toString() << endl;
	}
	cout << endl;
}

Card Shoe::takeCard() {
	_cardNum--;

	Card card = _cardShoe[_cardNum];
	if (_cardNum <= 0) {
		_initCardShoe();
	}
	return card;
}