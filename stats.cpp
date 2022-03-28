#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>
#include "users.h"
#include "words.h"
#include "stats.h"

using namespace std;

void SaveStatsFromFile(const string& fileName, vector<users>& list) {
    list.clear();
    string nick;
    int win, lose;
    fstream plik_stats(fileName, ios::in);
    while (plik_stats >> nick >> win >> lose) {
        users tmp;
        tmp.nick = nick;
        tmp.win = win;
        tmp.lose = lose;
        list.push_back(tmp);
    }
    plik_stats.close();

}

void SaveFromVectorToFile(vector<users>& list) {
    ofstream plik1("statystyki.txt", ios::trunc);
    if(plik1.good()){}
    plik1.close();
    fstream plik2("statystyki.txt", ios::app);
    for (int i = 0; i < list.size(); i++) {
        plik2 << list[i].nick << " " << list[i].win << " " << list[i].lose << endl;
    }
    plik2.close();

}

void AddToStats(const string& nick, vector<users>& list) {
    users tmp;
    tmp.nick = nick;
    tmp.lose = tmp.win = 0;
    list.push_back(tmp);
    SaveFromVectorToFile(list);
}

void AddWinLose(const string& nick, vector<users>& list, int pom) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i].nick == nick) {
            if (pom == 1)list[i].win++;
            else if (pom == 0)list[i].lose++;
        }
    }
}

void ReadStats(const vector<users>& list) {
    cout << "Statystyki: " << endl << endl;
    for (int i = 0; i < list.size(); i++) {
        cout << list[i].nick << endl;
        cout << "Wygrane: " << list[i].win << endl;
        cout << "Przegrane: " << list[i].lose << endl << endl;
    }
}

