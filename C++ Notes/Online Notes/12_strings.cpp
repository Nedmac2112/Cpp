#include <iostream>
#include <string>
using namespace std;

int main()
{
    // String basics
    string firstName = "Camden";
    string nickName1{firstName, 0, 3}; // this starts at index 0, and takes 3 characters
    cout << "Nickname (using initilization): " << nickName1 << endl;

    string nickName2 = firstName.substr(0, 3); // this does the same thing as the previous line
    cout << "Nickname (using substr()): " << nickName2 << endl;

    string test1(4, '#'); // this is used to create a populate a string with 4 '#' characters
    cout << "Test: " << test1 << endl;

    // heres another way to create a string with 4 '#' characters
    string test1_1;
    test1_1.assign(4, '#');
    cout << "Test 1: " << test1_1 << endl;

    // String concatenation
    string lastName = "Kirkpatrick";
    string fullName = firstName + " " + lastName; // this is used to concatenate two strings
    cout << "Full name: " << fullName << endl;

    // Append to a string
    string greeting1 = "Hello";
    string greeting2 = " World";
    string greeting3 = greeting1.append(greeting2); // this is used to append the second string to the first string
    cout << "Greeting 1: " << greeting3 << endl;

    string greeting4 = greeting3.append(3, '!'); // this is used to append 3 '!' characters to the string
    cout << "Greeting 2: " << greeting4 << endl;

    greeting1 = "Hello";                                  // this is used to reset the greeting1 string (append returns a reference to the original string)
    string greeting5 = greeting1.append(greeting2, 0, 3); // this is used to append the second string starting at index 0, and taking 3 characters
    cout << "Greeting 3: " << greeting5 << endl;
    /*

    */
    // Print each character in a string
    string test2 = "This is a test";
    cout << "Print each character in a string: ";
    for (int i = 0; i < test2.size(); i++)
    {
        cout << test2.at(i) << " "; // you can also use test2[i]
        if (i == test2.size() - 1)
            cout << endl;
    }

    // Front and Back
    string test3 = "Random";
    cout << "First character: " << test3.front() << ", Last character: " << test3.back() << endl; // this is used to get the first and last character in a string

    // Empty and Length
    cout << "String is empty: " << boolalpha << test3.empty() << endl;
    cout << "Length of string: " << test3.length() << endl;

    // Clear
    test3.clear(); // this is used to clear the string
    cout << "String is empty: " << boolalpha << test3.empty() << endl;
    /*

    */
    // Insert
    string test4 = "127";
    test4.insert(1, 2, '0'); // this is used to insert a character at a specific index (starts at index 1, and inserts 2 '0' characters)
    cout << "Insert 1: " << test4 << endl;

    test4.insert(4, "58"); // this is used to insert a string at a specific index
    cout << "Insert 2: " << test4 << endl;

    string test5 = "I'm doing";
    string test6 = "Are you doing good?";
    test5.insert(9, test6, 13, 5); // this is used to insert a substring of a string at a specific index (inserts at index 9, and takes 5 characters starting at index 13)
    cout << "Insert 3: " << test5 << endl;

    // Erase
    test5.erase(3, 6); // this is used to erase a substring of a string (starts at index 3, and takes 6 characters)
    cout << "Erase: " << test5 << endl;

    // Pop back
    string test7 = "Puppy";
    test7.pop_back(); // this is used to remove the last character in a string
    cout << "Pop back: " << test7 << endl;

    // Push back
    test7.push_back('y'); // this is used to add a character to the end of a string
    cout << "Push back: " << test7 << endl;
    /*

    */
    // Comapring strings
    string test8 = "Hello";
    string test9 = "Bello";
    cout << "Compare (\"Hello\" and \"Bello\"): " << test8.compare(test9) << endl; // this is used to compare two strings (returns 0 if they are equal, -1 if the first string is less than the second string, 1 if the first string is greater than the second string)

    string test10 = "Long Sword";
    cout << "Compare (\"Sword\" and \"Hello\"): " << test10.compare(5, 5, test8) << endl; // this compares 5 characters of test10, starting at index 5, with test8

    cout << "Compare (\"Sword\" and \"ello\"): " << test10.compare(5, 5, test8, 1, 4) << endl; // this compares 5 characters of test11, starting at index 6, with 4 characters of test8, starting at index 1
    /*

    */
    // Replace
    string test11 = "Universe";
    test11.replace(7, 1, "ity");
    cout << "Replace 1: " << test11 << endl; // this is used to replace a substring of a string with another string (starts at index 3, and takes 5 characters)

    test11 = "Universe"; // this resets the string, since replace modifies the original string
    string test12 = "University";
    test11.replace(7, 1, test12, 7, 3);
    cout << "Replace 2: " << test11 << endl; // this is used to replace a substring of a string with a substring of another string (starts at index 3, and takes 7 characters starting at index 3)
    /*

    */
    // Swapping strings and other variables
    string test13 = "Drums";
    string test14 = "Guitar";
    cout << "Swapping strings: " << endl;
    cout << "Before swap: " << test13 << ", " << test14 << endl;
    test13.swap(test14); // this is used to swap the contents of two strings
    cout << "After swap: " << test13 << ", " << test14 << endl
         << endl;

    int num1 = 10;
    int num2 = 20;
    cout << "Swapping integers: " << endl;
    cout << "Before swap: " << num1 << ", " << num2 << endl;
    swap(num1, num2); // this is used to swap the contents of two variables (swap() is from the <algorithm> library)
    cout << "After swap: " << num1 << ", " << num2 << endl;
    /*

    */
    // Searching strings

    // find
    string test15 = "Hello, my name is Camden";
    string test16 = "Camden";
    cout << "Searching \"" << test15 << "\" for a substring: " << endl;
    int index = test15.find(test16); // this is used to find the first occurrence of a substring in a string (returns -1 if the substring is not found)
    if (index != string::npos)       // string::npos is used to check if the substring was found (if it is not equal to npos, then the substring was found)
    {
        cout << "Found \"" << test16 << "\" at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // Search at a specific index
    index = test15.find("name", 7); // this is used to find the first occurrence of a substring in a string starting at a specific index
    if (index != string::npos)
    {
        cout << "Found \"name\" at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // rfind
    index = test15.rfind("am"); // this is used to find the last occurrence of a substring in a string
    if (index != string::npos)
    {
        cout << "Found \"am\" at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // find_first_of
    string test17 = "aeiou";
    index = test15.find_first_of(test17); // this is used to find the first occurrence of any character in a string in another string
    if (index != string::npos)
    {
        cout << "Found first vowel at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // find_last_of
    index = test15.find_last_of(test17); // this is used to find the last occurrence of any character in a string in another string
    if (index != string::npos)
    {
        cout << "Found last vowel at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // find_first_not_of
    index = test15.find_first_not_of(test17); // this is used to find the first occurrence of a character that is not in a string in another string
    if (index != string::npos)
    {
        cout << "Found first non-vowel at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // find_last_not_of
    index = test15.find_last_not_of(test17); // this is used to find the last occurrence of a character that is not in a string in another string
    if (index != string::npos)
    {
        cout << "Found last non-vowel at index: " << index << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    /*

    */
    // Convert to string
    int num3 = 20;
    cout << "Combine a string and integer: " << firstName + ", age: " + to_string(num3) << endl;

    // String to integer (stoi)
    string test18 = "123";
    int num4 = stoi(test18); // this is used to convert a string to an integer
    cout << "String to integer: " << num4 << endl;

    // String to double (stod)
    string test19 = "123.45";
    double num5 = stod(test19); // this is used to convert a string to a double
    cout << "String to double: " << num5 << endl;

    // Raw string literals (used to ignore escape characters)
    string raw_str = R"(This is a line break:
And this is a quote: "Hello, World!")"; // spaces, and new lines are preserved

    cout << raw_str << endl;

    return 0;
}
