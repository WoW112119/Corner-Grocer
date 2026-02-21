#ifndef RECORD_ANALYSIS_H
#define RECORD_ANALYSIS_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class RecordAnalysis {
private:
    // map to store item frequencies: key is item name, value is count
    std::map<std::string, int> itemFrequencyMap;

    // Internal helper methods for file management
    void loadInitialData(const std::string& filename);
    void writeBackupFile(const std::string& filename);

public:
    // Constructor handles automated startup tasks
    RecordAnalysis(const std::string& inputFilename);

    // Public interface for menu options
    void findItemFrequency();
    void printAllCounts();
    void printHistogram();
};

#endif
