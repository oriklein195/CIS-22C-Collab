#ifndef PERSON_H
#define PERSON_H

class Person{
private:
  bool byName;
public:
  string name, year, month, day;
  string birthdate;
  Person(){
    byName = true;
    name = "";
    birthdate = "";
  }
  Person(bool bN, string n, string y, string m, string d){
    byName = bN;
    name = n;
    year = y;
    month = m;
    day = d;
    birthdate = year+month+day;
  }
  ostream& operator<<(ostream& os, const Person& p){
	  os << p.name << ", " << p.month << "/" << p.day << "/" << p.year;
	  return os;
  }
  bool operator< (Person &p1, Person &p2){
    if (byName)
      return (p1.name < p2.name);
    return (p1.birthdate < p2.birthdate);
  }
  bool operator> (Person &p1, Person &p2){
    if (byName)
      return (p1.name > p2.name);
    return (p1.birthdate > p2.birthdate);
  }
  
}


#endif // !PERSON_H 
