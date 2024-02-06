
#include "Player.h"
#include "Shoe.h"

using namespace std;

Player::Player(const char* const name) : Person(name)
{

}

void Player::playBase(Shoe* shoe) {
	while (getScore()) {
		cout << getName() << "... hit or stand? >> ";

		
		char str[16]; 
		cin >> str; 
		if (strcmp(str, "hit") == 0) {
			hit(shoe);

			show();
		}
		else if (strcmp(str, "stand") == 0) {
			break;
		}
	}
}
