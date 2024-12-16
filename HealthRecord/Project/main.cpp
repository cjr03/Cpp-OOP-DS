//
//  main.cpp
//  Project
//
//  Created by Cole Roberts on 9/6/22.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "HealthRecordClass.hpp"

using namespace std;

int main() {
    string name, fname, input;
    int height {0}, weight {0};
    vector <HealthRecord*> records (10);
    cout << "Cole Roberts \t CIST 004A \t Health Record \n\n";
   
    for(int numrecords = 0; numrecords <= 9; ++numrecords){
        cout << "Health Record #" << numrecords+1 << "\nInput the name: ";
        getline(cin, name);
        cout << "Input the height in inches: ";
        cin >> height;
        cin.ignore(1000, '\n');
        cout << "Input the weight in pounds: ";
        cin >> weight;
        cin.ignore(1000, '\n');
        cout << "\n";
        records[numrecords] = new HealthRecord(name, height, weight);
        }
    
    do{
        cout << "\nEnter a new file name to create: ";
        getline(cin, fname);
        if (fstream(fname)){
            cout << "The file """ << fname << """ already exists.\n";
            continue;
        }
        ofstream myfile (fname);
        if (myfile){
            cout << "The file: \"" << fname << "\" was successfully written.\n";
            for(int numrecords = 0; numrecords < 10; ++numrecords){
                records[numrecords]->outputCSV(myfile);
            }
            cout << "The file was written.\n";
            break;
        } else {
            cout << "File could not be opened.\n";
        }
    } while(true);
    
    streampos begin, end;
    ifstream myfile (fname, ios::binary | ios::in);
    begin = myfile.tellg();
    myfile.seekg (0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "The file: \"" << fname << "\" is: " << (end-begin) << " bytes.\n\nEnter the final Health Record:\nInput the name: ";
        getline(cin, name);
    cout << "Input the height in inches: ";
        cin >> height;
    cin.ignore(1000, '\n');
    cout << "Input the weight in pounds: ";
        cin >> weight;
    cin.ignore(1000, '\n');
    cout << "\n";
    {
    ofstream myfile (fname, ios::app);
    HealthRecord(name, height, weight).outputCSV(myfile);
    myfile.close();
    }
    myfile.open(fname, ios::binary | ios::in);
    begin = myfile.tellg();
    myfile.seekg (0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "The file: \"" << fname << "\" is now: " << (end-begin) << " bytes.\n\n";
    
    

    return 0;
}
