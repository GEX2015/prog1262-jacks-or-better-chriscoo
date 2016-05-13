//
//  Created by Chris Arsenault on 2016-05-13.
//  Copyright © 2016 Chris Arsenault. All rights reserved.
//

#pragma once
#include <unordered_map>
#include "Hand.h"
class VideoPoker
{
public:
	VideoPoker();
	~VideoPoker();

	

	void play();
	
	

private:
	
	void payTable() const;
	void welcome() const;
	void game();
	void loadPayouts();
	void drawNewCards(Hand hand);
	void outcome(Hand hand);
	int credits = 0;
	std::unordered_map<payOuts, int> _payout;
	std::vector<int>choices;
	
};

