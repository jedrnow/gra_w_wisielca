#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>
#include "users.h"
#include "stats.h"

using namespace std;

void CheckArgs(int argc, char* argv[]) {
    
    if (argc == 5) {
        string p1 = "-i";
        string p2 = "hasla.txt";
        string p3 = "-w";
        string p4 = "statystyki.txt";
        if (argv[1] == p1) {}
        else { cout << "Zly przelacznik lub kolejnosc przelacznikow!"; }
        if (argv[3] == p3) {}
        else{ cout << "Zly przelacznik lub kolejnosc przelacznikow!"; }
        if (argv[2] == p2) {}
        else { cout << "Plik z haslami musi miec nazwe: hasla.txt"; }
        if (argv[4] == p4) {}
        else{ cout << "Plik ze statystykami musi miec nazwe: statystyki.txt"; }
    }
    else {
        cout << "BLAD! Uzyj przelacznikow: -i plik z haslami oraz -w plik ze statystykami" << endl;
        cout << "np. program -i hasla.txt -w statystyki.txt";
    }
}

string Name() {
    string nick;
    cout << "Podaj swoje imie:   ";
    cin >> nick;
    return nick;
}

bool ExistOrNot(const string& nick, const vector<users>& list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].nick == nick) return true;
    }
    return false;
}

void Start(vector <users>& list, const string& nick) {
    if (ExistOrNot(nick, list) == true) {}
    else {
        AddToStats(nick, list);
    }
    system("cls");
}
