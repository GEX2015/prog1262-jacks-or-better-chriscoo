#pragma once
#include <unordered_map>
#include "Hand.h"
class VideoPoker
{
public:
	VideoPoker();
	~VideoPoker();

	void play();
	void payTable() const;
	void welcome() const;
	void game();
	void loadPayouts();
	void drawNewCards(Hand hand);
	void outcome(Hand hand);


	
	int credits=0;

private:
	std::unordered_map<std::string, int> _payout;
	std::vector<int>choices;
	
};

