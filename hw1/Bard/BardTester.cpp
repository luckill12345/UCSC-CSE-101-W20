#include "LinkedList.h"
#include "VocabList.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

int main(int argc, char const *argv[])
{
    LinkedList *list = new LinkedList();
    //   VocabList* vlist = new VocabList();

    list->insert("test");
    cout << list->length() << " entries: " << list->print() << endl;

    list->insert("apple");
    cout << list->length() << " entries: " << list->print() << endl;

    list->insert("chewy");
    cout << list->length() << " entries: " << list->print() << endl;

    list->insert("haw");
    cout << list->length() << " entries: " << list->print() << endl;

    list->sort();
    cout << list->length() << " entries: " << list->print() << endl;

    list->insert("haw");
    cout << list->length() << " entries: " << list->print() << endl;

    list->sort();
    cout << list->length() << " entries: " << list->print() << endl;

    list->deleteList();
    cout << list->length() << " entries (all deleted): " << list->print() << endl;

    cout << "------------------------------------------------" << endl;

    VocabList *vlist = new VocabList();

    ifstream src("shakespeare-cleaned5.txt");
    string temp;

    auto start = high_resolution_clock::now();

    if (src.is_open())
    {
        while (!src.eof())
        {
            getline(src, temp);
            // cout << "Inserting: " << temp << endl;
            vlist->insert(temp);
            // cout << "Inserted: " << temp << endl;
        }
    }
    cout << "Sorting..." << endl;
    vlist->sort();
    cout << "Sorted" << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<seconds>(stop - start);

    cout << "Time to input and sort: " << duration.count() << " seconds" << endl;

    //   cout<<vlist->print()<<endl;

    cout << vlist->getRank(6, 3) << endl;
    cout << vlist->getRank(10, 0) << endl;
    cout << vlist->getRank(9, 2) << endl;
    cout << vlist->getRank(8, 14) << endl;
    cout << vlist->getRank(8, 15) << endl;
    cout << vlist->getRank(26, 0) << endl;

    //   cout<<vlist->print(6)<<endl;

    cout << "Deleting... " << temp << endl;
    vlist->deleteList();
    cout << "Deleted " << temp << endl;
    //   free(temp);
    src.close();
    return 0;
}
