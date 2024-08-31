#include <iostream>
#include <optional>
using namespace std;

optional<int> optional_v1(optional<int> test = nullopt)
{
    if (test != nullopt)
    {
        return test.value();
    }

    else
    {
        return nullopt;
    }
}

// You can also write the function like this
void optional_v2(optional<int> test = nullopt)
{
    if (test != nullopt)
    {
        cout << "Result = " << test.value();
    }

    else
    {
        cout << "Result = " << 0;
    }
}

int main()
{

    optional<int> result = optional_v1();              // The paramter test will be set to its default value (nullopt)
    cout << "Result = " << result.value_or(0) << endl; // This displays the value of result. If nullopt was returned, 0 will be displayed

    optional<int> test = 624;
    optional_v2(test); // This will overwrite the default parameter, and set it to 624

    // // This is a longer way of writing the code above
    // if (result.has_value())
    // {
    //     cout << "Result = " << result.value();
    // }
    // else
    // {
    //     cout << "Result is empty";
    // }

    return 0;
}

// #include <iostream>
// #include <optional>
// using namespace std;

// // Specify default character to  search for
// optional<size_t> find_character(const string &str,
//                                 optional<char> c = nullopt)
// {
//     // If found set return index, else return empty
//     // If c is specified, find it else just find 'z'
//     char char_to_find = c.value_or('z');

//     for (size_t i{}; i < str.size(); ++i)
//     {
//         // cout << "str[i] : " << str.at(i) << " , c : " << c << endl;
//         if (str[i] == char_to_find)
//         {
//             return i;
//         }
//     }
//     return {}; // Or nullopt
// }

// int main()
// {
//     string str1{};

//     str1 = "Hello Worldz in C++20!";

//     auto result1 = find_character(str1, 'o'); // Will search for 'z' if you don't specify
//                                               //  the character so search for
//     if (result1.has_value())
//     {
//         cout << "Found character 'o' at index " << result1.value() << endl;
//     }
//     else
//     {
//         cout << "Could not find character 'o' in the string : " << str1 << endl;
//     }

//     return 0;
// }
