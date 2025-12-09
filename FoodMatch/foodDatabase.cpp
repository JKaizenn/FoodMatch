#include "foodDatabase.h"
#include "food.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

/**************************
 FOOD_DATABASE: DEFAULT CONSTRUCTOR
 **************************/
FoodDatabase::FoodDatabase() { } // vectors initialize empty by default

/**************************
 FOOD_DATABASE: DESTRUCTOR
 **************************/
FoodDatabase::~FoodDatabase() { }

/**************************
 FOOD_DATABASE: LOAD_FROM_FILE
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
 FOOD_DATABASE: SAVE_SHOPPING_LIST
 **************************/
void FoodDatabase::saveShoppingList(std::string filename)
{
   std::ofstream file(filename);
   
   if(!file.is_open())
   {
      std::cout << "Error: Could not create file." << '\n';
      return;
   }
   
   // Write header
   file << "name, calories, category" << '\n';
   
   // Write each item
   for (int i = 0; i < shoppingList.size(); i++)
   {
      file << shoppingList[i].getName()
           << "," << shoppingList[i].getCalories()
           << ","
           << shoppingList[i].getCategory()
           << '\n';
   }
   
   file.close();
   std::cout << "Shopping list saved to: " << filename << '\n';
}

/**************************
 * FOOD_DATABASE: FIND_EXACT_MATCH
 * Finds the exact match of an item in the grocery catalog
 **************************/
void FoodDatabase::findExactMatch(std::string name)
{
   bool found = false; // Set a flag that tells us if the item is found to false.
   
   // Check the conditions to find the item
   for (int i = 0; i < foods.size(); i++)
   {
      if (foods[i].getName() == name)
      {
         std::cout << "Found: " << foods[i].getName() << '\n';
         std::cout << "Position: " << (i + 1) << '\n';
         found = true;
         break;
      }
   }
   
   // Condition outside of loop, if item is not found, prints statement
   if (!found)
   {
      std::cout << "Item not found." << '\n';
   }
}
/**************************
 * FOOD_DATABASE: FIND_CLOSE_MATCH
 * Finds items in the catalog that have similar matches in the names. Case insenstive
 **************************/

void FoodDatabase::findCloseMatch(std::string name)
{
   bool found = false;
   
   // Convert input to lowercase
   std::string lowerInput = name;
   for (int i = 0; i < lowerInput.size(); i++)
   {
      lowerInput[i] = std::tolower(lowerInput[i]);
   }
   
   for (int i = 0; i < foods.size(); i++)
   {
      // Convert food name to lowercase
      std::string lowerFood = foods[i].getName();
      for(int j = 0; j < lowerFood.size(); j++)
      {
         lowerFood[j] = std::tolower(lowerFood[j]);
      }
      
      // Check if starts with input
      if (lowerFood.substr(0, lowerInput.length()) == lowerInput)
      {
         std::cout << (i + 1) << ". " << foods[i].getName() << '\n';
         found = true;
      }
   }
   
   if (!found)
      std::cout << "No items found." << '\n';
}

/**************************
 * FOOD_DATABASE: FIND_BY_CATEGORY
 * Finds all items that belong to the same category of items (eg. Fruit, Grains, etc.)
 **************************/
void FoodDatabase::findByCategory(std::string category)
{
   // Set a flag that tells us if the item is found to false.
   bool found = false;
   
   for (int i = 0; i < foods.size(); i++)
   {
      if (foods[i].getCategory() == category)
      {
         std::cout << (i + 1) << "." << foods[i].getCategory() << '\n';
         found = true; // Sets found to true so all items in category are printed
      }
   }
   
   // Condition outside of loop, if item is not found, prints statement
   if (!found)
      std::cout << "Category not found." << '\n';
}

/**************************
 FOOD_DATABASE: ADD_TO_SHOPPING_LIST
 **************************/
void FoodDatabase::addToShoppingList(int index)
{
   if (index < 1 || index > foods.size())
   {
      std::cout << "Invalid Selection!" << '\n';
      return;
   }
   
   shoppingList.push_back(foods[index - 1]);
   std::cout << foods[index - 1].getName() << " added to shopping list!" << '\n';
   std::cout << "This item has: " << foods[index - 1].getCalories() << " calories"
             << " and is a " << foods[index - 1].getCategory() << '\n';
}

/**************************
 FOOD_DATABASE: REMOVE_FROM_SHOPPING_LIST
 **************************/
void FoodDatabase::removeFromShopList(int index)
{
   if (index < 1 || index > shoppingList.size())
   {
      std::cout << "Invalid selection." << std::endl;
      return;
   }
   
   std::cout << shoppingList[index - 1].getName() << " removed." << std::endl;
   shoppingList.erase(shoppingList.begin() + (index - 1));
}

/**************************
 FOOD_DATABASE: DISPLAY_ALL_FOODS
 **************************/
void FoodDatabase::displayAllFoods()
{
   for (int i = 0; i < foods.size(); i++)
   {
      foods[i].display();
   }
}

/**************************
 FOOD_DATABASE: DISPLAY_ALL_FOODS_NUMBERED
 **************************/
void FoodDatabase::displayAllFoodsNumbered()
{
   for (int i = 0; i < foods.size(); i++)
   {
      std::cout << (i + 1) << ". " << foods[i].getName() << '\n';
   }
}

/**************************
 FOOD_DATABASE: DISPLAY_SHOPPING_LIST
 **************************/
void FoodDatabase::displayShoppingList()
{
   if (shoppingList.empty())
   {
      std::cout << "Shopping list is empty!" << '\n';
      return;
   }
   
   for (int i = 0; i < shoppingList.size(); i++)
   {
      std::cout << (i + 1) << ". " << shoppingList[i].getName() << '\n';
   }
}
