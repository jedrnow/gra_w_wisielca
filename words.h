#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>

/**
* funkcja zapisujaca hasla z pliku do wektora hasel
* \param[in] fileName nazwa pliku
* \param[in] v wektor zawierajacy hasla
*/
void SaveToVector(const std::string& fileName, std::vector<std::string>& v);

/**
* funkcja sortujaca hasla do wektorow z kategoriami
* \param[in] v wektor zawierajacy hasla
* \param[in] kat1 wektor z haslami danej kategorii
* \param[in] kat2 wektor z haslami danej kategorii
* \param[in] kat3 wektor z haslami danej kategorii
*/
void SortToCategories(const std::vector<std::string>& v, std::vector<std::string>& kat1, std::vector<std::string>& kat2, std::vector <std::string>& kat3);

/**
* funkcja zwracajaca losowa liczbe calkowita od 0 do konca dlugosci wektora kategorii
* \param[in] v wektor zawierajacy hasla
*/
int RollInt(const std::vector<std::string>& v); 

/**
* funkcja zwracajaca losowe slowo w wektorze kategorii
* \param[in] v wektor zawierajacy hasla
*/
std::string Roll(const std::vector<std::string>& v);

