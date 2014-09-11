
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int nrOfLines = 25;
    vector<char*> filePaths;
    
    // Read args to vector
    vector<char*> argVector;
    for (int i = 0; i < argc; i++) {
        argVector.insert(argVector.begin(),static_cast<char*>(argv[i]));
    }
    
    // Check if user needs help
    for (int i = 0; i < argVector.size(); i++) {
        if ( !strncmp(argVector.at(i),"-h",2) || !strncmp(argVector.at(i),"--help",6) ) {
            argVector.erase(argVector.begin()+i);
            cout << "User needs help" << endl;
        }
    }
    
    // Check for if nr of lines are given.
    for (int i = 0; i < argVector.size(); i++) {
        if (!strncmp(argVector.at(i),"-n",2)) {
            // Remove -n from args
            argVector.erase(argVector.begin()+i);
            // Get nrOfLines
            nrOfLines = atoi(argVector.at(i));
            // Remove nrOfLines from args
            argVector.erase(argVector.begin()+i);
        }
    }
    
    // Rest of args are filepaths.
    filePaths = argVector;
    delete argVector;
    
    for (int i = 0; i < filePaths.size(); i++) {
        <#statements#>
    }
}
