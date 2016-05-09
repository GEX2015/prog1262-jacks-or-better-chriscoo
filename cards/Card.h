
#pragma once
#include<string>
#include <map>
#include <iostream>
#include <set>
enum class Suit { CLUB, DIAMOND, HEART, SPADE };
enum class Face { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };



struct Card
{
	Card() : face(Face::ACE), suit(Suit::CLUB) {}
	Card(Face f, Suit s) : face(f), suit(s) {}
	Suit suit;
	Face face;
	static const std::set<Suit> suits;
	static const std::set<Face> faces;

	static const std::map<Face, std::string> faceNames;
	static const std::map<Suit, std::string> SuitNames;
	Card& operator=(const Card& rhs)
	{
		
			Card tmp(Face::ACE, Suit::CLUB);
			tmp.face = rhs.face;
			tmp.suit = rhs.suit;
			
			return tmp;
	}
	inline friend std::ostream& operator<<(std::ostream& os, const Card& c)
	{
		std::cout << faceNames.at(c.face) + " of " + Card::SuitNames.at(c.suit);
		return os;
	}

	

	friend bool operator==(const Card& l, const Card&r)
	{
		if (l.face == r.face)
			return true;
		else
			return false;
	};

	std::string toString() const;
};

bool operator<(const Card& l, const Card& r);

