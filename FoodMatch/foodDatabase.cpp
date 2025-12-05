#include "foodDatabase.h"
#include "food.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

FoodDatabase::FoodDatabase()
{
   // vectors initialize empty by default
}

FoodDatabase::~FoodDatabase()
{
   // empty is fine
}

/**************************
 FOOD_DATABASE: LOADFROMFILE
 **************************/
void FoodDatabase::loadFromFile(std::string filename)
{
   std::ifstream file(filename);
   std::string line;
   
   // Check if the file opened
   if (!file.is_open())
   {
      std::cout << "Error: Could not open file " << filename << std::endl;
      return;
   }
   
   // Skip header row
   std::getline(file, line);
   
   // Read remaining lines
   while (std::getline(file, line))
   {
      // Parse the line
      std::stringstream ss(line);
      std::string name;
      std::string calories_str;
      std::string category;
      
      std::getline(ss, name, ',');
      std::getline(ss, calories_str, ',');
      std::getline(ss, category);
      
      uint calories = static_cast<uint>(std::stoul(calories_str)); // Convert to uint
      
      // Create a food object
      Food item;
      item.setName(name);
      item.setCalories(calories);
      item.setCategory(category);
      
      // Add member to vector
      foods.push_back(item);
   }

   file.close(); // Close file
}

/**************************
 FOOD_DATABASE: DISPLAYALLFOODS
 **************************/
void FoodDatabase::displayAllFoods()
{
   for (int i = 0; i < foods.size(); i++)
   {
      foods[i].display();
   }
}
