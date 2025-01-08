# Signup and Registration System

This C++ program implements a simple Signup and Registration system. It allows users to sign up with personal details, log in with a username and password, and displays all registered users information. The user data is stored in a text file (`users.txt`).

**Note**: Before running the program, ensure that a `users.txt` file exists in the same directory. This file will be used to store and retrieve user data during signup and login.

## Table of Contents

1. [Code Explanation](#code-explanation)
    - [User Class](#user-class)
    - [UserDetails Class](#userdetails-class)
    - [Functions](#functions)
    - [Main Function](#main-function)
2. [Sample Output](#sample-output)
3. [About Me](#about-me)

## Code Explanation

### User Class

The `User` class is a **base class** that defines two protected member variables:

- **username**: A string that holds the username of the user.
- **password**: A string that holds the password of the user.

This class also has a **pure virtual function** `display()`, which makes `User` an abstract class. This function is overridden in the `UserDetails` class to display the user's information.

### UserDetails Class

The `UserDetails` class inherits from the `User` class and contains additional personal information:

- **fname**: First name of the user.
- **lname**: Last name of the user.
- **email**: The email address of the user.
- **mobile**: Mobile number of the user.
- **location**: The location of the user.

#### Constructor
The constructor of `UserDetails` initializes all the variables using the parameters passed to it. This includes the data from the base `User` class (username and password) and the additional personal details.

#### `display()` Method
The `display()` method overrides the `display()` function from the base class. It prints the user details in a tabular format with proper alignment using the `setw` function to set the width of each column.

#### `toCSV()` Method
The `toCSV()` method converts the user details into a comma-separated string in the format:
`username,password,first_name,last_name,email,mobile,location`


This string is written into a file (`users.txt`) for storing the user data in a text file.

### Functions

#### `signup()`
The `signup()` function handles the registration process:

1. **Input**: It prompts the user to enter their username, password, first name, last name, email, mobile number, and location.
2. **Create UserDetails Object**: Once the data is entered, it creates a `UserDetails` object with the provided details.
3. **Store User Data**: The `toCSV()` method of the `UserDetails` object is called to generate a CSV string, which is appended to the `users.txt` file.

#### `login()`
The `login()` function checks if a user can log in by verifying the username and password:

1. **Input**: It prompts the user for their username and password.
2. **File Search**: The function opens the `users.txt` file and reads it line by line. For each line, it splits the data using the comma delimiter and checks if the username and password match any entry.
3. **Return**: If a match is found, it prints "Login successful!" and returns `true`. If no match is found, it prints "Invalid username or password" and returns `false`.

#### `displayAllUsers()`
This function displays all registered users' data in a tabular format (for admin purposes):

1. **File Reading**: It reads the `users.txt` file and splits each line into fields.
2. **Display**: It displays all user details in a structured format (username, first name, last name, email, mobile, and location) using the `display()` function of the `UserDetails` class.

### Main Function

The main function serves as the entry point for the program. It presents a menu to the user with four options:

1. **Signup**: Calls the `signup()` function to register a new user.
2. **Login**: Calls the `login()` function to authenticate a user.
3. **Display All Users**: Calls the `displayAllUsers()` function to show all registered users (for admin).
4. **Exit**: Exits the program.

The program runs in a loop until the user selects the exit option.

## Sample Output

![loginDemo](https://github.com/user-attachments/assets/aca8d4cb-f6eb-43b9-8a5a-d42f6801e7df)


## About Me

A passionate Computer Science student with an interest in software development, open-source projects, and learning new technologies.

### Contact Me
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/yourusername)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:your-email@example.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/yourprofile)
[![WhatsApp](https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://wa.me/yourphonenumber)


