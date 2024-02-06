#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <iomanip>
#include <windows.h>

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

enum PERSON
{
	DEALER,
	Player1,
	Player2,
	Player3
};

static void showPersonsHand(Person** persons, int num)
{
	cout << std::left;
	for (int i = 0; i < num; i++)
	{
		cout << setw(15) << "==============";
		cout << " ";
	}
	cout << endl;

	cout << "Players" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << setw(15) << persons[i]->getName();
		cout << " ";
	}
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		char buf[32] = { 0 };
		cout << setw(15) << persons[i]->createCardString(buf);
		cout << " ";
	}
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		char buf[32] = "score:";
		sprintf(buf, "score:%d", persons[i]->getScore());
		cout << setw(15) << buf;
		cout << " ";
	}
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		cout << std::left << setw(15) << "==============";
		cout << " ";
	}
	cout << endl;
}

static void showResult(Person** p, int num)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;

	p[DEALER]->show();
	showPersonsHand(p + 1, num - 1);

	for (int i = 1; i < num; i++)
	{
		cout << p[i]->getName();
		if (p[i]->getScore() > p[DEALER]->getScore()) {
			cout << " Win!" << endl;
		}
		else if (p[i]->getScore() < p[DEALER]->getScore()) {
			cout << " Lose" << endl;
		}
		else {
			cout << " Push" << endl;
		}
	}
}

static void Game()
{
	Shoe shoe;

	Person* persons[] = { 
		new Dealer(),
		new Player("konbu"), new Player("tunamayo"),
		new Player("takana"), new Player("ume"),
		new Player("menntaiko")
	};
	const int num = sizeof(persons) / sizeof(Person*);

	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(&shoe);
	}
	for (int i = 1; i < num; i++)
	{
		persons[i]->hit(&shoe);
	}

	persons[DEALER]->show();
	persons[DEALER]->hit(&shoe);

	showPersonsHand(&persons[1], num - 1);


	
	for (int i = 1; i < num; i++)
	{
		if (!persons[i]->play(&shoe)) {
			cout << "Burst " << persons[i]->getName() << endl;
		}
	}


	persons[DEALER]->play(&shoe);

	showResult(persons, num);

	for (int i = 0; i < num; i++)
	{
		if (persons[i] != NULL) {
			delete persons[i];
		}
	}

}

int main() {

	srand((unsigned int)time(NULL));

	Game();

	return 0;
}