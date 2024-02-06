#pragma once

#include "common.h"

#include "Card.h"

class Shoe final {

private:
	Card _cardShoe[CARD_NUM];
	int _cardNum;
	void _initCardShoe();

	void shuffle();
public:
	enum SHOW_TYPE
	{
		CARD_ONLY,
		ALL
	};

	Shoe();
	virtual ~Shoe();

	Card takeCard();

	void show(SHOW_TYPE type = CARD_ONLY) const;
};

