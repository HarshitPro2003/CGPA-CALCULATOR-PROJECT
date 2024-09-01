#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

// Function to calculate CGPA
double calculateCGPA(int numCourses) {
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 1; i <= numCourses; ++i) {
        double grade, credits;

        // Input validation for grade
        do {
            cout << "Enter grade for course " << i << " (0.0 - 4.0): ";
            cin >> grade;
            if (grade < 0.0 || grade > 4.0) {
                cout << "Invalid grade. Please enter a value between 0.0 and 4.0." << endl;
            }
        } while (grade < 0.0 || grade > 4.0);

        // Input validation for credits
        do {
            cout << "Enter credits for course " << i << ": ";
            cin >> credits;
            if (credits <= 0.0) {
                cout << "Invalid credits. Please enter a positive value." << endl;
            }
        } while (credits <= 0.0);

        totalGradePoints += grade * credits;
        totalCredits += credits;
    }

    if (totalCredits == 0.0) {
        cout << "Error: Total credits cannot be zero." << endl;
        return 0.0;
    }

    return totalGradePoints / totalCredits;
}

int main() {
    int numCourses;

    // Input validation for number of courses
    do {
        cout <<"\033[1;35m**Welcome to the CGPA Calculator**\033[0m" << endl;
        
        cout << "Enter the number of courses: ";
        cin >> numCourses;
        if (numCourses <= 0) {
            cout << "Invalid number of courses. Please enter a positive integer." << endl;
        }
    } while (numCourses <= 0);

    double cgpa = calculateCGPA(numCourses);

    // Set precision to 2 decimal places
    cout << fixed << setprecision(2);
    cout << "\033[1;34m Your CGPA is\033[0m: " << cgpa << endl;

    return 0;
}
