//COMSC-210|Ethan Aylard|Final-pt-1
//IDE Used:Visual Studio

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

const bool debug = false;

int main (){
    map<string, int> airport;
    string tempStr;
    ifstream iFile;

    //Milestone 1: This code block opens the file and reads the data to the aiport map and displays it.
    iFile.open("210-final-1-FA25.txt");

    if (!iFile){
        cout << "File failed to open...\n";
        return -1;
    }

    if(debug){
        cout << "File Opened!\n";
    }

    while (!iFile.eof()){
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
    if(debug){
        cout << "end of the while loop\n";
    }


    }


    cout << "Airport Visitation Data:\n";
    for(auto data : airport){
        cout << "Airport Code: " << data.first << ": # visits: " << data.second << endl;
    }
    cout << endl;

    //Milestone 2:This code block will only display the airports with the highest traffic:
    int busiest_amount = 0;
    for (auto highest: airport){
        if(busiest_amount < highest.second){
            busiest_amount = highest.second;
            if(debug){
                cout << "New High:" << busiest_amount << endl;
            }
        }
    }

    cout << "Busiest Airport(s): count: " << busiest_amount << ":\n";
    for (auto busiest : airport){
        if (busiest.second == busiest_amount){
            cout << "Airport Code: " << busiest.first << ": # visits: " << busiest.second << endl;
        }
    }
    cout << endl;

    //Milestone 3: This code block will display only the airports that fall within two different ranges:
    int range_start = 0, range_end = 8;

    cout << "Airports within traffic range [" << range_start << ", " << range_end << "]:\n";
    for(auto traffic : airport){
        if (traffic.second > range_start && traffic.second < range_end){
            cout << "Airport Code: " << traffic.first << ": # visits: " << traffic.second << endl;
        }

    } 
    cout << endl;

    range_start = 10; range_end = 15;

    cout << "Airports within traffic range [" << range_start << ", " << range_end << "]:\n";
    for(auto traffic : airport){
        if (traffic.second > range_start && traffic.second < range_end){
            cout << "Airport Code: " << traffic.first << ": # visits: " << traffic.second << endl;
        }

    }
    cout << endl;



    return 1;
}