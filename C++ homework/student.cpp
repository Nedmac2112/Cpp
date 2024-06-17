// Camden K., 11/30/23, cckirkpatrick@dmacc.edu


// libraries
#include <iostream>
#include <vector>
using namespace std;

// Student class
class Student
{
private:
    string firstName;
    string lastName;
    string grade;

public:
    // constructors
    Student(){};

    // added this one in, but didn't haver a use for it
    Student(string fName, string lName, string grd)
    {
        firstName = fName;
        lastName = lName;
        grade = grd;
    }
    // setter and getter functions
    void setFirstName(string fName)
    {
        firstName = fName;
    }
    string getFirstName()
    {
        return firstName;
    }

    void setLastName(string lName)
    {
        lastName = lName;
    }
    string getLastName()
    {
        return lastName;
    }

    void setGrade(string grd)
    {
        grade = grd;
    }
    string getGrade()
    {
        return grade;
    }
};

int main()
{
    int numStudents;
    string firstName;
    string lastName;
    string grade;

    cout << "How many students do you want to add? ";
    cin >> numStudents;

    // vector of objects in the Student class
    vector<Student> sVector;
    // student object of class Student
    Student student;

    // loop that sets the properties of each student, and adds them to the vector
    for (int i = 0; i < numStudents; i++)
    {
        cout << "What is the first name of the student? ";
        cin >> firstName;
        student.setFirstName(firstName);

        cout << "What is the last name of the student? ";
        cin >> lastName;
        student.setLastName(lastName);

        cout << "What is the grade of the student? ";
        cin >> grade;
        student.setGrade(grade);

        sVector.push_back(student);
    }

cout << endl;

    // loop that displays each students information
    for (int i=0; i<numStudents; i++)
    {
        cout << "Student " << i+1 << " first name: "
        << sVector[i].getFirstName() << endl;

         cout << "Student " << i+1 << " last name: "
        << sVector[i].getLastName() << endl;

         cout << "Student " << i+1 << " grade: "
        << sVector[i].getGrade() << endl;

        cout << endl;
    }

    return 0;
}

/* Test
Input: 2, John, Howard, B, Rick, Maxwell, F

Expected:
Student 1 first name: John
Student 1 last name: Howard
Student 1 grade: B

Student 2 first name: Rick
Student 2 last name: Maxwell
Student 2 grade: F

Received:
Student 1 first name: John
Student 1 last name: Howard
Student 1 grade: B

Student 2 first name: Rick
Student 2 last name: Maxwell
Student 2 grade: F
*/