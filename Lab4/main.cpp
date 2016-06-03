#include "Person.h"
#include "BST.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
  BST<Person> namesTree;
  BST<Person> datesTree;
  ifstream myFile;
  string name, year, month, day;
  myFile.open("OriginalList.txt", ios::in);
  if (myFile.is_open())
  {
  while (getline(myFile, name, ' '))
    {
		getline(myFile, month, ' ');
		getline(myFile, day, ' ');
		getline(myFile, year, ' ');
      Person p = Person(true, name, year, month, day);
      namesTree.insert(p);
      Person p2 = Person(false, name, year, month, day);
      datesTree.insert(p2);
    }
    myFile.close();
  }
  cout << namesTree.getRoot()->getData();
  ofstream nameOutput;
  ofstream dateOutput;
  namesTree.writeToFile(2, nameOutput, "SortedNames.txt");
  datesTree.writeToFile(4, dateOutput, "SortedDates.txt");

 
  system("pause");
  return 0;
}
