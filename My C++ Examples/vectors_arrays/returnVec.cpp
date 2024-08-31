#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> returnVec(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "mushrooms")
        {
            v.erase(v.begin() + i);
        }
    }

    return v;
}

int main()
{

    vector<string> food = {"pizza", "burgers", "mushrooms", "icecream", "chocolate"};
    cout << "Original Foods: ";
    for (string food : food)
    {
        cout << food << " ";
    }
    cout << endl;
    vector<string> favoriteFoods = returnVec(food);
    cout << "Favorite Foods: ";
    for (string food : favoriteFoods)
    {
        cout << food << " ";
    }

    return 0;
}