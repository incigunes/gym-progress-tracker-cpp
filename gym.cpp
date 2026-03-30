#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct WorkoutRecord {
    string exerciseName;
    float weight;
    int reps;
    int sets;
    string date;
};

vector<WorkoutRecord> records;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void showMenu() {
    cout << "\n===== Gym Progress Tracker =====\n";
    cout << "1. Add workout record\n";
    cout << "2. View all records\n";
    cout << "3. Search by exercise name\n";
    cout << "4. Show personal best\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void addRecord() {
    WorkoutRecord record;

    cin.ignore();

    cout << "Enter exercise name: ";
    getline(cin, record.exerciseName);

    cout << "Enter weight (kg): ";
    cin >> record.weight;

    cout << "Enter reps: ";
    cin >> record.reps;

    cout << "Enter sets: ";
    cin >> record.sets;

    cin.ignore();
    cout << "Enter date (DD/MM/YYYY): ";
    getline(cin, record.date);

    records.push_back(record);

    cout << "Workout record added successfully!\n";
}

void viewRecords() {
    if (records.empty()) {
        cout << "No workout records found.\n";
        return;
    }

    cout << "\n===== Workout Records =====\n";

    for (size_t i = 0; i < records.size(); i++) {
        cout << "\nRecord " << i + 1 << ":\n";
        cout << "Exercise: " << records[i].exerciseName << endl;
        cout << "Weight: " << records[i].weight << " kg" << endl;
        cout << "Reps: " << records[i].reps << endl;
        cout << "Sets: " << records[i].sets << endl;
        cout << "Date: " << records[i].date << endl;
    }
}

void searchRecord() {
    if (records.empty()) {
        cout << "No workout records found.\n";
        return;
    }

    string searchName;
    bool found = false;

    cin.ignore();
    cout << "Enter exercise name to search: ";
    getline(cin, searchName);

    for (size_t i = 0; i < records.size(); i++) {
        if (toLower(records[i].exerciseName) == toLower(searchName)) {
            cout << "\nExercise found:\n";
            cout << "Exercise: " << records[i].exerciseName << endl;
            cout << "Weight: " << records[i].weight << " kg" << endl;
            cout << "Reps: " << records[i].reps << endl;
            cout << "Sets: " << records[i].sets << endl;
            cout << "Date: " << records[i].date << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching exercise found.\n";
    }
}

void showPersonalBest() {
    if (records.empty()) {
        cout << "No workout records found.\n";
        return;
    }

    string exerciseName;
    bool found = false;
    float maxWeight = 0;

    cin.ignore();
    cout << "Enter exercise name: ";
    getline(cin, exerciseName);

    for (size_t i = 0; i < records.size(); i++) {
        if (toLower(records[i].exerciseName) == toLower(exerciseName)) {
            if (!found || records[i].weight > maxWeight) {
                maxWeight = records[i].weight;
                found = true;
            }
        }
    }

    if (found) {
        cout << "Personal best for " << exerciseName << ": " << maxWeight << " kg\n";
    } else {
        cout << "No records found for this exercise.\n";
    }
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                showPersonalBest();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}