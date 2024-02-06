#pragma once

#include "Person.h"

class Dealer : public Person 
{
public:

	Dealer(const char* const name);
	Dealer();
	void playBase(Shoe* shoe) override;

};