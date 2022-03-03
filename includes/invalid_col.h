#ifndef INVALID_Col
#define INVALID_Col

#include <stdexcept>

class invalid_col : public std::runtime_error
{
public:
    invalid_col(int) : runtime_error("Error: the number of columns is alphabetical.")
    {
    }
    invalid_col() : runtime_error("Error: the number of columns is negative.")
    {
    }
};
#endif