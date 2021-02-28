#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include "player.h"

const int decksize = 52;
const double shufflepercent = 0.3;

class card
{
public:
	std::string getcardtype(int randomno);
	void shuffle();
	int getrandomcard();
	double bet();
	bool play(player playername);
	void printwinner(int winnercard);
	void printlooser(int randcard);
	void checkdeck();
	void initializedeck();
	void endgametotal(std::string playername);
	void testvector();
private:
	std::vector<int> vectordeck = std::vector<int>(decksize);
	int wins = 0;
	int losses = 0;	
	double totalmoneylost = 0;
	double totalmoneywon = 0;
};
