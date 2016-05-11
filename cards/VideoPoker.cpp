#include "VideoPoker.h"



VideoPoker::VideoPoker()
{
	loadPayouts();
}


VideoPoker::~VideoPoker()
{
}

void VideoPoker::play()
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

void VideoPoker::payTable() const
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

void VideoPoker::welcome() const
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
	while (hand.sizeofHand() != 5)
		hand.addCard(deck.draw());

	
	drawNewCards(hand);


		for (int i = 0; i != choices.size(); i++)
		{
			if (choices[i] != 0)
				hand.redraw(choices[i], deck.draw());
		}

	std::cout << hand << std::endl;

	hand.checkHand();

	outcome(hand);










}

void VideoPoker::loadPayouts()
{

	std::pair<std::string, int> pair("pair", 1);
	std::pair<std::string, int> TwoPair("Two Pair", 2);
	std::pair<std::string, int> threeoak("Three of a kind", 3);
	std::pair<std::string, int> Straight("Straight", 4);
	std::pair<std::string, int> Flush("Flush", 6);
	std::pair<std::string, int> FullHouse("Full House", 9);
	std::pair<std::string, int> fouroak("Four of a kind", 25);
	std::pair<std::string, int> StraightFlush("Straight Flush", 50);
	std::pair<std::string, int> RoyalFlush("Royal Flush", 250);

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
	int choice = 1;

	while (choice != 0)
	{
		std::cout << hand << std::endl;
		std::cout << "chose the card you would like to redraw (0 to continue): ";
		std::cin >> choice;

		if (choice < 0 || choice > hand.sizeofHand())
		{
			std::cout << "enter a valid card choice" << std::endl;
			system("pause");
		}
		else if (choice != 0)
		{
			
			hand.toggleDraw(choice);

		}


		choices.push_back(choice);
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

			std::cout << h.first << "! You won " << p->second << " credits!" << std::endl;
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
