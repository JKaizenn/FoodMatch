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
   db.loadFromFile("/Users/jforbush/Dev/C++/Personal_Projects/FoodMatch/FoodMatch/foodData.txt");
   uint option {};
   std::cout << "Welcome to this Food Matching Program! \n"
             << "Please choose from the following menu options: \n"
             << "1. Display All Food Items \n"
             << "2. Load from file \n"
             << "\n";
   
   std::cin >> option;

   switch (option)
   {
      case 1:
         std::cout << "Here are the all foods: " << '\n';
         db.displayAllFoods();
   }
   
   return 0;
}
