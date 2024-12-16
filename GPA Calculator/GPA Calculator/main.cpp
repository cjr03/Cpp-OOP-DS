//
//  main.cpp
//  GPA Calculator
//
//  Created by Cole Roberts on 9/14/22.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

float calculateMeanGPA (float totalGPApoints, float studentNumber) {
    float GPA = totalGPApoints / studentNumber;
    return GPA;
}

int main(int argc, const char * argv[]) {
    int studentNumber {0};
    float minGPA {4.0F}, maxGPA {0.0F}, studentGPA {0.0F}, totalGPApoints {0.0F}, meanGPA {0.0F};
    string inputStudentGPA;
    cout << "Cole Roberts \t \t CIST 004A \n \nStudent GPA Calculator. \nEnter valid GPAs (0.0 to 4.0). \nEnter ""EXIT"" to finish.\n\n";
    
    for(studentNumber = 0; studentNumber <= 1000; ++studentNumber){
                do {
                cout << "Enter student number " << studentNumber + 1 << "'s GPA (0.0 - 4.0): ";
                getline (cin, inputStudentGPA);
                if(inputStudentGPA == "EXIT"){
                    break;
                }
                stringstream (inputStudentGPA) >> studentGPA;
                if(studentGPA < 0.0F or studentGPA > 4.0F){
                    cout << "Invalid Input.\n";
                }
            } while ( studentGPA < 0.0F or studentGPA > 4.0F);
            if(inputStudentGPA == "EXIT"){
                break;
            }
            if(studentGPA < minGPA){
                minGPA = studentGPA;
            }
            if(studentGPA > maxGPA){
                maxGPA = studentGPA;
            }
            totalGPApoints += studentGPA;
        }
    
    meanGPA = calculateMeanGPA (totalGPApoints, studentNumber);
    
    if(studentNumber == 0){
        cout << "\nNo valid data entered, please rerun the program and enter valid data." << "\n\n";
    } else {
    cout << fixed << setprecision(3);
    cout << "\nThe mean GPA of the students is " << meanGPA << "\n";
    cout << "The maximum GPA of the students is " << maxGPA << "\n";
    cout << "The minimum GPA of the students is " << minGPA << "\n\n";
    }
    
    return 0;
}
