#include <iostream>
#include <string>
#include <fstream>
#include "food.h"
#include "foodDatabase.h"
#include <cstdlib>


/**************************
 * CLEAR_SCREEN
 **************************/
void clearScreen()
{
   system("clear");
}

/**************************
 * SEARCH_MENU
 **************************/
void searchMenu(FoodDatabase& db)
{
   uint searchOption = {0};
   while(searchOption != 4)
   {
      clearScreen();
      std::cout << "\n===== SEARCH MENU =====\n"
      << "1. Exact Match\n"
      << "2. Close Match\n"
      << "3. Search by Category\n"
      << "4. Back to Main Menu\n"
      << "Choice: ";
      clearScreen();
      std::cin >> searchOption;
      
      switch (searchOption)
      {
         case 1:
         {
            std::string name;
            std::cout << "Enter exact name: ";
            std::cin >> name;
            db.findExactMatch(name);
            break;
         }
            
         case 2:
         {
            std::string name;
            std::cout << "Enter a name: ";
            std::cin >> name;
            db.findCloseMatch(name);
            break;
         }
            
         case 3:
         {
            std::string category;
            std::cout << "Enter category (fruit, vegetable, protein, grain , dairy, nuts, etc): ";
            std::cin >> category;
            db.findByCategory(category);
            break;
         }
            
         case 4:
            std::cout << "Returning to the main menu...\n";
            break;
            
         default:
            std::cout << "Invalid Option.\n";
      }
   }
}

/**************************
 * SEARCH_MENU
 **************************/
void shopMenu(FoodDatabase& db)
{
   uint shopOption = {0};
   while(shopOption != 5)
   {
      clearScreen();
      std::cout << "\n===== SEARCH MENU =====\n"
      << "1. View Shopping List\n"
      << "2. Add Item\n"
      << "3. Remove Item\n"
      << "4. Save List to File\n"
      << "5. Back to Main Menu\n"
      << "Choice: ";
      clearScreen();
      std::cin >> shopOption;
      
      switch (shopOption)
      {
         case 1:
         {
            db.displayShoppingList();
            break;
         }
            
         case 2:
         {
            db.displayAllFoodsNumbered();
            int index;
            std::cout << "Enter a number to add: " << '\n';
            std::cin >> index;
            db.addToShoppingList(index);
            break;
         }
            
         case 3:
         {
            db.displayShoppingList();
            int index;
            std::cout << "Enter number to remove: " << '\n';
            std::cin >> index;
            db.removeFromShopList(index);
            break;
         }
            
         case 4:
         {
            std::string filename;
            std::cout << "Enter filename: " << "\n";
            std::cin >> filename;
            db.saveShoppingList(filename);
            break;
         }
            
         case 5:
            std::cout << "Returning to the main menu...\n";
            break;
            
         default:
            std::cout << "Invalid Option.\n";
      }
   }
}
 
/**************************
 * MAIN
 **************************/
int main()
{
   FoodDatabase db;
   db.loadFromFile("/Users/jforbush/Dev/C++/Personal_Projects/FoodMatch/FoodMatch/foodData.txt");
   
   uint option = {0};
   while (option != 5)
   {
      clearScreen();
      std::cout << "\n===== MAIN MENU =====\n"
      << "1. Display All Foods\n"
      << "2. Search Menu\n"
      << "3. Shopping List Menu\n"
      << "4. Load From File\n"
      << "5. Exit\n"
      << "Choice: ";
      std::cin >> option;
      
      switch (option)
      {
         case 1:
         {
            db.displayAllFoodsNumbered();
            break;
         }
            
         case 2:
         {
            searchMenu(db);
            break;
         }
            
         case 3:
         {
            shopMenu(db);
            break;
         }
            
         case 4:
         {
         std::string filepath;
         std::cout << "Enter file path: " << '\n';
         std::cin >> filepath;
         db.loadFromFile(filepath);
         break;
         }
            
         case 5:
            std::cout << "Goodbye! \n";
            break;
            
         default:
            std::cout << "Invalid Option!" << '\n';
      }
   }

   return 0;
}
