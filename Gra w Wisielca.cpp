#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include<windows.h>
#include "users.h"
#include "words.h"
#include "stats.h"
#include "game.h"
#include "start.h"

using namespace std;


int main(int argc, char* argv[])
{
    CheckArgs(argc, argv);
    vector <users> list;
    vector <string> hasla, szkola, ogrod, meble;
    fstream plik("hasla.txt");
    plik.close();
    SaveStatsFromFile("statystyki.txt", list);
    SaveToVector("hasla.txt", hasla);
    SortToCategories(hasla, szkola, ogrod, meble);
    
    string nick = Name();
    Start(list,nick);
    Menu(nick,list,szkola, ogrod, meble);
    
    
    
    return 0;
}
