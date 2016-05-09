#pragma once
#include "Deck.h"

struct Card;
using Cardptr = std::shared_ptr<Card>;
class Hand
{
public:
	Hand();
	~Hand();
	int sizeofHand() const { return _hand.size(); }
	friend std::ostream& operator<<(std::ostream& os, const Hand& h)
	{
		for (int i = 0; i != h.sizeofHand(); i++)
		{
			std::cout << *h._hand[i] << std::endl;
		}
		return os;
	}
	void addCard(Cardptr c);
	void clear();
	void removeCard(int c);

	bool findPair();
	bool findThreeOfAKind();
	bool findFourOfAKind();
	bool findFullHouse();
	bool findTwoPair();
	bool findFlush();
	bool findStraight();
	bool findStraightFlush();
	bool findRoyalFlush();
private:
	std::vector<Cardptr> _hand;
	
};

