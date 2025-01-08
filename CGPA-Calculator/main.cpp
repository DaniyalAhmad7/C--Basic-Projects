#include <iostream>
#include <vector>
#include <iomanip>     //Used for Input and Output Formatting
using namespace std;

// Class to represent a single course
class Course {
private:
    string courseName;
    int totalMarks;
    int obtainedMarks;

public:
    Course(string name, int total, int obtained)
        : courseName(name), totalMarks(total), obtainedMarks(obtained) {}

    // Getters 
    int getCredits() const { return totalMarks / 10; }           // Represents the weight or importance of the course based on total marks.
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

public:
    // Constructor to initialize previous CGPA
    Student(double cgpa) : previousCGPA(cgpa) {}

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
        /*
        This can also be written as 
                if (totalCredits > 0) {
                return totalGradePoints / totalCredits;  // Calculate GPA
                } else {
                return 0.0;  // No courses, so return GPA as 0.0
                }
        */
    }

    // Calculate new CGPA
    double calculateCGPA() {
        double currentGPA = calculateGPA();
        return (previousCGPA + currentGPA) / 2.0; // Simplified CGPA calculation
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

    cout << "Enter your previous CGPA: ";
    cin >> previousCGPA;

    if (previousCGPA < 0.0 || previousCGPA > 4.0) {
        cout << "Error: CGPA must be between 0.0 and 4.0.\n";
        return 1;
    }

    Student student(previousCGPA);
    int numCourses;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    if (numCourses <= 0 || numCourses > 10) {
        cout << "Error: Invalid number of courses\n";
        return 1;
    }

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
        if (totalMarks <= 0 || totalMarks >= 300) {
            cout << "Error: Invalid number of marks\n";
            return 1;
        }

        cout << "Obtained Marks: ";
        cin >> obtainedMarks;
        if (obtainedMarks < 0 || obtainedMarks > totalMarks) {
            cout << "Error: Invalid obtained marks.\n";
            return 1;
        }

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
