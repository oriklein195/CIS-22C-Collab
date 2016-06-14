/**
 * Defines the header for the Food class.
 */

#ifndef __FOOD_H
#define __FOOD_H

#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * Represents an ingredient or a recipe made of food.
 */
class Food {

  int id;

  string name;

  string foodGroup;

  int calories;

  double fat;

  double protein;

  double fiber;

  double sugar;

  double carbohydrates;

  vector<int> ingredients;

public:
  
  Food();

  Food(int id, string name, string foodGroup, int calories, double fat,
       double protein, double fiber, double sugar, double carbohydrates);

  Food(int id, string name, vector<int> ingredients);

  ~Food(){};

  void calculateNutrients(vector<Food> ingredients){};

  int getId() const;

  string getName();

  string getFoodGroup();

  int getCalories();

  double getFat();

  double getProtein();

  double getFiber();

  double getSugar();

  double getCarbohydrates();

  vector<int> getIngredients();

  bool isIngredient();

  bool isRecipe();
 
  friend bool operator< (const Food &p1, const Food &p2);
   
  friend bool operator> (const Food &p1, const Food &p2);
    
};

bool operator< (const Food &f1, const Food &f2){
    return (f1.getId() < f2.getId());
};

bool operator> (const Food &f1, const Food &f2){
    return (f1.getId() > f2.getId());
};

#endif
