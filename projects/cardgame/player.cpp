#include "player.h"
#include <iostream>

 player player::getplayerinfo()
{
    player p;
    std::cout << "what is your first name?: ";
    std::cin >> p.firstname;
    std::cout << "what is your last name?: ";
    std::cin >> p.lastname;
    std::cout << "what is your id?: ";
    std::cin >> p.id;
    std::cout << "what is your birthday year?: ";
    std::cin >> p.bdyear;
    std::cout << "what is your birthday month?: ";
    std::cin >> p.bdmonth;
    std::cout << "what is your birthday day?: ";
    std::cin >> p.bdday;
    std::cout << "what is your house number? ";
    std::cin >> p.housenumber;
    std::cout << "what is your street name?: ";
    std::cin >> p.streetname;
    std::cout << "what is your city name?: ";
    std::cin >> p.city;
    std::cout << "what is your state name?: ";
    std::cin >> p.state;
    std::cout << "what is your zip code?: ";
    std::cin >> p.zipcode;
    return p;
}

 void player::saveplayerinfo(player info)
 {
 }

 player player::retrieveplayerinfo(std::string id)
 {
     return player();
 }
