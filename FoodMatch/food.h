#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <list>

class Food
{
public:
   
   Food(); // Default Constructor
   Food(const Food & rhs); // Copy Constructor
   ~Food(); // Destructor
   
   // Getters
   std::string getName()     const { return name;     }
   uint getCalories()        const { return calories; }
   std::string getCategory() const { return category; }
   
   // Setters
   void setName(std::string name)         {this->name = name;         }
   void setCalories(uint calories)        {this->calories = calories; }
   void setCategory(std::string category) {this->category = category; }
   
   // Display a food's info
   void display();
   
private:
   std::string name;
   uint calories;
   std::string category;
};

#endif
