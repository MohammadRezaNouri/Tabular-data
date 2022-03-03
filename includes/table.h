#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class table
{
private:
    string name;
    float *_table;
    int col = 0, row = 0;

public:
    table(string, string);
    void setName(string);
    void setCol(string);
    string getName();
    int getCol();
    void insert(vector<string>);
    void display();
    void drop(int, vector<string>);
    void merge(table);
    int getRow();
    void sort(int);
    void statistics();
    void Export(string);
    void import(string);
    ~table();
};

#endif