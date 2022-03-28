#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>
#include "users.h"


/**
* funkcja sprawdzajaca poprawne wywolanie programu z lini polecen
*/
void CheckArgs(int argc, char* argv[]);

/**
* funkcja pobierajaca nazwe uzytkownika
*/
std::string Name();

/**
* funkcja sprawdzajaca czy dany uzytkownik jest w bazie statystyk
* \param[in] nick nazwa gracza
* \param[in] list wektor przechowujacy aktualne statystyki graczy
*/
bool ExistOrNot(const std::string& nick, const std::vector<users>& list); 

/**
* podprogram, ktory wywoluje funkcje dodajaca nowego uzytkownika do statystyk, jesli jeszcze nie znajduje sie w statystykach
* \param[in] list wektor przechowujacy aktualne statystyki graczy
* \param[in] nick nazwa gracza
*/
void Start(std::vector <users>& list, const std::string& nick);