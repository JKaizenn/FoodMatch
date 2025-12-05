#include "food.h"
#include <iostream>
#include <string>
#include <fstream>

// Default CTOR
Food::Food()
{
   // default values (optional)
   name = "";
   calories = 0;
   category = "";
}

// Non-Default CTOR
Food::Food(const Food& rhs)
{
   name = rhs.name;
   calories = rhs.calories;
   category = rhs.category;
}

Food::~Food() {}

/**************************
 FOOD::DISPLAY
 Displays a food item's attributes (name, calories, category, etc)
 **************************/
void Food::display()
{
   std::cout << "Food: " << name << '\n';
   std::cout << "Calories: " << calories << '\n';
   std::cout << "Category: " << category << '\n';
}
