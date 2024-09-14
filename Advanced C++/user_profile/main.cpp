// Camden K., 9/13/24, cckirkpatrick@dmacc.edu
// This program demonstrates the use of a class that contains another class as a member variable.

/*
   1. How does the code demonstrate the principal of association?

      The account class contains a user object as a member variable. This is an example of association, where one class is associated with another class.
      The account class is associated with the user class. This shows a "has-a" relationship between the two classes, using composition.

    2. Could we have used inheritance instead, for example made Account a derived class of User?
       If so, what are the advantages of using association instead of inheritance in this case?

       Yes, we could have used inheritance instead, making Account a derived class of User. However, in this case, it makes more sense to use association.
       The reason being that an account is not a type of user, but rather an entity that has a user associated with it. This is a "has-a" relationship,
       which is better represented using association.

    3. We have not created any destructor yet, but when we do, should the destructor for Account call the destructor for User?

       No. Since the user object is a member variable of the account class, the user object will be destroyed automatically when the account object is destroyed.

*/

#include <iostream>
using namespace std;

#include "account.h"
#include "user.h"

int main()
{
   // Create a User object
   User user("John", "Doe", "123 Main St", "Anytown", "NY", "12345", "555-1234");
   // Create an Account object that contains the User object
   Account account(123456, 1000.00, user);

   // Display the account information, which contains the user information
   cout << "User Information" << endl;
   cout << "First Name: " << account.getUserFirstName() << endl;
   cout << "Last Name: " << account.getUserLastName() << endl;
   cout << "Address: " << account.getUserAddress() << endl;
   cout << "City: " << account.getUserCity() << endl;
   cout << "State: " << account.getUserState() << endl;
   cout << "Zip Code: " << account.getUserZipCode() << endl;
   cout << "Phone Number: " << account.getUserPhoneNumber() << endl
        << endl;

   cout << "Bank Information" << endl;
   cout << "Account Number: " << account.getBankAccountNumber() << endl;
   cout << "Amount: $" << account.getAmount() << endl;

   return 0;
}

/*
    Tests:
    Everything is working as expected. The account object contains the user object, and the account information is displayed correctly.
*/