#include "Hand.h"
#include <algorithm>


Hand::Hand()
{
	std::pair<std::string, bool> pair("pair", false);
	std::pair<std::string, bool> TwoPair("Two Pair", false);
	std::pair<std::string, bool> threeoak("Three of a kind", false);
	std::pair<std::string, bool> Straight("Straight", false);
	std::pair<std::string, bool> Flush("Flush", false);
	std::pair<std::string, bool> FullHouse("Full House", false);
	std::pair<std::string, bool> fouroak("Four of a kind", false);
	std::pair<std::string, bool> StraightFlush("Straight Flush", false);
	std::pair<std::string, bool> RoyalFlush("Royal Flush", false);

	_payoutHands.insert(pair);
	_payoutHands.insert(TwoPair);
	_payoutHands.insert(threeoak);
	_payoutHands.insert(Straight);
	_payoutHands.insert(Flush);
	_payoutHands.insert(FullHouse);
	_payoutHands.insert(fouroak);
	_payoutHands.insert(StraightFlush);
	_payoutHands.insert(RoyalFlush);

}


Hand::~Hand()
{
}

void Hand::addCard(Cardptr c)
{
	_hand.push_back(c);
	std::pair<Cardptr, bool>newCard(c, false);
	_draw.push_back(false);
}

void Hand::clear()
{
	while (sizeofHand() != 0)
		_hand.pop_back();

	_Redraw.clear();
}

void Hand::removeCard(int c)
{
	_hand.erase(_hand.begin() + (c - 1));
	int j = 0;
	auto tmp = _Redraw.begin();
	while (j != (c - 1))
		tmp++;

	_Redraw.erase(tmp);
}



void Hand::redraw(int i, Cardptr c)
{
	_hand[i-1] = c;
}

void Hand::checkHand()
{

	if (findRoyalFlush())
		_payoutHands["Royal Flush"] = true;
	else if (findStraightFlush())
		_payoutHands["Straight Flush"] = true;
	else if (findFourOfAKind())
		_payoutHands["Four of a kind"] = true;
	else if (findFullHouse())
		_payoutHands["Full House"] = true;
	else if (findFlush())
		_payoutHands["Flush"] = true;
	else if (findStraight())
		_payoutHands["Straight"] = true;
	else if (findThreeOfAKind())
		_payoutHands["Three of a kind"] = true;
	else if (findTwoPair())
		_payoutHands["Two Pair"] = true;
	else if (findPair())
		_payoutHands["pair"] = true;

}

bool Hand::findPair()
{
	std::map<Face, int>map;

	for (int i = 0; i != _hand.size(); i++)
		map[_hand[i]->face]++;

	int pairCount = count_if(map.begin(), map.end(), [](std::pair<Face, int> e) {return(e.second == 2); });

	if (pairCount == 1)
	{
		return true;
	}
	else
		return false;
}

bool Hand::findThreeOfAKind()
{
	std::map<Face, int>map;

	for (int i = 0; i != _hand.size(); i++)
		map[_hand[i]->face]++;

	int pairCount = count_if(map.begin(), map.end(), [](std::pair<Face, int> e) {return(e.second == 3); });

	if (pairCount == 1)
	{
		//std::cout << "three of a kind found" << std::endl;
		return true;
	}
	else
		return false;
}

bool Hand::findFourOfAKind()
{
	std::map<Face, int>map;

	for (int i = 0; i != _hand.size(); i++)
		map[_hand[i]->face]++;

	int pairCount = count_if(map.begin(), map.end(), [](std::pair<Face, int> e) {return(e.second == 4); });

	if (pairCount == 1)
	{
		//std::cout << "four of a kind found" << std::endl;
		return true;
	}
	else
		return false;
}

bool Hand::findFullHouse()
{
	if (findPair() == true && findThreeOfAKind() == true)
		return true;
	else
		return false;
}

bool Hand::findTwoPair()
{
	std::map<Face, int>map;

	for (int i = 0; i != _hand.size(); i++)
		map[_hand[i]->face]++;

	int pairCount = count_if(map.begin(), map.end(), [](std::pair<Face, int> e) {return(e.second == 2); });

	if (pairCount == 2)
	{

		return true;
	}
	else
		return false;
}

bool Hand::findFlush()
{
	std::set<Suit> hand;
	for (int i = 0; i != _hand.size(); i++)
		hand.insert(_hand[i]->suit);

	if (hand.size() == 1)
		return true;
	else
		return false;
}

bool Hand::findStraight()
{

	std::set<int> hand;



	for (int i = 0; i != _hand.size(); i++)
	{

		hand.insert((int)_hand[i]->face);
	}

	auto start = hand.begin();
	auto last = hand.end();
	last--;
	if (hand.size() == 5) {
		if (*start == *last - (hand.size() - 1))
		{
			return true;
		}
		else if (*start == 0)
		{
			hand.insert(13);
			start++;
			last = hand.end();
			last--;
			if (*start == *last - (_hand.size() - 1))
			{
				return true;
			}
		}
		else
			return false;
	}
	return false;
}

bool Hand::findStraightFlush()
{
	if (findStraight() == true && findFlush() == true)
		return true;
	else
		return false;
}

bool Hand::findRoyalFlush()
{

	std::set<int> hand;



	for (int i = 0; i != _hand.size(); i++)
	{

		hand.insert((int)_hand[i]->face);
	}

	auto start = hand.begin();
	auto last = hand.end();
	last--;
	if (hand.size() == 5) {
		if (*start == 0)
		{
			hand.insert(13);
			start++;
			last = hand.end();
			last--;

			if (*start == *last - (_hand.size() - 1) && findFlush() == true)
			{
				return true;
			}
		}
		else
			return false;
	}
	return false;

}

bool Hand::isDraw(int idx)
{
	if (_draw[idx] == true)
		return true;
	else
		return false;
}

void Hand::toggleDraw(int idx)
{
	_draw[idx-1] = !_draw[idx-1];
}



