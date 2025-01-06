#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Class to represent a single course
class Course {
private:
    string courseName;
    int totalMarks;
    int obtainedMarks;

public:
    // Constructor
    Course(string name, int total, int obtained)
        : courseName(name), totalMarks(total), obtainedMarks(obtained) {}

    // Getters
    int getCredits() const { return totalMarks / 10; } // Assume 10 marks = 1 credit
    double getGradePoints() const { return (obtainedMarks / (double)totalMarks) * getCredits() * 4.0; }
    string getCourseName() const { return courseName; }
    int getTotalMarks() const { return totalMarks; }
    int getObtainedMarks() const { return obtainedMarks; }
};

// Class to represent a student
class Student {
private:
    vector<Course> courses; // List of courses for the current semester
    double previousCGPA;
    int previousCredits;

public:
    // Constructor to initialize previous CGPA and credits
    Student(double cgpa, int credits) : previousCGPA(cgpa), previousCredits(credits) {}

    // Add a course to the student's record
    void addCourse(const Course &course) {
        courses.push_back(course);
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

    // Calculate new CGPA
    double calculateCGPA() {
        double currentGPA = calculateGPA();
        int currentCredits = 0;
        for (const auto &course : courses) {
            currentCredits += course.getCredits();
        }
        double totalGradePoints = (previousCGPA * previousCredits) + (currentGPA * currentCredits);
        int totalCredits = previousCredits + currentCredits;

        return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
    }

    // Display details of all courses
    void displayCourses() {
        cout << "\nCourses Details:\n";
        cout << left << setw(20) << "Course Name" << setw(15) << "Total Marks" << setw(15) << "Obtained Marks" << endl;
        for (const auto &course : courses) {
            cout << left << setw(20) << course.getCourseName() << setw(15) << course.getTotalMarks() << setw(15) << course.getObtainedMarks() << endl;
        }
    }
};

int main() {
    double previousCGPA;
    int previousCredits;

    cout << "Enter your previous CGPA: ";
    cin >> previousCGPA;
    cout << "Enter your total credits from previous semesters: ";
    cin >> previousCredits;

    Student student(previousCGPA, previousCredits);
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        string courseName;
        int totalMarks;
        int obtainedMarks;

        cout << "\nEnter details for course " << (i + 1) << ":\n";
        cout << "Course Name: ";
        cin.ignore(); // To handle newline from previous input
        getline(cin, courseName);
        cout << "Total Marks: ";
        cin >> totalMarks;
        cout << "Obtained Marks: ";
        cin >> obtainedMarks;

        // Add course to student's record
        student.addCourse(Course(courseName, totalMarks, obtainedMarks));
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
