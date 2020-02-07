#ifndef QUEENS
#define QUEENS

class Queens
{
private:
    int row;
    int col;
    bool given = false;

public:
    Queens();
    Queens(int, int);
    Queens(int, int, bool);
    int getRow();
    int getCol();
    bool editable();
};
#endif