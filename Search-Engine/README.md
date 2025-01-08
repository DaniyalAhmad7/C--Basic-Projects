# Search Engine Project

This project is a simple search engine implemented in C++. It loads a CSV file into memory and allows the user to perform exact searches on the data using a key. The program utilizes an unordered map to efficiently map primary keys to their respective row indices for quick lookup.

## Features

- Loads data from a CSV file into memory.
- Allows exact search based on a primary key.
- Efficient lookup using an unordered map.
- Interactive menu for performing searches and exiting the program.

## Table of Contents
1. [Data Loading and Storage](#data-loading-and-storage)
2. [Search Functionality](#search-functionality)
3. [Code Explanation](#code-explanation)
    - [Helper Functions](#helper-functions)
    - [Main Function](#main-function)
4. [Sample Output](#sample-output)
5. [About Me](#about-me)

## Data Loading and Storage

The program reads data from a CSV file, storing it in a 2D vector. An unordered map is used to associate each primary key (first column of the CSV) with its corresponding row index, enabling quick and efficient exact searches.

## Search Functionality

The search engine supports exact searches, where the user provides a key to look up. The program retrieves and displays the entire row of data associated with the key if a match is found. If no match is found, an appropriate message is displayed.

## Code Explanation

### Helper Functions

- **`split(const string& line, char delimiter)`**:
    - This function takes a string and a delimiter character as inputs.
    - It splits the string into multiple substrings based on the delimiter.
    - The function returns a vector containing all the substrings (tokens).
    - It's used to parse each line of the CSV file into individual fields.

- **`loadCSV(const string& filename, vector<vector<string>>& data, unordered_map<string, int>& indexMap)`**:
    - Opens the specified CSV file for reading.
    - Reads the header line and stores it as the first row in the `data` vector.
    - Iterates over each subsequent line, splitting it into fields and storing it in the `data` vector.
    - Maps the first field of each row (assumed to be a unique primary key) to its corresponding row index in the `indexMap`.
    - Returns `true` if the file is loaded successfully, or `false` if there's an error opening the file.

- **`exactSearch(const unordered_map<string, int>& indexMap, const vector<vector<string>>& data, const string& key)`**:
    - Takes the `indexMap`, `data`, and a search `key` as inputs.
    - Checks if the `key` exists in `indexMap`.
    - If found, retrieves the corresponding row index and prints the entire row from `data`.
    - If not found, outputs a message indicating no match was found.

### Main Function

- **Initialization**:
    - Defines the filename (`data.csv`), a 2D vector (`data`) to store the CSV content, and an unordered map (`indexMap`) for fast lookups.

- **Loading the CSV**:
    - Calls `loadCSV()` to read and load the data into memory.
    - Displays a success message if the CSV is loaded correctly.

- **Interactive Menu**:
    - Presents a simple menu with two options: Exact Search and Exit.
    - Reads the user's choice and executes the corresponding action.
    - For Exact Search, prompts the user to enter a key and calls `exactSearch()` to perform the search.
    - Loops until the user chooses to exit the program.

The program is designed to efficiently handle exact searches in large CSV files by leveraging an unordered map for quick key-to-row index mapping.




## Sample Output



## About Me

A passionate Computer Science student with an interest in software development, open-source projects, and learning new technologies.

### Contact Me
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/yourusername)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:your-email@example.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/yourprofile)
[![WhatsApp](https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://wa.me/yourphonenumber)


