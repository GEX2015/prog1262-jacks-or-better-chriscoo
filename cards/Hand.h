#pragma once
#include "Deck.h"
#include <unordered_map>

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
		int i = 1;
		int j = 0;
		while (j < h.sizeofHand())		{
			if (h._draw[j] == true)
				std::cout << i << ") " << *h._hand[j] << " (drawing)" << std::endl;
			else
				std::cout << i << ") " << *h._hand[j] << " (holding)" << std::endl;

			i++;
			j++;
			
		}

		return os;
	}
	void addCard(Cardptr c);
	void clear();
	void removeCard(int c);
	void redraw(int i, Cardptr c);

	void checkHand();

	bool findPair();
	bool findThreeOfAKind();
	bool findFourOfAKind();
	bool findFullHouse();
	bool findTwoPair();
	bool findFlush();
	bool findStraight();
	bool findStraightFlush();
	bool findRoyalFlush();
	std::unordered_map<std::string, int> _payoutHands;
	std::unordered_map<Cardptr, bool> _Redraw;
	bool isDraw(int idx); // do I draw card at idx
	void toggleDraw(int idx);  //fart
private:
	std::vector<Cardptr> _hand;
	std::vector<bool> _draw; // true if card is to be drawn
	
	
};

