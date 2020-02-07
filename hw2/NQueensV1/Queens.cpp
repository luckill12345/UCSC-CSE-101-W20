#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>

#include "Queens.h"

using namespace std;

Queens::Queens()
{
    row = -1;
    col = -1;
}

Queens::Queens(int newrow, int newcol)
{
    row = newrow;
    col = newcol;
}

Queens::Queens(int newrow, int newcol, bool newgiven)
{
    row = newrow;
    col = newcol;
    given = newgiven;
}

int Queens::getRow()
{
    return row;
}

int Queens::getCol()
{
    return col;
}

bool Queens::editable()
{
    return !given;
}