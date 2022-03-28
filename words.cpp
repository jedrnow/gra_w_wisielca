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

void SaveToVector(const string& fileName, vector<string>& v) {
    string tmp;
    fstream plik(fileName);
    while (plik >> tmp) {
        v.push_back(tmp);
    }
    plik.close();
}

void SortToCategories(const vector<string>& v, vector<string>& kat1, vector<string>& kat2, vector <string>& kat3) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "SZKOLA") {
            kat1.push_back(v[i + 1]);
        }
        if (v[i] == "OGROD") {
            kat2.push_back(v[i + 1]);
        }
        if (v[i] == "MEBLE") {
            kat3.push_back(v[i + 1]);
        }
    }
}

int RollInt(const vector<string>& v) {
    srand(time(NULL));
    int x = rand() % v.size();
    return x;
}

string Roll(const vector<string>& v) {
    int i = RollInt(v);
    return v[i];
}