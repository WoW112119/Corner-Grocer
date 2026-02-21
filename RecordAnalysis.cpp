#include "RecordAnalysis.h"
#include <iomanip>

using namespace std;

// Constructor: Executes data loading and backup immediately
RecordAnalysis::RecordAnalysis(const string& inputFilename) {
    loadInitialData(inputFilename);
    writeBackupFile("frequency.dat");
}

// Logic to read the text records and populate the frequency map
void RecordAnalysis::loadInitialData(const string& filename) {
    ifstream inputFile(filename);
    string currentItem;

    if (inputFile.is_open()) {
        while (inputFile >> currentItem) {
            itemFrequencyMap[currentItem]++; // Increment count for each purchase
        }
        inputFile.close();
    }
    else {
        // Specifically addresses the professor's warning about file locations
        cerr << "Critical Error: Cannot find " << filename << " in the project directory." << endl;
    }
}

// Requirement: Automatically create frequency.dat for backup
void RecordAnalysis::writeBackupFile(const string& filename) {
    ofstream backupFile(filename);
    if (backupFile.is_open()) {
        for (auto it = itemFrequencyMap.begin(); it != itemFrequencyMap.end(); ++it) {
            // it->first is the Name, it->second is the Count
            backupFile << it->first << " " << it->second << endl;
        }
        backupFile.close();
    }
}

// Menu Option 1: Numeric search
void RecordAnalysis::findItemFrequency() {
    string searchTarget;
    cout << "Search Item: ";
    cin >> searchTarget;

    if (!searchTarget.empty()) {
        searchTarget[0] = toupper(searchTarget[0]);
        for (size_t i = 1; i < searchTarget.length(); ++i) {
            searchTarget[i] = tolower(searchTarget[i]);
        }
    }

    if (itemFrequencyMap.count(searchTarget)) {
        cout << searchTarget << " " << itemFrequencyMap[searchTarget] << endl;
    }
    else {
        cout << "Item not found in records." << endl;
    }
}

// Menu Option 2: Print full numeric list
void RecordAnalysis::printAllCounts() {
    // Standard iterator loop to avoid C3312/C2065 errors
    for (auto it = itemFrequencyMap.begin(); it != itemFrequencyMap.end(); ++it) {
        // Output format: ItemName Space Count
        cout << it->first << " " << it->second << endl;
    }
}

// Menu Option 3: Print visual histogram
void RecordAnalysis::printHistogram() {
    for (auto const& [item, count] : itemFrequencyMap) {
        cout << left << setw(12) << item << " ";
        for (int i = 0; i < count; ++i) {
            cout << "*"; // Represents frequency with special characters
        }
        cout << endl;
    }
}