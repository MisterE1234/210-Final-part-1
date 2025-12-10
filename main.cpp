//COMSC-210|Ethan Aylard|Final-pt-1
//IDE Used:Visual Studio

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

const bool debug = true;

int main (){
    map<string, int> airport;
    string tempStr;
    ifstream iFile;

    iFile.open("210-final-1-FA25.txt");

    if (!iFile){
        cout << "File failed to open...\n";
        return -1;
    }

    if(debug){
        cout << "File Opened!\n";
    }

    while (iFile.eof()){
    iFile >> tempStr;

    if(debug){
        cout << tempStr << endl;
    }
    auto search = airport.find(tempStr);

    if(search != airport.end()){
        search->second++;
        if(debug){
            cout << "Increasing " << tempStr << " count\n";
        }
    }
    else{
        airport[tempStr] = {1};
        if(debug){
            cout << "New Airport: " << tempStr << endl;
        }
    }


    }

    for(auto data : airport){
        
    }




    return 1;
}