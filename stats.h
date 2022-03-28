#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>

/**
* zapisuje statystyki z pliku do wektora uzytkownikow
* \param[in] fileName nazwa pliku
* \param[in] list wektor przechowujacy aktualne statystyki graczy
*/
void SaveStatsFromFile(const std::string& fileName, std::vector<users>& list); 

/**
* funkcja dodajaca nowego uzytkownika do statystyk
* \param[in] nick nazwa gracza
* \param[in] list wektor przechowujacy aktualne statystyki graczy
*/
void AddToStats(const std::string& nick, std::vector<users>& list);

/**
* funkcja dodajaca uzytkownikowi wygrana lub przegrana do statystyk
* \param[in] nick nazwa gracza
* \param[in] list wektor przechowujacy aktualne statystyki graczy
* \param[in] pom zmienna pomocnicza
*/
void AddWinLose(const std::string& nick, std::vector<users>& list, int pom);

/**
* funkcja zapisujaca statystyki z wektora do pliku
* \param[in] list wektor przechowujacy aktualne statystyki graczy
*/
void SaveFromVectorToFile(std::vector<users>& list);

/**
* podprogram czytajacy statystyki
* \param[in] list wektor przechowujacy aktualne statystyki graczy
*/
void ReadStats(const std::vector<users>& list);