#include "card.h"
#include "player.h"

std::string card::getcardtype(int randomno)
{
	switch (randomno) {
	case 0:
		return "ace of diamonds";
	case 1:
		return "ace of spades";
	case 2:
		return "ace of hearts";
	case 3:
		return "ace of cloves";
	case 4:
		return "two of diamonds";
	case 5:
		return "two of spades";
	case 6:
		return "two of hearts";
	case 7:
		return "two of cloves";
	case 8:
		return "three of diamonds";
	case 9:
		return "three of spades";
	case 10:
		return "three of hearts";
	case 11:
		return "three of cloves";
	case 12:
		return "four of diamonds";
	case 13:
		return "four of spades";
	case 14:
		return "four of hearts";
	case 15:
		return "four of cloves";
	case 16:
		return "five of diamonds";
	case 17:
		return "five of spades";
	case 18:
		return "five of hearts";
	case 19:
		return "five of cloves";
	case 20:
		return "six of diamonds";
	case 21:
		return "six of spades";
	case 22:
		return "six of hearts";
	case 23:
		return "six of cloves";
	case 24:
		return "seven of diamonds";
	case 25:
		return "seven of spades";
	case 26:
		return "seven of hearts";
	case 27:
		return "seven of cloves";
	case 28:
		return "eight of diamonds";
	case 29:
		return "eight of spades";
	case 30:
		return "eight of hearts";
	case 31:
		return "eight of cloves";
	case 32:
		return "nine of diamonds";
	case 33:
		return "nine of spades";
	case 34:
		return "nine of hearts";
	case 35:
		return "nine of cloves";
	case 36:
		return "ten of diamonds";
	case 37:
		return "ten of spades";
	case 38:
		return "ten of hearts";
	case 39:
		return "ten of cloves";
	case 40:
		return "jack of diamonds";
	case 41:
		return "jack of spades";
	case 42:
		return "jack of hearts";
	case 43:
		return "jack of cloves";
	case 44:
		return "queen of diamonds";
	case 45:
		return "queen of spades";
	case 46:
		return "queen of hearts";
	case 47:
		return "queen of cloves";
	case 48:
		return "king of diamonds";
	case 49:
		return "king of spades";
	case 50:
		return "king of hearts";
	case 51:
		return "king of cloves";
	default:
		return "none";
	}
}

void card::shuffle() {
	srand( (unsigned int)time(NULL) );
}

int card::getrandomcard()
{
	int newcard;
	checkdeck();
	while (true)
	{
		newcard = rand() % vectordeck.size();
		if (vectordeck[newcard] == 1)
		{
			continue;
		}
		vectordeck[newcard] = 1;
		break;
	}

	return newcard;
}

double card::bet()
{
	double betprice;
	std::cout << "how much money do you want to bet?:  ";
	std::cin >> betprice;
	return betprice;
}

bool card::play(player info)
{
	char yesorno;
	bool haventbet = true;
	int playerguess;
	double betamount = 0;
	int cardno;
	std::cout << "lets play " << info.firstname << "\n";
	std::cout << "we will pick a card for you. do you want to guess the card ? " << "(y / n) : ";
	std::cin >> yesorno;
	
	if (yesorno == 'y' || yesorno == 'Y') {
		initializedeck();
		shuffle();
		while (true)
		{
			if (haventbet)
			{
				betamount = bet();
				if (betamount < 1)
				{
					std::cout << "invalid amount give us more money\n";
					continue;
				}
				haventbet = false;
				cardno = -1;
			}
			if (cardno == -1)
			{
				cardno = getrandomcard();
				//testvector();
			}
			std::cout << "please type in a card number from 0 to 51 or 99 to exit: ";
			std::cin >> playerguess;
			if (playerguess == 99)
			{
				std::cout << "thanks for playing\n";
				exit(0);
			}
			if (playerguess < 0 || playerguess > 51)
			{
				std::cout << "invalid number please try again\n";
				continue;
			}
			if (playerguess == cardno) {

				printwinner(playerguess);
				wins++;
				totalmoneywon = totalmoneywon + betamount;
			}
			else
			{
				printlooser(cardno);
				losses++;
				totalmoneylost = totalmoneylost + betamount;
			}
			haventbet = true;
			std::cout << "would you like to play again? (y/n): ";
			std::cin >> yesorno;
			if (yesorno == 'n' || yesorno == 'N')
			{
				break;
			}
		}
	} else {
		std::cout << "thanks for coming see you next time\n";
		return true;
	}
	endgametotal(info.firstname);
	return false;
}

void card::printwinner(int winnercard)
{
	std::cout << "you win\n";
	std::cout << "the type of card for that number is " << getcardtype(winnercard) << "\n";
}

void card::printlooser(int randcard)
{
	std::cout << "you loose\n";
	std::cout << "the right card number was " << randcard << "\n";
	std::cout << "the type of card for that number is " << getcardtype(randcard) << "\n";
}

void card::checkdeck()
{
	int notdealtcheck = 0;
	unsigned int i;
	for (i = 0; i < vectordeck.size(); i++) {
		if (vectordeck[i] == 0)
		{
			notdealtcheck++;
		} 	
	} 
	if (notdealtcheck <= shufflepercent * vectordeck.size())
	{
		shuffle();
		initializedeck(); 
		std::cout << "we have reshuffled the deck." << "\n";
	}
}


void card::initializedeck()
{
	unsigned int i;
	for (i = 0; i < vectordeck.size(); i++) 
	{
		vectordeck[i] = 0;
	}
}

void card::endgametotal(std::string playername)
{
	std::cout << "thanks for playing " << playername << "\n";
	std::cout << "you have played " << wins + losses << " times\n";
	std::cout << "your total bets were $" << totalmoneywon + totalmoneylost << "\n";
	std::cout << "you have won " << wins << " times and gained " << "$" << totalmoneywon << "\n";
	std::cout << "you have lost " << losses << " times and $" << totalmoneylost << "\n";
}

void card::testvector()
{
	for (unsigned int i = 0; i < vectordeck.size(); i++)
	{
		std::cout << i << ". " << vectordeck[i] << "\n";
	}
}


	
