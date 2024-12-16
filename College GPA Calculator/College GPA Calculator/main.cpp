//
//  main.cpp
//  College GPA Calculator
//
//  Created by Cole Roberts on 9/20/22.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float credits (string creditIsolator, string inputCourse, float courseCredits, bool validInput) {
    for(char checker : creditIsolator){
        inputCourse.erase(remove(inputCourse.begin(), inputCourse.end(), checker), inputCourse.end());
    }
    if(inputCourse.length() > 0){
    courseCredits = stof(inputCourse);
    }
    if((courseCredits < 1.0F) or (courseCredits > 45.0F)){
        cout << "Invalid Credit Input.\n";
        validInput = false;
        return -1.0F;
    }else{
        return courseCredits;
    }
}

int main() {
    int courseNumber {0};
    float classGPA {0.0F}, finalGPA {0.0F}, courseGrade {-1.0F}, courseCredits {0.0F}, totalCourseCredits {0.0F};
    char letterGrade {' '}, letterGradeSign {' '};
    
    cout << "Cole Roberts\t\tCIST 004A\n\nAdvanced GPA Calculator\n\nTo calculate your GPA, enter each letter grade in \neither upper or lower case with an optional + or - then a ',' [comma]\nfollowed by the number of units for that course, then the [Return] \nkey. If you have no more grades to enter, enter [RETURN].\n";
    
    string creditIsolator = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~`!@#$%^&*()+-=_{}[]|<>?;:,";
    
    for (int loop = 0; loop <= 1000; ++loop){
        string inputCourse {};
        bool validInput {false};
        do {
            validInput = true;
            letterGrade = ' ';
            letterGradeSign = ' ';
            cout << "\nEnter letter grade followed by the credit number for course #" << courseNumber + 1 << " (enter [RETURN] to finish): ";
            getline(cin, inputCourse);
            inputCourse.erase(remove(inputCourse.begin(), inputCourse.end(), ' '), inputCourse.end());
            if (inputCourse.length() == 0) break;
            letterGrade = inputCourse[0];
            letterGrade = toupper(letterGrade);
            letterGradeSign = inputCourse[1];
            courseCredits = credits(creditIsolator, inputCourse, courseCredits, validInput);
            if(courseCredits == -1.0F){
                validInput = false;
            }
            switch (letterGrade){
                case 'A':
                    courseGrade = 4.0F;
                    break;
                case 'B':
                    courseGrade = 3.0F;
                    break;
                case 'C':
                    courseGrade = 2.0F;
                    break;
                case 'D':
                    courseGrade = 1.0F;
                    break;
                case 'F':
                    courseGrade = 0.0F;
                    break;
                default:
                    courseGrade = -1.0F;
                    validInput = false;
                    cout << "Invalid Grade Input.\n";
                    break;
            }
            switch (letterGradeSign){
                case '+':
                    if((letterGrade == 'A') or (letterGrade == 'F')){
                        cout << letterGrade << letterGradeSign << " is treated as an " << letterGrade << ".\n";
                    } else {
                    courseGrade += 0.3F;
                    }
                    break;
                case '-':
                    if(letterGrade == 'F'){
                        cout << letterGrade << letterGradeSign << " is treated as an " << letterGrade << ".\n";
                    } else {
                    courseGrade -= 0.3F;
                    }
                    break;
                case ',':
                    break;
                default:
                    cout << "Invalid Sign Input.\n";
                    validInput = false;
                    break;
                    
            }
        } while(validInput == false);
        if (inputCourse.length() == 0) {
            break;
        }
        classGPA += courseGrade*courseCredits;
        totalCourseCredits += courseCredits;
        courseGrade = 0.0F;
        courseCredits = 0.0F;
        ++courseNumber;
        }
    
    finalGPA = classGPA / totalCourseCredits;
    cout << "\nYour GPA for the "<< courseNumber << " valid courses entered is: " << fixed << setprecision (3) << finalGPA << endl;
    
    return 0;
}
