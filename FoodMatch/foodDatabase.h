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
   void findCloseMatch(std::string name);
   void findByCategory(std::string category);
   
   // Shopping list 
   void addToShoppingList(int index);
   void removeFromShopList(int index);

   // Display
   void displayAllFoods();
   void displayAllFoodsNumbered();
   void displayShoppingList();
   
private:
   std::vector<Food> foods;
   std::vector<Food> category;
   std::vector<Food> shoppingList;
};
#endif
