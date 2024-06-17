/* Purpose: shows how to pass objects as arguments to a function

This program creates 2 student objects, and assigns each of them 2 test scores.
After that, the program calculates the average of each students test scores, and
assign the average of those 2 scored to the average score of student 3
*/

#include <iostream>
using namespace std;

class Student
{
private:
    double testScore1;
    double testScore2;
    double avgScore;

public:
    // the member variables are set to 0 by default
    Student() : testScore1(0), testScore2(0), avgScore(0){};
    // sets the values of s1 and s2 objects
    void setScore(double t1, double t2)
    {
        testScore1 = t1;
        testScore2 = t2;
        avgScore = (t1 + t2) / 2;
    }
    // sets the averageScore for the s3 object
    void setAvgScore(double avg)
    {
        avgScore = avg;
    }
    // assigns the average score of s3 to the average of the other 2 object's average scores
    void s3Avg(Student s1, Student s2)
    {
        double s3AvgScore = (s1.getAvg() + s2.getAvg()) / 2;
        setAvgScore(s3AvgScore);
    }
    // returns the average score
    double getAvg()
    {
        return avgScore;
    }
};

// compares the average scores of s1 and s2, and displays which one is bigger
void biggerAvg(Student &s1, Student &s2)
{
    if (s1.getAvg() > s2.getAvg())
    {
        cout << "Student 1 has a higher average score than student 2 \n";
    }

    else if (s1.getAvg() < s2.getAvg())
    {
        cout << "Student 1 has a lower average score than student 2 \n";
    }

    else
    {
        cout << "Student 1 has the same average score as student 2 \n";
    }
}

int main()
{
    Student s1, s2, s3;
    s1.setScore(77, 81);
    s2.setScore(70, 93);
    biggerAvg(s1, s2);
    s3.s3Avg(s1, s2);
    cout << s3.getAvg() << "\n";

    return 0;
}