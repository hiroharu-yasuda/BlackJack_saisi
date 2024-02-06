#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

#include "Person.h"
#include "Shoe.h"
#include "Card.h"

using namespace std;

Person::Person(const char* const name)
{
	if (_pName != NULL)
	{
		delete[] _pName;
		_pName = NULL;
	}
	_pName = new char[strlen(name) + 1];
	strcpy(_pName, name);
}

void Person::_copy(const Person& other)
{
	copy(std::begin(other._hand), std::end(other._hand), std::begin(_hand));

	_cardNum = other._cardNum;
	_calcUpdate = other._calcUpdate;
	_score = other._score;

	_pName = new char[strlen(other._pName) + 1];
	strcpy(_pName, other._pName);
}

Person::Person(const Person& other)
{
	_copy(other);
}

// デストラクタ
Person::~Person()
{
	if (_pName != NULL)
	{
		delete _pName;
		_pName = NULL;
	}
}

void Person::operator=(const Person& other)
{
	_copy(other);
}

int Person::getScore()
{
	if (_calcUpdate == true)
	{
		int* data = NULL;

		data = new(nothrow) int[_cardNum]; 
		if (data == NULL)
		{
			cout << "メモリの確保に失敗:再起動してください。" << endl;
			return 0;
		}

		for (int i = 0; i < _cardNum; i++) {
			if (_hand[i].getNum() < 11) {
				*(data + i) = _hand[i].getNum();

			}
			else {
				*(data + i) = 10;
			}
		}

		sort(data, data + _cardNum);

		_score = 0;

		for (int i = 1; i < _cardNum; i++) {
			_score = _score + (*(data + i));
		}

		if (*data == 1) {
			if (_score + 11 < 22) { 
				_score += 11;
			}
			else {
				_score += 1;
			}
		}
		else {
			_score += data[0];
		}

		if (_score > 21) {
			_score = 0;
		}

		if (data != NULL)
		{
			delete[] data;
			data = NULL;
		}
	}

	return _score;
}

void Person::hit(Shoe* shoe) {
	Card card = shoe->takeCard();

	_hand[_cardNum] = card;
	_cardNum++;
	_calcUpdate = true;
}

char* Person::createCardString(char* const pStr) const
{
	if (pStr != NULL)
	{
		strcpy(pStr, "");

		for (int i = 0; i < _cardNum; i++) {
			strcat(pStr, _hand[i].toString().c_str());
			strcat(pStr, " ");

		}
		strcat(pStr, "\0");
	}
	return pStr;
}

void Person::show() {
	cout << "====================" << endl;
	cout << _pName << endl;
	cout << "hand: ";

	char buf[32];
	cout << createCardString(buf);

	cout << endl;
	cout << "score: " << getScore() << endl; 
	cout << "====================" << endl;

}

bool Person::play(Shoe* const shoe)
{
	playBase(shoe);

	if (getScore() <= 0) return false;
	return true;

}