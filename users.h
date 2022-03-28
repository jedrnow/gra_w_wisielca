#pragma once
#include <string>


/**
*  struktura przechowujaca nazwe uzytkownika, ilosc wygranych oraz ilosc przegranych
* \param[in] nick nazwa gracza
* \param[in] win ilosc wygranych
* \param[in] lose ilosc przegranych
*/
struct users {
	std::string nick;
	int win, lose;
};