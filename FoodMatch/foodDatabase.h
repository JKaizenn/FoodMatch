#ifndef FOOD_DATABASE_H
#define FOOD_DATABASE_H
#include "food.h"
#include <string>
#include <vector>

class FoodDatabase
{
public:
   FoodDatabase(); // Default Constructor
   FoodDatabase(std::string filename); // Non-Default Constructor
   ~FoodDatabase();
   
   // I/O Methods
   void loadFromFile(std::string filename); // Done
   void saveShoppingList(std::string filename);
   
   // Search
   void findExactMatch(std::string);
   void findCloseMatch(std::vector<Food> name);
   void findByCategory(std::vector<Food> category);
   
   // Shopping list
   void addToShoppingList(Food item);
   void displayShoppingList();
   
   // Display
   void displayAllFoods();
   
   
private:
   std::vector<Food> foods;
   std::vector<Food> category;
   
};
#endif
