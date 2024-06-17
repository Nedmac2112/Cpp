#include <iostream>
#include <conio.h> // For _getch() and _putch()

int main()
{
    std::string input;
    char ch;
    std::cout << "Enter your secret input: ";

    // Loop until Enter is pressed
    while ((ch = _getch()) != '\r')
    { // On Windows, Enter key has ASCII value '\r'
        if (ch == '\b')
        { // If backspace is pressed
            if (!input.empty())
            {
                // std::cout << "\b \b"; // Move cursor back, erase character, move cursor back again
                std::cout << "\b \b";
                // input.pop_back(); // Remove last character from input string
            }
        }
        else
        {
            std::cout << '*'; // Print asterisks instead of characters
            input += ch;      // Add character to input string
        }
    }

    std::cout << std::endl;
    std::cout << "You entered: " << input << std::endl;

    return 0;
}
