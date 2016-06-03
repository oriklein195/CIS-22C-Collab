#ifndef PERSON_H
#define PERSON_H

class Person{
private:
  string name;
  string birthdate;
public:
  Person(){
    name = "";
    birthdate = "";
  }
  Person(string n, string year, string month, string day){
    name = n;
    birthdate = year+month+day;
  }
  
}


#endif // !PERSON_H 
