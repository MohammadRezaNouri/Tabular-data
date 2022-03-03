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

void table::insert(vector<string> tokens)
{
    float *temp = new float[row * col];
    for (int i = 0; i < row * col; i++)
        temp[i] = _table[i];
    delete[] _table;
    row++;
    _table = new float[row * col];
    for (int i = 0; i < (row - 1) * col; i++)
        _table[i] = temp[i];
    delete[] temp;
    for (int i = (row - 1) * col, j = 2; i < col * row; i++, j++)
        if (i == (row - 1) * col)
            _table[i] = stof(tokens[j].substr(1));
        else
            _table[i] = stof(tokens[j]);
}

void table::display()
{
    if (row == 0)
    {
        cout << "This table has no data" << endl;
        return;
    }
    cout << "table " << name << " with " << col << " columns and " << row << " rows" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "[" << i << "] [";
        for (int j = 0; j < (i * col) + col; j++)
        {
            cout << _table[j];
            if (j == ((i * col) + col) - 1)
                cout << "]" << endl;
            else
                cout << " ";
        }
    }
}

void table::drop(int rm, vector<string> tokens)
{
    if (rm == 2)
    {
        delete[] _table;
        row = 0;
        _table = new float[row];
        for (int i = 1; i <= row; i++)
            _table[i - 1] = 0;
    }
    else
    {
        if (stoi(tokens[2]) > row)
        {
            cout << "The row in question does not exist." << endl;
            return;
        }
        else
        {
            for (int i = stoi(tokens[2]) * col; i < (row * col) - col; i++)
                _table[i] = _table[i + col];
            float *temp = new float[--row * col];
            for (int i = 0; i < row * col; i++)
                temp[i] = _table[i];
            delete[] _table;
            _table = new float[row * col];
            for (int i = 0; i < row * col; i++)
                _table[i] = temp[i];
            delete[] temp;
        }
    }
}