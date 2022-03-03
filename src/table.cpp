#include "table.h"
#include "invalid_col.h"

#include <vector>
#include <cmath>
#include <fstream>

table::table(string name, string col)
{
    setName(name);
    setCol(col);
}

void table::setName(string Name)
{
    name = Name;
}

void table::setCol(string Col)
{
    for (int i = 0; i < Col.size(); i++)
        if (Col[i] < '0' || Col[i] > '9')
            throw invalid_col(0);
    if (stoi(Col) < 0)
        throw invalid_col();
    col = stoi(Col);
    _table = new float[row];
    for (int i = 1; i <= row; i++)
        _table[i - 1] = 0;
}

string table::getName()
{
    return name;
}

int table::getCol()
{
    return col;
}

int table::getRow()
{
    return row;
}