#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// Base class for User
class User {
protected:
    string username;
    string password;

public:
    User(string uname, string pass) : username(uname), password(pass) {}
    virtual void display() const = 0; // Pure virtual function for polymorphism
};

// Derived class for storing user details during signup
class UserDetails : public User {
private:
    string fname;
    string lname;
    string email;
    string mobile;
    string location;

public:
    UserDetails(string uname, string pass, string fn, string ln, string mail, string mob, string loc)
        : User(uname, pass), fname(fn), lname(ln), email(mail), mobile(mob), location(loc) {}

    void display() const override {
        cout << left << setw(15) << username << setw(15) << fname << setw(15) << lname << setw(30) << email
             << setw(15) << mobile << setw(20) << location << endl;
    }

    string toCSV() const {
        return username + "," + password + "," + fname + "," + lname + "," + email + "," + mobile + "," + location;
    }
};

// Function to handle signup
void signup() {
    string username, password, fname, lname, email, mobile, location;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter First Name: ";
    cin >> fname;
    cout << "Enter Last Name: ";
    cin >> lname;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Mobile: ";
    cin >> mobile;
    cout << "Enter Location: ";
    cin >> location;

    UserDetails user(username, password, fname, lname, email, mobile, location);

    ofstream outfile("users.txt", ios::app);
    if (outfile.is_open()) {
        outfile << user.toCSV() << endl;
        outfile.close();
        cout << "Signup successful!" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

// Function to handle login
bool login() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string uname, pass;

            getline(ss, uname, ',');
            getline(ss, pass, ',');

            if (uname == username && pass == password) {
                infile.close();
                cout << "Login successful!" << endl;
                return true;
            }
        }
        infile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }

    cout << "Invalid username or password." << endl;
    return false;
}

// Function to display all user data (for admin purposes)
void displayAllUsers() {
    ifstream infile("users.txt");
    if (infile.is_open()) {
        string line;
        cout << left << setw(15) << "Username" << setw(15) << "First Name" << setw(15) << "Last Name"
             << setw(30) << "Email" << setw(15) << "Mobile" << setw(20) << "Location" << endl;
        cout << string(110, '-') << endl;
        while (getline(infile, line)) {
            stringstream ss(line);
            vector<string> fields;
            string field;
            while (getline(ss, field, ',')) {
                fields.push_back(field);
            }

            if (fields.size() == 7) {
                UserDetails user(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6]);
                user.display();
            }
        }
        infile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Signup\n2. Login\n3. Display All Users (Admin)\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            displayAllUsers();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
