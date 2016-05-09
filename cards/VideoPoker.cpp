#include "VideoPoker.h"
#include "Hand.h"


VideoPoker::VideoPoker()
{
}


VideoPoker::~VideoPoker()
{
}

void VideoPoker::play()
{
	Deck deck;
	Hand hand;
	
	int choice;
	bool leave = false;
	std::cout << "*************************************\n" <<
				 "**        1) view pay table        **\n" <<
				 "**        2) Play the game         **\n" <<
				 "**        3) Quit		             **\n" <<
				 "*************************************\n" << std::endl;
	while (leave != true)
	{
		std::cin >> choice;

		switch (choice) {
		case 1:
			payTable();
			break;
		case 2:
			
			deck.shuffle();
		case 3:
			leave = true;
			break
		default
			break;
		};
	}
	for (int i = 0; i != 5; i++)
		hand.addCard(deck.draw());



	system("pause");
	system("cls");
}

void VideoPoker::payTable()
{


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

		 
}

void VideoPoker::welcome()
{
	std::cout << "*******************************************\n" <<
				 "**      Welcome to Jacks or better!      **\n" <<
				 "*******************************************" <<std::endl << std::endl;

	std::cout << "how to play: " << std::endl;
	std::cout << "you goal is to get atleast one of the follow combinations in your hand: of a pair of jacks, which pays even money." << std::endl <<
		"All the other hand combinations in video poker are the same as in table poker, including such hands as two pair," << std::endl <<
		"three of a kind, straight(a sequence of 5 cards of same suits), flush(any 5 cards of the same suit)," << std::endl <<
		"full house(a pair and a three of a kind), four of a kind(four cards of the same value)," << std::endl <<
		"straight flush(5 consecutive cards of the same suit) and royal flush(a Ten, a Jack, a Queen, a King and an Ace of the same suit)." << std::endl;


}
