#include <iostream>
#include <time.h>
#include "card.h"
#include <vector>
#include "player.h"

void greeting(player info) 
{
    std::cout << "hello, " << info.firstname << " Welcome to Andy and Chris's card game!\n"; 
}



int main()
{
    card c;
    player p;
    player player_info = p.getplayerinfo(); 
    greeting(player_info);
    c.play(player_info);
} 
