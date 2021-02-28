#pragma once
#include <iostream>
#include <string>
class player
{
	
   public:
	player getplayerinfo();
	void saveplayerinfo(player info);
	player retrieveplayerinfo(std::string id);

	std::string firstname;
	std::string lastname;
	std::string id;
    int bdday;
	int bdmonth;
	int bdyear;
	int housenumber;
	std::string streetname;
	std::string city;
	std::string state;
	std::string zipcode;

};

