// Purpose: Show how to use private functions in a class
// Description: This program shows how to use private functions in a class. The private function SetHumanYears is used to calculate the human years of a dog. The function SetHumanYears is called from the public function SetWeightAndAge. The function GetHumanYears is used to get the human years of the dog. The function SetHumanYears cannot be called from outside the class.
// Last modified: 5/7/2024

#include <iostream>
using namespace std;

class Dog
{
public:
   void SetWeightAndAge(int weightToSet, int ageToSet);
   int GetHumanYears() const;

private:
   int years;
   int weight;
   string size;
   int humanYears;
   void SetHumanYears();
};

void Dog::SetWeightAndAge(int weightToSet, int yearsToSet)
{
   weight = weightToSet;

   if (weight <= 20)
   {
      size = "small";
   }
   else if (weight <= 45)
   {
      size = "medium";
   }
   else
   {
      size = "large";
   }

   years = yearsToSet;
   SetHumanYears();
}

// This function is private and cannot be called from outside the class
void Dog::SetHumanYears()
{
   int factor;

   if (size == "small")
   {
      factor = 6;
   }
   else if (size == "medium")
   {
      factor = 7;
   }
   else
   {
      factor = 8;
   }

   humanYears = years * factor;
}

int Dog::GetHumanYears() const
{
   return humanYears;
}

int main()
{
   Dog buddy;

   buddy.SetWeightAndAge(40, 8);

   cout << "Human years: " << buddy.GetHumanYears();

   // This line will not compile because SetHumanYears is a private function
   // buddy.SetHumanYears();
   return 0;
}