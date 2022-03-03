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

void table::merge(table add)
{
    float *temp = new float[row * col];
    for (int i = 0; i < row * col; i++)
        temp[i] = _table[i];
    delete[] _table;
    _table = new float[(row * col) + (add.getRow() * add.getCol())];
    for (int i = 0; i < row * col; i++)
        _table[i] = temp[i];
    delete[] temp;
    for (int i = row * col, j = 0; i < (row * col) + (add.getRow() * add.getCol()); i++, j++)
        _table[i] = add._table[j];
    row = add.getRow() + row;
}

void table::sort(int check)
{
    if (check + 1 > col || check < 0)
    {
        cout << "The column in question does not exist." << endl;
        return;
    }
    else
        for (int i = check; i < (row * col) - col; i += col)
            if (_table[i] > _table[i + col])
            {
                float *temp = new float[col];
                for (int j = 0, k = i; j < col; j++, k++)
                {
                    temp[j] = _table[k - 1];
                    _table[k - 1] = _table[k + col - 1];
                    _table[k + col - 1] = temp[j];
                }
                delete[] temp;
                if (i > col)
                    i = i - (col * 2);
            }
}

void table::statistics()
{
    float temp1, temp2;
    vector<float> temp(row);
    cout << "[min ] [";
    for (int i = 0; i < col; i++)
    {
        for (int j = i, l = 0; j < col * row; j += col, l++)
            temp[l] = _table[j];
        temp1 = temp[0];
        for (int m = 1; m < temp.size(); m++)
            if (temp[m] < temp1)
            {
                temp1 = temp[m];
                m -= 2;
                if (m < -1)
                    m = -1;
            }
        cout << temp1 << " ";
    }
    cout << '\b' << "]" << endl
         << "[max ] [";
    for (int i = 0; i < col; i++)
    {
        for (int j = i, l = 0; j < col * row; j += col, l++)
            temp[l] = _table[j];
        temp1 = temp[0];
        for (int m = 1; m < temp.size(); m++)
            if (temp[m] > temp1)
            {
                temp1 = temp[m];
                m -= 2;
                if (m < -1)
                    m = -1;
            }
        cout << temp1 << " ";
    }
    cout << '\b' << "]" << endl
         << "[sum ] [";
    for (int i = 0; i < col; i++)
    {
        temp1 = 0;
        for (int j = i, l = 0; j < col * row; j += col, l++)
            temp1 += _table[j];
        cout << temp1 << " ";
    }
    cout << '\b' << "]" << endl
         << "[mean ] [";
    for (int i = 0; i < col; i++)
    {
        temp1 = 0;
        for (int j = i, l = 0; j < col * row; j += col, l++)
            temp1 += _table[j];
        cout << temp1 / row << " ";
    }
    cout << '\b' << "]" << endl
         << "[var ] [";
    for (int i = 0; i < col; i++)
    {
        temp1 = temp2 = 0;
        for (int j = i, l = 0; j < col * row; j += col, l++)
            temp1 += _table[j];
        temp1 /= row;
        for (int k = i; k < col * row; k += col)
            temp2 += pow((_table[k] - temp1), 2);
        cout << temp2 / row << " ";
    }
    cout << '\b' << "]" << endl
         << "[std ] [";
    for (int i = 0; i < col; i++)
    {
        temp1 = temp2 = 0;
        for (int j = i, l = 0; j < col * row; j += col, l++)
            temp1 += _table[j];
        temp1 /= row;
        for (int k = i; k < col * row; k += col)
            temp2 += pow((_table[k] - temp1), 2);
        cout << sqrt(temp2 / row) << " ";
    }
    cout << '\b' << "]" << endl;
}

void table::Export(string save)
{
    fstream tableFile(save, ios::app);
    if (tableFile.fail())
    {
        cout << "File storage was a problem." << endl;
        return;
    }
    if (row == 0)
    {
        tableFile << "table " << name << " with " << col << " columns and " << row << " rows" << endl;
        return;
    }
    tableFile << "table " << name << " with " << col << " columns and " << row << " rows" << endl;
    for (int i = 0; i < row; i++)
    {
        tableFile << '[' << i << "] [";
        for (int j = 0; j < (i * col) + col; j++)
        {
            tableFile << _table[j];
            if (j == ((i * col) + col) - 1)
                tableFile << ']' << endl;
            else
                tableFile << ' ';
        }
    }
    tableFile << endl;
    tableFile.close();
}