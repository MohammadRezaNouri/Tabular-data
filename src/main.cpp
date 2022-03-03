#include <thread>
#include <chrono>
#include <sstream>
#include <algorithm>

#include "table.h"
#include "invalid_col.h"

using namespace std;

int main()
{
    system("clear || cls");
    cout << "Hi, welcome to my program." << endl;
    string t1;
    vector<string> tokens;
    vector<table *> Table;
    int Bool;
    chrono::seconds time(2);
    this_thread::sleep_for(time);
    cout << "Page cleaning = clear" << endl;
menu:
    cout << "> ";
    getline(cin, t1);
    if (t1 == "exit")
    {
        for (int i = 0; i < Table.size(); i++)
            delete Table[i];
        cout << "Bye" << endl;
        return 0;
    }
    if (t1 == "clear")
    {
        system("clear || cls");
        goto menu;
    }
    stringstream check1(t1);
    while (getline(check1, t1, ' '))
        if (t1.size() != 0)
            tokens.push_back(t1);
    for (int i = 0; i < tokens.size(); i++)
        transform(tokens[i].begin(), tokens[i].end(), tokens[i].begin(), [](unsigned char c)
                  { return tolower(c); });
    return 0;
}