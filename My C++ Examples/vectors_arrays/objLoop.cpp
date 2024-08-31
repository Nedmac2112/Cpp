#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    string name;
    char letterGrade;
    int age;

public:
    void inputStudent()
    {
        char grades[] = {'A', 'B', 'C', 'D', 'F'};
        const int numGrades = sizeof(grades) / sizeof(grades[0]);
        bool found = false;

        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Letter Grade: ";
        cin >> letterGrade;
        letterGrade = toupper(letterGrade);

        while (!found)
        {
            for (int i = 0; i < numGrades; ++i)
            {
                if (letterGrade == grades[i])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Please enter a valid grade letter (A, B, C, D, or F): ";
                cin >> letterGrade;
                letterGrade = toupper(letterGrade);
            }
        }
    }
    void printStudent()
    {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << letterGrade << "\n";
    }

    char getGrade() const
    {
        return letterGrade;
    }

    string getName() const
    {
        return name;
    }
    Student() { cout << "Student object created\n"; };
    Student(string n, int a, char g) : name(n), age(a), letterGrade(g) { cout << "Student object created\n"; };
    ~Student() { cout << "Student object being destroyed!\n"; };
};

int main()
{
    int size = 0;
    int count = 0;

    cout << "How many students do you want to add to the list?: ";
    cin >> size;

    vector<Student> students(size);
    cout << "\n";

    for (int counter = 0; counter < size; counter = counter + 1)
    {
        cout << "Enter info for student " << counter + 1 << "\n";
        students[counter].inputStudent();
        cout << "\n";
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Student " << i + 1 << ":\t";
        students[i].printStudent();

        if (students[i].getGrade() == 'A')
        {
            cout << students[i].getName() << " is doing a great job!\n";
        }

        else if (students[i].getGrade() == 'F')
        {
            cout << students[i].getName() << " is failing!\n";
        }
    }

    return 0;
}
