
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // Read args to vector
    vector<char*> argList;
    for (int i = 0; i < argc; i++) {
        argList.insert(argList.begin(),static_cast<char*>(argv[i]));
    }
    
    // Check if user needs help
    for (int i = 0; i < argList.size(); i++) {
        if ( !strncmp(argList.at(i),"-h",2) || !strncmp(argList.at(i),"--help",6) ) {
            cout << "User needs help" << endl;
        }
    }
}
