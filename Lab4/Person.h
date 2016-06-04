#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person{
public:
    bool byName;
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
    friend ostream& operator<<(ostream& os, const Person& p);
    friend bool operator< (const Person &p1, const Person &p2);
    friend bool operator> (const Person &p1, const Person &p2);
};
ostream& operator<<(ostream& os, const Person& p){
    os << p.name << ", " << p.month << "/" << p.day << "/" << p.year;
    return os;
};
bool operator< (const Person &p1, const Person &p2){
    if (p1.byName)
        return (p1.name < p2.name);
    return (p1.birthdate < p2.birthdate);
};
bool operator> (const Person &p1, const Person &p2){
    if (p1.byName)
        return (p1.name > p2.name);
    return (p1.birthdate > p2.birthdate);
};

#endif // !PERSON_H
