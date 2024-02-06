#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;

#include "Shoe.h"

using namespace std;

Dealer::Dealer(const char* const name) : Person(name)
{

}


Dealer::Dealer() : Person("Dealer")
{

}

void Dealer::playBase(Shoe* shoe) {
	while (getScore() < 17 && getScore() > 0) {
		hit(shoe);
		cout << getName() << "... hit" << endl;
		show();
	}
}