
#include <iostream>
#include "AVL.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    AVL myAVL;
    myAVL.insert("10");
    myAVL.insert("20");
    myAVL.insert("30");
    myAVL.insert("40");
    myAVL.insert("50");
    myAVL.insert("60");
    myAVL.insert("70");
    myAVL.insert("80");
    myAVL.insert("90");
    myAVL.insert("99");

    myAVL.insert("15");
    myAVL.insert("14");
    myAVL.insert("12");
    myAVL.insert("25");
    myAVL.insert("28");
    myAVL.insert("95");
    myAVL.insert("35");
    myAVL.insert("38");
    myAVL.insert("11");
    myAVL.insert("23");
    myAVL.insert("22");

    myAVL.printTree();

    cout << myAVL.range("10", "20") << endl;
    cout << myAVL.range("10", "99") << endl;
    cout << myAVL.range("45", "87") << endl;
    cout << myAVL.range("21", "39") << endl;
    cout << myAVL.range("21", "79") << endl;
    cout << myAVL.range("29", "79") << endl;
}
