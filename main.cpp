#include "RecordAnalysis.h"
#include <limits>

using namespace std;

int main() {
    // Instantiate the tracker with the required input file name
    RecordAnalysis tracker("CS210_Project_Three_Input_File.txt");
    int menuChoice = 0;

    // Standard menu loop
    while (menuChoice != 4) {
        cout << "\n--- Corner Grocer Analysis Menu ---" << endl;
        cout << "1. Item Search Frequency" << endl;
        cout << "2. Print List" << endl;
        cout << "3. Print Histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Make A Selection: ";

        // Optional Challenge: Input Validation
        if (!(cin >> menuChoice)) {
            cout << "Invalid selection. Please enter a numeric choice (1-4)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (menuChoice) {
        case 1: tracker.findItemFrequency(); break;
        case 2: tracker.printAllCounts(); break;
        case 3: tracker.printHistogram(); break;
        case 4: cout << "System exiting. Backup saved to frequency.dat." << endl; break;
        default: cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}