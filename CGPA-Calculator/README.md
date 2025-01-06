# CGPA Calculator

This C++ program calculates the GPA for the current semester and the cumulative CGPA for a student based on the input of multiple courses. It uses classes to encapsulate the data and functionality.

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Code Explanation](#code-explanation)
   - [Course Class](#course-class)
   - [Student Class](#student-class)
   - [Main Function](#main-function)
4. [How to Run](#how-to-run)
5. [Screenshots](#screenshots)
6. [Conclusion](#conclusion)

## Introduction

The CGPA Calculator is designed to help students calculate their GPA for a given semester and their cumulative CGPA based on the grades and credits of each course they have taken.

## Features

- Allows the input of multiple courses with their respective credits and grade points.
- Calculates the GPA for the current semester.
- Calculates the cumulative CGPA across all semesters.
- Displays a summary of all entered courses.

## Code Explanation

### Course Class

The `Course` class represents a single course with the following attributes:
- `courseName`: The name of the course.
- `credits`: The number of credits for the course.
- `gradePoints`: The grade points earned in the course.

**Methods:**
- Constructor to initialize the course attributes.
- Getters to retrieve course details.

### Student Class

The `Student` class manages a list of `Course` objects and tracks cumulative grade points and credits.

**Attributes:**
- `courses`: A vector to store multiple courses.
- `cumulativeGradePoints`: Total grade points across all semesters.
- `cumulativeCredits`: Total credits across all semesters.

**Methods:**
- `addCourse()`: Adds a course to the student's record.
- `calculateGPA()`: Calculates GPA for the current semester.
- `calculateCGPA()`: Calculates cumulative CGPA.
- `displayCourses()`: Displays details of all courses.

### Main Function

The `main()` function orchestrates the program's execution:
1. Prompts the user to enter the number of courses.
2. Loops to collect course details and adds each course to the student record.
3. Displays all entered courses.
4. Calculates and displays the GPA and CGPA.

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/C++-Basic-Projects.git

