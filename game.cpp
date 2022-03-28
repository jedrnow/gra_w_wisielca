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

void Play(const string &name,vector<users>& list,vector <string>& v1, vector <string>& v2, vector <string>& v3);

void Menu(const string &name, vector<users>&list,vector <string>& v1, vector <string>& v2, vector <string>& v3) {
    while (true)
    {
        system("cls");
        cout << "MENU GLOWNE" << endl;
        cout << "-----------------" << endl;
        cout << "1. Graj" << endl;
        cout << "2. Statystyki" << endl;
        cout << "3. Wyjdz" << endl;


        cout << endl;
        int choice;
        cout << "Wybierz: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            Play(name,list,v1, v2, v3);
            break;
        }

        else if (choice == 2) {
            int wybor=0;
            while (wybor != 3) {
                system("cls");
                ReadStats(list);
                cout << "3. Powrot do menu glownego" << endl;
                cin >> wybor;
            }
            Menu(name, list, v1, v2, v3);
            break;
        }
        else if (choice == 3) {
            exit(0);
            break;
        }
        else {
            cout << "Nie ma takiej opcji w menu!";
            Sleep(1000);
        }
    }
}


void Wisielec(const string& name,vector<users>& list,const string& h, int i, vector <string>& v1, vector <string>& v2, vector <string>& v3) {
    if (i == 0) cout << " " << endl;
    if (i == 1) cout << "/" << endl;
    if (i == 2) cout << "/ \\" << endl;
    if (i == 3) {
        cout << " |  " << endl;
        cout << "/ \\" << endl;
    }
    if (i == 4) {
        cout << " O  " << endl;
        cout << " |  " << endl;
        cout << "/ \\" << endl;
    }
    if (i == 5) {
        cout << " O  " << endl;
        cout << "/|  " << endl;
        cout << "/ \\" << endl;
    }
    if (i == 6) {
        cout << " O  " << endl;
        cout << "/|\\" << endl;
        cout << "/ \\" << endl;
    }
    if (i == 7) {
        cout << " |  " << endl;
        cout << " O  " << endl;
        cout << "/|\\" << endl;
        cout << "/ \\" << endl;
    }
    if (i == 8) {
        cout << " +---+  " << endl;
        cout << "     |  " << endl;
        cout << "     O  " << endl;
        cout << "    /|\\" << endl;
        cout << "    / \\" << endl;
    }
    if (i == 9) {
        cout << " +---+  " << endl;
        cout << " |   |  " << endl;
        cout << " |   O  " << endl;
        cout << " |  /|\\" << endl;
        cout << " |  / \\" << endl;
    }
    if (i == 10) {
        cout << " +---+  " << endl;
        cout << " |   |  " << endl;
        cout << " |   O  " << endl;
        cout << " |  /|\\" << endl;
        cout << " |  / \\" << endl;
        cout << "-+-     " << endl;
        cout << "KONIEC GRY!" << endl;
        cout << "POPRAWNA ODPOWIEDZ TO:  " << h << endl;
        AddWinLose(name, list, 0);
        SaveFromVectorToFile(list);

        Sleep(1500);
        Menu(name,list,v1, v2, v3);
    }
}

bool HitOrNot(string& answer, string h) {
    for (int i = 0; i < h.size(); i++) {
        if (answer[0] == h[i]) return true;
    }
    return false;
}

bool LetterOrNot(string& answer) {
    int x = answer[0];
    if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122)) {
        return true;
    }
    else return false;
}

bool WinnerOrNot(const vector<char>& v, const string& h) {
    for (int i = 0; i < h.size(); i++) {
        if (v[i] != h[i]) return false;
    }
    return true;
}

void Game(const string& h, const int n, const string& category, const string& name, vector<users>& list, vector <string>& v1, vector <string>& v2, vector <string>& v3) {
    system("cls");
    string choice;
    vector <char> v;
    int wrong_answer = 0;
    for (int i = 0; i < n; i++) {
        v.push_back('_');
    }
    while (true) {
        if (WinnerOrNot(v, h) == true) {
            cout << "Gratulacje!!! Wygrales!!!";
            AddWinLose(name, list, 1);
            SaveFromVectorToFile(list);
            Sleep(1000);
            Menu(name,list,v1, v2, v3);
        }
        cout << "Kategoria: " << category << endl << endl;
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl << endl << endl << endl;
        Wisielec(name,list,h, wrong_answer, v1, v2, v3);
        cout << endl << endl << "Podaj litere: " << endl;
        cin >> choice;
        char tmp2 = choice[0] + 32;
        string tmp3(1, tmp2);
        if (choice.size() > 1) {
            cout << "\n Podaj TYLKO jedna litere!";
            Sleep(1000);
            system("cls");
        }
        else if (LetterOrNot(choice) == false) {
            cout << "\n Podano zly znak!";
            Sleep(1000);
            system("cls");
        }
        else if (HitOrNot(choice, h) == true) {
            for (int i = 0; i < h.size(); i++) {
                if (choice[0] == h[i]) v[i] = choice[0];
            }
            cout << "Dobrze!";
            Sleep(1000);
            system("cls");
        }
        else if (HitOrNot(tmp3, h) == true) {
            for (int i = 0; i < h.size(); i++) {
                if (tmp3[0] == h[i]) v[i] = tmp3[0];
            }
            cout << "Dobrze!";
            Sleep(1000);
            system("cls");
        }
        else {
            cout << "Pudlo!";
            wrong_answer++;
            Sleep(1000);
            system("cls");
        }

    }
}

void Play(const string&name,vector<users>& list,vector <string>& v1, vector <string>& v2, vector <string>& v3) {
    while (true) {
        system("cls");
        string h;


        cout << "Wybierz kategorie: " << endl;
        cout << "1. Szkola" << endl;
        cout << "2. Ogrod" << endl;
        cout << "3. Meble" << endl;
        cout << "4. Powrot do menu glownego" << endl << endl;

        int choice;

        cout << "Wybierz: " << endl;
        cin >> choice;

        if (choice == 1) {
            h = Roll(v1);
            Game(h, h.size(), "Szkola", name, list, v1, v2, v3);
            break;
        }
        else if (choice == 2) {
            h = Roll(v2);
            Game(h, h.size(), "Ogrod", name, list, v1, v2, v3);
            break;
        }
        else if (choice == 3) {
            h = Roll(v3);
            Game(h, h.size(), "Meble", name,list, v1, v2, v3);
            break;
        }
        else if (choice == 4) {
            Menu(name,list,v1, v2, v3);
            break;
        }
        else {
            cout << "Nie ma takiej opcji w menu!";
            Sleep(1000);
            Play(name,list,v1, v2, v3);
            break;
        }
    }
    system("cls");

}