#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Class to represent a single course
class Course {
private:
    string courseName;
    int credits;
    double gradePoints; // Grade points earned for this course

public:
    // Constructor
    Course(string name, int credit, double gradePoint)
        : courseName(name), credits(credit), gradePoints(gradePoint) {}

    // Getters
    int getCredits() const { return credits; }
    double getGradePoints() const { return gradePoints; }
    string getCourseName() const { return courseName; }
};

// Class to represent a student
class Student {
private:
    vector<Course> courses; // List of courses for the current semester
    double cumulativeGradePoints = 0.0; // Total grade points across all semesters
    int cumulativeCredits = 0; // Total credits across all semesters

public:
    // Add a course to the student's record
    void addCourse(const Course &course) {
        courses.push_back(course);
        cumulativeGradePoints += course.getGradePoints();
        cumulativeCredits += course.getCredits();
    }

    // Calculate GPA for the current semester
    double calculateGPA() {
        double totalGradePoints = 0.0;
        int totalCredits = 0;

        for (const auto &course : courses) {
            totalGradePoints += course.getGradePoints();
            totalCredits += course.getCredits();
        }

        return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
    }

    // Calculate CGPA
    double calculateCGPA() {
        return (cumulativeCredits > 0) ? (cumulativeGradePoints / cumulativeCredits) : 0.0;
    }

    // Display details of all courses
    void displayCourses() {
        cout << "\nCourses Details:\n";
        cout << left << setw(20) << "Course Name" << setw(10) << "Credits" << "Grade Points" << endl;
        for (const auto &course : courses) {
            cout << left << setw(20) << course.getCourseName() << setw(10) << course.getCredits() << course.getGradePoints() << endl;
        }
    }
};

int main() {
    Student student;
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        string courseName;
        int credits;
        double gradePoints;

        cout << "\nEnter details for course " << (i + 1) << ":\n";
        cout << "Course Name: ";
        cin.ignore(); // To handle newline from previous input
        getline(cin, courseName);
        cout << "Credits: ";
        cin >> credits;
        cout << "Grade Points: ";
        cin >> gradePoints;

        // Add course to student's record
        student.addCourse(Course(courseName, credits, gradePoints));
    }

    // Display all courses
    student.displayCourses();

    // Calculate and display GPA and CGPA
    double gpa = student.calculateGPA();
    double cgpa = student.calculateCGPA();

    cout << fixed << setprecision(2);
    cout << "\nGPA for the current semester: " << gpa << endl;
    cout << "Cumulative CGPA: " << cgpa << endl;

    return 0;
}

