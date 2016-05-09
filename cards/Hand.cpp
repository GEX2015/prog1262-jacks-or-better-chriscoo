#include "Hand.h"
#include <algorithm>


Hand::Hand()
{

}


Hand::~Hand()
{
}

void Hand::addCard(Cardptr c)
{
	_hand.push_back(c);
}

void Hand::clear()
{
	while (sizeofHand() != 0)
		_hand.pop_back();
}

void Hand::removeCard(int c)
{
	_hand.erase(_hand.begin() + c);
}

bool Hand::findPair()
{
	std::map<Face, int>map;

	for (int i = 0; i != _hand.size(); i++)
		map[_hand[i]->face]++;

	int pairCount = count_if(map.begin(), map.end(), [](std::pair<Face, int> e) {return(e.second == 2); });

	if (pairCount == 1)
	{
		//std::cout << "pair Found" << std::endl;
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

}



