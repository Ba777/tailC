
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// -------- Helper funcitons


bool isNumber(const string& inString){
    cout << inString << endl;
    for (int i = 0; i < inString.size(); i++) {
        if ( (int)inString.at(i) > 9 ) {
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
    
    cout << "Args: " << endl;
    for (int i = 0; i < argVector.size(); i++) {
        cout << argVector.at(i) << endl;
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
//            argVector.erase(argVector.begin()+i);
        }
    }
    
    // Rest of args are filepaths.
    filePaths = argVector;
    
//    for (int i = 0; i < filePaths.size(); i++) {
//        <#statements#>
//    }
}
