//
//  main.cpp
//  HeightProgram
//
//  Created by Cole Roberts on 9/11/22.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float height, weight, BMI;
    cout << "Cole Roberts \t \t CIST 004A \n \n";
    
    do{
        cout << "Input Height in Inches between 20 and 100: ";
        cin >> height;
        if (height < 20.0F or height > 100.0F){
            cout << "\nInvalid Input\n\n";
        }
    } while ( height < 20.0F or height > 100.0F);
    
    do{
        cout << "Input Weight in Pounds between 20 and 600:: ";
        cin >> weight;
        if ( height < 20.0F or weight > 600.0F){
            cout << "\nInvalid Input\n\n";
        }
    } while ( height < 20.0F or weight > 600.0F);
    
    height *= 0.0254F;
    weight /= 2.2046F;
    BMI = weight / (height*height);
    
    if(height <= 1.5F) {cout << "Wow you are short!\n";}
    if(weight >= 135.0F) {cout << "Wow you are heavy!\n";}
    
    cout << "\nYour height in M's is: " << height << "\n";
    cout << "Your weight in KG's is: " << weight << "\n";
    cout << "Your BMI is: " << BMI << "\n";
    
    if(BMI < 18.5F){
        cout << "\nYou are underweight.\n";
    }else if(BMI < 25.0F){
        cout << "\nYou are normal weight.\n";
    }else if(BMI < 30.0F){
        cout << "\nYou are overweight.\n";
    }else if(BMI < 35.0F){
        cout << "\nYou are obese.\n";
    } else {
        cout << "\nYou are extremely obese.\n";
    }
    
    double test1 = 1.0;
    float test2 = 1.0F;
    long double test3 = 1.0L;
    test1 /= 3.0;
    test2 /= 3.0F;
    test3 /= 3.0L;
    
    cout << setprecision(25.0F);
    cout << "\nexpected result:     0.3333333333333333333333333\n";
    cout << "double result:       "  << test1 << "\n";
    cout << "float result:        "  << test2 << "\n";
    cout << "long double result:  " <<  test3 << "\n\n";
    
    return 0;
}
