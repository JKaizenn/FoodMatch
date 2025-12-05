#include <iostream>
#include <string>
#include <fstream>
#include "food.h"
#include "foodDatabase.h"

/**************************
 * MAIN
 **************************/
int main()
{
   FoodDatabase db;
   std::cout << "Welcome to this Food Matching Program!\n" << "\n";
   db.loadFromFile("/Users/jforbush/Dev/C++/Personal_Projects/FoodMatch/FoodMatch/foodData.txt");
   db.displayAllFoods();
   
   return 0;
}
