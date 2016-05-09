#include "Deck.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

Deck::Deck()
{
	srand(static_cast<unsigned int>(time(0)));
	for (auto f : Card::suits)
		for (auto s : Card::faces)
			_deck.push_back(std::make_shared<Card>(Card(s, f)));

	_topOfDeck = _deck.size() - 1;
}


Deck::~Deck()
{
}



const bool Deck::isEmpty()
{
	if (_topOfDeck < 0)
		return true;
	else
		return false;
}

Cardptr Deck::draw()
{
	//
	return _deck.at(_topOfDeck--);
}

void Deck::shuffle()
{
	for (int i = 0; i < _deck.size(); ++i)
	{
		swap(_deck[i], _deck[i + (rand() % (_deck.size() - i))]);
	}
	_topOfDeck = _deck.size() - 1;
}
