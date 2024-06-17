// #include <iostream>
// #include <vector>
// using namespace std;

// class Person
// {
// private:
//     string name;
//     int age;
//     static int objCount;

// public:
//     Person()
//     {
//         objCount++;
//         cout << "person " << objCount << " created\n";
//         name = "";
//         age = 0;
//     }

//     Person(string name, int age)
//     {
//         objCount++;
//         cout << "person " << objCount << " created\n";
//         this->name = name;
//         this->age = age;
//     }

//     string getName()
//     {
//         return name;
//     }
//     void setName(string name)
//     {
//         this->name = name;
//     }

//     int getAge()
//     {
//         return age;
//     }
//     void setAge(int age)
//     {
//         this->age = age;
//     }

//     void display()
//     {
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//     }

//     ~Person() {}
// };

// int Person::objCount = 0;

// int main()
// {
//     vector<Person *> people;

//     Person *p1 = new Person();
//     p1->setName("John");
//     p1->setAge(25);
//     p1->display();
//     people.push_back(p1);

//     cout << endl;

//     Person *p2 = new Person("Jane", 30);
//     p2->display();
//     people.push_back(p2);

//     for (int i = 0; i < people.size(); i++)
//     {
//         delete people[i];
//         people[i] = nullptr;
//         cout << "person " << i + 1 << " deleted\n";
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

template <typename T>
class Stuff
{
private:
    T *arr;
    int size;

public:
    Stuff(int size)
    {
        this->size = size;
        arr = new T[size];
    }

    void set(int index, T value)
    {
        arr[index] = value;
    }

    T get(int index)
    {
        return arr[index];
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (i == size - 1)
                cout << arr[i];
            else
                cout << arr[i] << ", ";
        }
        cout << endl;
    }

    ~Stuff()
    {
        delete[] arr;
        arr = nullptr;
    };
};

int main()
{
    int x;

    Stuff<int> intArr1(3);
    intArr1.set(0, 10);
    intArr1.set(1, 20);
    intArr1.set(2, 30);
    intArr1.display();

    Stuff<string> strArr1(3);
    strArr1.set(0, "John");
    strArr1.set(1, "Jane");
    strArr1.set(2, "Doe");
    strArr1.display();

    return 0;
}