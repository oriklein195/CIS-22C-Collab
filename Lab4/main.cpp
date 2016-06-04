#include "Person.h"
#include "BST.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    BST<Person> namesTree;
    BST<Person> datesTree;
    
    ifstream inFile("OriginalList.txt");
    if (inFile.is_open())
    {
        string name, year, month, day;
        while (getline(inFile, name, ' '))
        {
            getline(inFile, month, ' ');
            getline(inFile, day, ' ');
            getline(inFile, year, ' ');
            Person p = Person(true, name, year, month, day);
            namesTree.insert(p);
            Person p2 = Person(false, name, year, month, day);
            datesTree.insert(p2);
            cout << "hello" << month << p;
        }
        inFile.close();
    }
    Person p = Person(true, "Ori", "1998", "01", "01");
    namesTree.insert(p);
    Person p2 = Person(false, "Ori", "1998", "01", "01");
    datesTree.insert(p2);
    ofstream nameOutput;
    ofstream dateOutput;
    namesTree.writeToFile(3, nameOutput, "SortedNames.txt");
    datesTree.writeToFile(4, dateOutput, "SortedDates.txt");
    return 0;
}
