#include "Person.h"
#include "BST.h"
#include <fstream>
#include <iostream>

int main(){
  BST namesTree;
  BST datesTree;
  ifstream inFile("OriginalList.txt");
  if (inFile.is_open())
  {
  string name, year, month, day;
    while (inFile >> name >> month >> day >> year)
    {
      Person p = Perosn(true, name, year, month, day);
      namesTree.insert(p);
      Person p2 = Perosn(false, name, year, month, day);
      datesTree.insert(p2);
    }
    myfile.close();
  }
  ofstream nameOutput;
  ofstream dateOutput;
  namesTree.display(3, nameOutput, "namesList.txt");
  datesTree.display(4, dateOutput, "datesList.txt");

  return 0;
}
