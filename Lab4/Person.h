#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person{
private:
  bool byName;
  string name, year, month, day;
  string birthdate;
public:
  
  Person(){
    byName = true;
    name = "";
    birthdate = "";
  }
  friend ostream& operator<<(ostream& os, const Person& p);
  Person(bool bN, string n, string y, string m, string d){
    byName = bN;
    name = n;
    year = y;
    month = m;
    day = d;
    birthdate = year+month+day;
  }

  bool operator< (Person &p1){
    if (byName)
      return (name < p1.name);
    return (birthdate < p1.birthdate);
  }
  bool operator> (Person &p1){
    if (byName)
      return (name > p1.name);
    return (birthdate > p1.birthdate);
  }
  string getName(){ return name; }
  string getYear(){ return year; }
  string getMonth(){ return month; }
  string getDay(){ return day; }
  string getBirthdate() { return birthdate; }
  
};
ostream& operator<<(ostream& os, const Person& p){
	os << p.name << ", " << p.month << "/" << p.day << "/" << p.year;
	return os;
};

#endif // !PERSON_H 
