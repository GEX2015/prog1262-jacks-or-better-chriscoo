//
//  Created by Chris Arsenault on 2016-05-13.
//  Copyright © 2016 Chris Arsenault. All rights reserved.
//

#include "VideoPoker.h"



VideoPoker::VideoPoker()
{
	loadPayouts();
}

VideoPoker::~VideoPoker()
{
}

void VideoPoker::play() //game loop
{

	int choice;
	bool leave = false;
	while (leave != true)
	{
		welcome();

		std::cout << "*************************************\n" <<
			"**        1) view pay table        **\n" <<
			"**        2) Play the game         **\n" <<
			"**        3) Quit                  **\n" <<
			"*************************************\n" << std::endl;


		std::cout << "credis: " << credits << std::endl;

		std::cin >> choice;

		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> choice;
		}
		std::cin.ignore();
		switch (choice) {
		case 1:
			payTable();
			break;
		case 2:
			game();
			break;

		case 3:
			leave = true;
			break;
		default:
			break;
		};
		system("cls");
	}
	system("cls");
}

void VideoPoker::payTable() const //shows the payout table
{

	system("cls");
	std::cout << "******************************************\n" <<
		"**       hand        |      credits     **\n" <<
		"**______________________________________**\n" <<
		"** Royal Flush       |        250       **\n" <<
		"**______________________________________**\n" <<
		"** Straight flush    |         50       **\n" <<
		"**______________________________________**\n" <<
		"** Four of a kind    |         25       **\n" <<
		"**______________________________________**\n" <<
		"** Full House        |          9       **\n" <<
		"**______________________________________**\n" <<
		"** Flush             |          6       **\n" <<
		"**______________________________________**\n" <<
		"** Straight          |          4       **\n" <<
		"**______________________________________**\n" <<
		"** Three of a kind   |          3       **\n" <<
		"**______________________________________**\n" <<
		"** Two pair          |          2       **\n" <<
		"**______________________________________**\n" <<
		"** Jacks of better   |          1       **\n" <<
		"**______________________________________**\n" <<
		"** Theoretical Return|         98.4%    **\n" <<
		"**                                      **\n" <<
		"******************************************" << std::endl;
	system("pause");

}

void VideoPoker::welcome() const //instructions/welcome message
{
	std::cout << "*******************************************\n" <<
		"**      Welcome to Jacks or better!      **\n" <<
		"*******************************************" << std::endl << std::endl;

	std::cout << "how to play: " << std::endl;
	std::cout << "you goal is to get atleast one of the follow combinations in your hand: of a pair of jacks, which pays even money." << std::endl <<
		"All the other hand combinations in video poker are the same as in table poker, including such hands as two pair," << std::endl <<
		"three of a kind, straight(a sequence of 5 cards of same suits), flush(any 5 cards of the same suit)," << std::endl <<
		"full house(a pair and a three of a kind), four of a kind(four cards of the same value)," << std::endl <<
		"straight flush(5 consecutive cards of the same suit) and royal flush(a Ten, a Jack, a Queen, a King and an Ace of the same suit)." << std::endl;


}

void VideoPoker::game()
{

	system("cls");

	Deck deck;
	Hand hand;

	deck.shuffle();
	while (hand.sizeofHand() != 5) //makes the hand
		hand.addCard(deck.draw());

	
	drawNewCards(hand); //chose cards to hold or draw loop


		for (int i = 0; i != choices.size(); i++)
		{
			if (choices[i] != 0)
				hand.redraw(choices[i], deck.draw()); //draws all the chards the player chose
		}

	std::cout << hand << std::endl;

	hand.checkHand(); //checks to see if the player won anything

	outcome(hand); //pays out the money if they did win










}

void VideoPoker::loadPayouts() //prepares our payout map for later comparison in outcome
{

	std::pair<payOuts, int> pair(payOuts::PAIR, 1);
	std::pair<payOuts, int> TwoPair(payOuts::TWOPAIR, 2);
	std::pair<payOuts, int> threeoak(payOuts::THREEOAKIND, 3);
	std::pair<payOuts, int> Straight(payOuts::STRAIGHT, 4);
	std::pair<payOuts, int> Flush(payOuts::FLUSH, 6);
	std::pair<payOuts, int> FullHouse(payOuts::FULLHOUSE, 9);
	std::pair<payOuts, int> fouroak(payOuts::FOUROFAKIND, 25);
	std::pair<payOuts, int> StraightFlush(payOuts::STRAIGHTFLUSH, 50);
	std::pair<payOuts, int> RoyalFlush(payOuts::ROYALFLUSH, 250);

	_payout.insert(pair);
	_payout.insert(TwoPair);
	_payout.insert(threeoak);
	_payout.insert(Straight);
	_payout.insert(Flush);
	_payout.insert(FullHouse);
	_payout.insert(fouroak);
	_payout.insert(StraightFlush);
	_payout.insert(RoyalFlush);

}

void VideoPoker::drawNewCards(Hand hand)
{
	int choice = 1; //dummy value to get into the loop

	while (choice != 0)
	{
		std::cout << hand << std::endl;
		std::cout << "chose the card you would like to redraw (0 to continue): ";
		std::cin >> choice;


		
		if (choice < 0 || choice > hand.sizeofHand() || std::cin.fail()) //if its above or below the max number of cards in hand or if they don't input a number
		{
			std::cout << "enter a valid card choice" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			system("pause");
		}
		else if (choice != 0)
		{
			
			hand.toggleDraw(choice);

			int count = std::count(choices.begin(), choices.end(), choice); // checks to see if it's being toggled back off 

			if (count > 0) //if it being toggled back to hold
			{
				for (int i = 0; i < choices.size(); i++)
				{
					if (choices[i] == choice)
						choices.erase(choices.begin() + i);
				}
			}
			else	//of it's not
			choices.push_back(choice);
		}


		
		system("cls");
	}

	system("cls");
}

void VideoPoker::outcome(Hand hand)
{
	auto end = hand._payoutHands.end();
	end--;//gets the one before end
	for (auto h : hand._payoutHands) //checks if there was a pay out of not in any of the pairs in the map
	{
		auto p = _payout.begin();

		if (h.second == true)
		{
			while (p->first != h.first) //matches the pay with the right outcome
				p++;
			switch ((int)h.first)
			{
			case 0:
				std::cout << "pair! You won " << p->second << " credits!" << std::endl;
				break;
			case 1:
				std::cout << "Two Pair! You won " << p->second << " credits!" << std::endl;
				break;
			case 2:
				std::cout << "Three of a kind! You won " << p->second << " credits!" << std::endl;
				break;
			case 3:
				std::cout << "Straight! You won " << p->second << " credits!" << std::endl;
				break;
			case 4:
				std::cout << "Flush! You won " << p->second << " credits!" << std::endl;
				break;
			case 5:
				std::cout << "Full house! You won " << p->second << " credits!" << std::endl;
				break;
			case 6:
				std::cout << "Four of a kind! You won " << p->second << " credits!" << std::endl;
				break;
			case 7:
				std::cout << "Straigh flush! You won " << p->second << " credits!" << std::endl;
				break;
			case 8:
				std::cout << "ROYAL FLUSH! You won " << p->second << " credits!" << std::endl;
				break;
			}
			//std::cout << h.first << "! You won " << p->second << " credits!" << std::endl;
			credits = credits + p->second;
			system("pause");
			break;
		}
		else if (h.first == end->first) //to check if there isnt any matches
		{
			std::cout << "you lost!" << std::endl;
			system("pause");
		}


	}
}
