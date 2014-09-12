
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// -------- Helper funcitons


void printHelp(){
    cout << endl;
    cout << "Usage:" << endl;
    cout << "   ./tailC [-n NR] FILENAME" << endl;
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
    for (int i = 0; i < argc; i++) {
        argVector.insert(argVector.begin(),static_cast<string>(argv[i]));
    }
    
    // Check if user needs help
    for (int i = 0; i < argVector.size(); i++) {
        if ( argVector.at(i) == "-h" || argVector.at(i) == "--help" ) {
            argVector.erase(argVector.begin()+i);
            cout << "User needs help" << endl;
        }
    }
    
    // Check for if nr of lines are given.
    for (int i = 0; i < argVector.size(); i++) {
        if ( argVector.at(i) == "-n" ) {
            // Get nrOfLines - need to find an exception if char isn't a number
            if ( isNumber(argVector.at(i-1)) ) {
                nrOfLines = atoi(argVector.at(i-1).c_str());
            }
            else {
                cout << "Parameter after '-n' needs to be a valid number." << endl;
            }
            // Remove nrOfLines from args
            argVector.erase(argVector.begin()+i);
            argVector.erase(argVector.begin()+i-1);
        }
    }
    
    // Rest of args are filepaths.
    filePaths = argVector;
    
    if ( filePaths.size() == 0) {
        printHelp();
    }
    
    for (int i = 0; i < filePaths.size(); i++) {
        ifstream readFile(filePaths.at(i));
        vector<string> fileContent;
        
        if ( readFile.is_open() ) {
            string line;
            i = 0;
            
            while ( getline(readFile,line) ) {
                fileContent[i] = line;
                i++;
            }
            // Print
            for (int i = fileContent.size()-1; i >= 0; i--) {
                cout << fileContent[i] << endl;
            }
        }
        
        else {
            cout << filePaths[i] << " is not a valid filepath" << endl;
        }
    }
}






