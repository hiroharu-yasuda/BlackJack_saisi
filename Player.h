#pragma once

#include "Person.h"

class Player : public Person
{
public:
	Player(const char* const name);

protected:
	virtual void playBase(Shoe* const shoe);
};
