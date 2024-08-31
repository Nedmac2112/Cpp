#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    // Check if character is alphanumeric
    cout << endl;
    cout << "isalnum : " << endl;

    cout << "C is alphanumeric : " << isalnum('C') << endl;
    cout << "^ is alphanumeric : " << isalnum('^') << endl;

    // You can use this as a test condition
    char input_char{'*'};
    if (isalnum(input_char))
    {
        cout << input_char << " is alhpanumeric." << endl;
    }
    else
    {
        cout << input_char << " is not alphanumeric." << endl;
    }

    // Check if character is alphabetic
    cout << endl;
    cout << "isalpha : " << endl;
    cout << "C is alphabetic : " << isalpha('e') << endl; // 1
    cout << "^ is alphabetic : " << isalpha('^') << endl; // 0
    cout << "7 is alphabetic : " << isalpha('7') << endl; // 0

    if (isalpha('e'))
    {
        cout << 'e' << " is alphabetic" << endl;
    }
    else
    {
        cout << 'e' << " is NOT alphabetic" << endl;
    }

    // Check if a character is blank
    cout << endl;
    cout << "isblank : " << endl;
    char message[]{"Hello there. How are you doing? The sun is shining."};
    cout << "message : " << message << endl;

    // Find and print blank index
    size_t blank_count{};
    for (size_t i{0}; i < size(message); ++i)
    {
        // cout << "Value : " << message[i] << endl;
        if (isblank(message[i]))
        {
            cout << "Found a blank character at index : [" << i << "]" << endl;
            ++blank_count;
        }
    }
    cout << "In total we found " << blank_count << " blank characters." << endl;

    // Check if character is lowercase or uppercase
    cout << "islower and isupper : " << endl;

    cout << endl;
    char thought[]{"The C++ Programming Language is one of the most used on the Planet"};
    size_t lowercase_count{};
    size_t upppercase_count{};

    // Print original string for ease of comparison on the terminal
    cout << "Original string  : " << thought << endl;

    for (auto character : thought)
    {
        if (islower(character))
        {
            cout << " " << character;
            ++lowercase_count;
        }
        if (isupper(character))
        {
            ++upppercase_count;
        }
    }
    cout << endl;
    cout << "Found " << lowercase_count << " lowercase characters and "
         << upppercase_count << " uppercase characters." << endl;

    // Check if a character is a digit
    cout << endl;
    cout << "isdigit : " << endl;

    char statement[]{"Mr Hamilton owns 221 cows. That's a lot of cows! The kid exclamed."};
    cout << "statement : " << statement << endl;

    size_t digit_count{};

    for (auto character : statement)
    {
        if (isdigit(character))
        {
            cout << "Found digit : " << character << endl;
            ++digit_count;
        }
    }
    cout << "Found " << digit_count << " digits in the statement string" << endl;

    // Turning a character to lowercase using the tolower() function
    cout << endl;
    cout << "tolower and toupper: " << endl;
    char original_str[]{"Home. The feeling of belonging"};
    char dest_str[size(original_str)];

    // Turn this to uppercase. Change the array in place
    for (size_t i{}; i < size(original_str); ++i)
    {
        dest_str[i] = toupper(original_str[i]);
    }

    cout << "Original string : " << original_str << endl;
    cout << "Uppercase string : " << dest_str << endl;

    // Turn this to lowercase. Change the array in place
    for (size_t i{}; i < size(original_str); ++i)
    {
        dest_str[i] = tolower(original_str[i]);
    }

    cout << "Lowercase string : " << dest_str << endl;
    /*



    */
    // C-string functions

    const char *s = "Hello";
    // strlen() returns the length of the string
    cout << strlen(s) << endl;
    // sizeof() returns the size of the pointer (8 bytes)
    cout << sizeof(s) << endl;

    const char *s1 = "Hello";
    const char *s2 = "Mello";
    // strcmp() compares two strings
    // returns 0 if they are equal, -1 if s1 < s2, 1 if s1 > s2
    cout << strcmp(s1, s2) << endl; // M is greater than H lexicographically, so -1 is returned

    const char *const str{"Try not. Do, or do not. There is no try."};
    char target = 'T';
    const char *result = str;
    size_t iterations{};

    // Find all occurrences of target in str (Only for C-strings)
    // strchr returns a pointer to the first occurrence of target in str
    while ((result = strchr(result, target)) != nullptr)
    {
        cout << "Found '" << target
             << "' starting at '" << result << "'\n";

        // Increment result, otherwise we'll find target at the same location
        ++result;
        ++iterations;
    }
    cout << "iterations : " << iterations << endl;

    // strrchr() finds the last occurrence of a character in a string
    char input[] = "/home/user/hello.cpp";
    char *output = strrchr(input, '/');
    int index = output - input; // Pointer arithmetic, subtracts the address of the first element of the array from the address of the found character
    if (output)
        cout << "Last occurrence of '/' found at index : " << index << endl;

    // strcat() concatenates two strings
    char combined[50] = "Hello"; // Make sure the destination array is large enough to hold the concatenated string
    char concat[50] = " World!";
    strcat(combined, concat);
    cout << combined << endl;

    // You can also use new to allocate memory for the combined string
    char *combined = new char[50]{"Hello"};
    char *concat = new char[50]{" World!"};
    strcat(combined, concat);
    cout << combined << endl;

    char combined2[50]{"Hello"};
    char concat2[30] = {" There is a bird on my window"};
    // This will concatenate the first 6 characters of source2 to dest2
    strncat(combined2, concat2, 6);
    cout << "The concatenated string is : " << combined2 << endl;

    // strcpy() copies a string to another
    const char *source = "C++ is a multipurpose programming language.";
    char *dest = new char[strlen(source) + 1]; // +1 for the null terminator
    strcpy(dest, source);
    cout << "dest : " << dest << endl;

    // strncpy() copies a string to another, but only the first n characters
    const char *source2 = "C++ is a multipurpose programming language.";
    char *dest2 = new char[strlen(source2) + 1]; // +1 for the null terminator
    strncpy(dest2, source2, 5);
    dest2[5] = '\0'; // Null terminate the string, since strncpy doesn't do this
    cout << "dest2 : " << dest2 << endl;
    return 0;
}