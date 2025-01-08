#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

// Helper function to split a string by a delimiter
vector<string> split(const string& line, char delimiter) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to load CSV into memory
bool loadCSV(const string& filename, vector<vector<string>>& data, unordered_map<string, int>& indexMap) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'\n";
        return false;
    }

    string line;
    int rowIndex = 0;

    // Read header
    if (getline(file, line)) {
        data.push_back(split(line, ',')); // Save header as the first row
    }

    // Read rows
    while (getline(file, line)) {
        vector<string> row = split(line, ',');
        if (!row.empty()) {
            data.push_back(row);
            // Map the first column (primary key) to its row index
            indexMap[row[0]] = rowIndex + 1; // +1 to account for the header
        }
        rowIndex++;
    }

    file.close();
    return true;
}

// Function for exact search
void exactSearch(const unordered_map<string, int>& indexMap, const vector<vector<string>>& data, const string& key) {
    if (indexMap.find(key) != indexMap.end()) {
        int rowIndex = indexMap.at(key);
        for (const auto& value : data[rowIndex]) {
            cout << value << " ";
        }
        cout << "\n";
    } else {
        cout << "No exact match found for key: " << key << "\n";
    }
}

// Main function
int main() {
    string filename = "data.csv";
    vector<vector<string>> data;
    unordered_map<string, int> indexMap;

    if (!loadCSV(filename, data, indexMap)) {
        return 1;
    }

    cout << "CSV loaded successfully!\n";

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Exact Search\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key for exact search: ";
            string key;
            cin >> key;
            exactSearch(indexMap, data, key);
        } else if (choice == 2) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
