#pragma once

#include "common.h"

#include "Card.h"

class Shoe;


class Person
{
private:
	Card _hand[HAND_SIZE];
	bool _calcUpdate = false;
	int _cardNum = 0;
	int _score = 0;
	char* _pName = NULL;

	void _copy(const Person& other);

public:
	Person(const char* const name);
	virtual ~Person();

	Person(const Person& other);

	void operator=(const Person& p);

	int getScore();

	void hit(Shoe* const shoe);

	char* getName() const { return _pName; };

	char* createCardString(char* const pStr) const;

	void show();

	bool play(Shoe* const shoe);
protected:
	virtual void playBase(Shoe* const shoe) = 0;

};