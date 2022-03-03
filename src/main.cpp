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
    if (tokens[0] == "create")
    {
        if (tokens.size() == 2)
        {
            cerr << "The number of columns is not entered." << endl;
            tokens.erase(tokens.begin(), tokens.end());
            goto menu;
        }
        for (int i = 0; i < Table.size(); i++)
            if (tokens[1] == Table[i]->getName())
            {
                cerr << "Error: table " << tokens[1] << " alreasy exists." << endl;
                tokens.erase(tokens.begin(), tokens.end());
                goto menu;
            }
        try
        {
            Table.push_back(new table(tokens[1], tokens[2]));
            tokens.erase(tokens.begin(), tokens.end());
            goto menu;
        }
        catch (invalid_col &Err)
        {
            cerr << Err.what() << endl;
            tokens.erase(tokens.begin(), tokens.end());
            goto menu;
        }
    }
    else if (tokens[0] == "insert")
    {
        Bool = 0;
        for (int i = 0; i < Table.size(); i++)
            if (tokens[1] == Table[i]->getName())
            {
                Bool = 1;
                if (tokens.size() - 2 == Table[i]->getCol())
                {
                    Table[i]->insert(tokens);
                    tokens.erase(tokens.begin(), tokens.end());
                    goto menu;
                }
                else
                {
                    cerr << "The number of columns is not equal." << endl;
                    tokens.erase(tokens.begin(), tokens.end());
                    goto menu;
                }
            }
        if (Bool == 0)
        {
            cerr << "There is no table with this name." << endl;
            tokens.erase(tokens.begin(), tokens.end());
            goto menu;
        }
    }
    else if (tokens[0] == "display")
    {
        Bool = 0;
        for (int i = 0; i < Table.size(); i++)
            if (tokens[1] == Table[i]->getName())
            {
                Bool = 1;
                Table[i]->display();
                tokens.erase(tokens.begin(), tokens.end());
                goto menu;
            }
        if (Bool == 0)
        {
            cerr << "There is no table with this name." << endl;
            tokens.erase(tokens.begin(), tokens.end());
            goto menu;
        }
    }
    else if (tokens[0] == "drop")
    {
        Bool = 0;
        for (int i = 0; i < Table.size(); i++)
            if (tokens[1] == Table[i]->getName())
            {
                Bool = 1;
                Table[i]->drop(tokens.size(), tokens);
                tokens.erase(tokens.begin(), tokens.end());
                goto menu;
            }
        if (Bool == 0)
        {
            cerr << "There is no table with this name." << endl;
            tokens.erase(tokens.begin(), tokens.end());
            goto menu;
        }
    }
    return 0;
}