#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>

/**
*  podprogram spelniajacy funkcje menu glownego
* \param[in] name nazwa gracza
* \param[in] list wektor zawierajacy statystyki wszystkich graczy
* \param[in] v1 wektor zawierajacy hasla z danej kategorii
* \param[in] v2 wektor zawierajacy hasla z danej kategorii
* \param[in] v3 wektor zawierajacy hasla z danej kategorii
*/
void Menu(const std::string& name, std::vector<users>& list,std::vector <std::string>& v1, std::vector <std::string>& v2, std::vector <std::string>& v3); 

/**
* funkcja rysujaca wisielca
* \param[in] name nazwa gracza
* \param[in] list wektor zawierajacy statystyki wszystkich graczy
* \param[in] h haslo do odgadniecia
* \param[in] i zmienna pomocnicza
* \param[in] v1 wektor zawierajacy hasla z danej kategorii
* \param[in] v2 wektor zawierajacy hasla z danej kategorii
* \param[in] v3 wektor zawierajacy hasla z danej kategorii
*/
void Wisielec(const std::string& name, std::vector<users>& list,const std::string& h, int i, std::vector <std::string>& v1, std::vector <std::string>& v2, std::vector <std::string>& v3);

/**
* funkcja sprawdzajaca czy uzytkownik podal dobra litere czy nie
* \param[in] answer podana przez uzytkownika odpowiedz
* \param[in] h haslo do odgadniecia
*/
bool HitOrNot(std::string& answer, std::string h);

/**
* funkcja sprawdzajaca czy uzytkownik podal litere czy inny znak
* \param[in] answer podana przez uzytkownika odpowiedz
*/
bool LetterOrNot(std::string& answer); 

/**
* funkcja sprawdzajaca czy uzytkownik juz wygral czy nie
* \param[in] v vektor zawierajacy aktualnie odgadniete znaki
* \param[in] h haslo do odgadniecia
*/
bool WinnerOrNot(const std::vector<char>& v, const std::string& h); 

/**
* podprogram, wlasciwa gra
* \param[in] h haslo do odgadniecia
* \param[in] n ilosc znakow w hasle
* \param[in] category kategoria hasla
* \param[in] name nazwa gracza
* \param[in] list wektor zawierajacy statystyki wszystkich graczy
* \param[in] v1 wektor zawierajacy hasla z danej kategorii
* \param[in] v2 wektor zawierajacy hasla z danej kategorii
* \param[in] v3 wektor zawierajacy hasla z danej kategorii
*/
void Game(const std::string& h, const int n, const std::string& category, const std::string& name, std::vector<users>& list, std::vector <std::string>& v1, std::vector <std::string>& v2, std::vector <std::string>& v3);

/**
* opcja menu, w ktorej uzytkownik wybiera kategorie hasla
* \param[in] name nazwa gracza
* \param[in] list wektor zawierajacy statystyki wszystkich graczy
* \param[in] v1 wektor zawierajacy hasla z danej kategorii
* \param[in] v2 wektor zawierajacy hasla z danej kategorii
* \param[in] v3 wektor zawierajacy hasla z danej kategorii
*/
void Play(const std::string& name, std::vector<users>& list,std::vector <std::string>& v1, std::vector <std::string>& v2, std::vector <std::string>& v3); 