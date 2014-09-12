
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

// -------- Helper funcitons


void printHelp(){
    cout << endl;
    cout << "Usage:" << endl;
    cout << "   ./tailC [-n NR] FILENAME" << endl;
    exit(1);
}

// ------------


bool isNumber(const string& inString){
    for (int i = 0; i < inString.size(); i++) {
        if ( (int)inString.at(i) < 48 || (int)inString.at(i) > 57 ) {
            return false;
        }
    }
    
    return true;
}

// -------------------------

int main(int argc, char *argv[])
{
    int nrOfLines = 25;
    vector<string> filePaths;
    
    // Read args to vector
    vector<string> argVector;
    for (int i = 1; i < argc; i++) {
        argVector.push_back(static_cast<string>(argv[i]));
    }
    
    // Check if user needs help
    for (int i = 0; i < argVector.size(); i++) {
        if ( argVector.at(i) == "-h" || argVector.at(i) == "--help" ) {
            argVector.erase(argVector.begin()+i);
            printHelp();
        }
    }
    
    // Check for if nr of lines are given.
    for (int i = 0; i < argVector.size(); i++) {
        if ( argVector.at(i) == "-n" ) {
            // Get nrOfLines - need to find an exception if char isn't a number
            if ( isNumber(argVector.at(i+1)) ) {
                nrOfLines = atoi(argVector.at(i+1).c_str());
            }
            else {
                cout << "Argument after '-n' needs to be a valid number." << endl;
                exit(2);
            }
            // Remove nrOfLines from args
            argVector.erase(argVector.begin()+i);
            argVector.erase(argVector.begin()+i);
        }
    }
    
    // Rest of args are filepaths.
    filePaths = argVector;
    
    // If we have no filepaths - print help.
    if ( filePaths.size() == 0) {
        printHelp();
    }
    
    for (int i = 0; i < filePaths.size(); i++) {
        // Read file
        ifstream readFile(filePaths.at(i));
        vector<string> fileContent;
        
        if ( readFile.is_open() ) {
            string line;
            
            while ( getline(readFile,line) ) {
                fileContent.push_back(line);
            }
            
            // Indenting output
            if (filePaths.size() > 1) {
                cout << "----- " << filePaths.at(i) << " -----" << endl;
            }
            // Print file
            int it = 0;
            while ( it < nrOfLines && !fileContent.empty()) {
                cout << fileContent.front() << endl;
                fileContent.erase(fileContent.begin()+0);
                it++;
            }
            if (filePaths.size() > 1) {
                cout << endl;           // Indenting output
            }
        }
        
        else {
            cout << filePaths[i] << " is not a valid filepath" << endl;
        }
    }
}






