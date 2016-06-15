//
//  main.cpp
//  Hashtables
//
//  Created by Ori Klein on 6/14/16.
//  Copyright (c) 2016 Ori Klein. All rights reserved.
//

#include <iostream>
#include "HashTable.h"
#include "Food.h"
using namespace std;

int main(int argc, const char * argv[]) {

    HashTable<Food> test;
    Food f1 = Food(45, "banana", "fruits", 999, 999, 999, 999, 999, 999);
    Food f2 = Food(700, "apple", "fruits", 999, 999, 999, 999, 999, 999);
    Food f3 = Food(900, "apple", "fruits", 999, 999, 999, 999, 999, 999);
	test.insertItem(f1.getKey(), f1);
	test.insertItem(f2.getKey(), f2);
	test.insertItem(f3.getKey(), f3);
    test.printTable();

	system("pause");
    return 0;
}
