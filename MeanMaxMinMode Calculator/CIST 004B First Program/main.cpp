//
//  main.cpp
//  Min Max Mean Median Mode
//
//  Created by Cole Roberts on 1/31/23.
//

#include <iostream>
#include <vector>

using namespace std;

bool inputinvalid (int &input, int lowlim, int upperlim){
    cin.clear();
    cin >> input;
    if(cin.fail() or input > upperlim or input < lowlim){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input.\n";
        return true;
    }
    return false;
}

int main(){
    
    cout << "Cole J Roberts\t\tCIST004B Spring 2023\n\nMinimum, Maximum, Mean, Median and Mode Calculator\nwith extra polish and multimodal support.\n\n";
    
    int numinput{0};
    do {
        cout << "How many numbers are in your list (1 to 100)? ";
        if (inputinvalid(numinput, 1, 100)){
            numinput = -1;
        }
    } while (numinput < 1 or numinput > 100);
    
    vector<int> input(numinput);
    int userinput{};
    cout << "\nYour list may have numbers between 1 and 1000.\n";
    for(int x = 1; x < numinput+1; ++x){
        cout << "Enter the " << x;
        switch(x){
            case 1:
                if(x == 11) cout << "nth number: ";
                else cout << "st number: ";
                break;
            case 2:
                if(x == 12) cout << "th number: ";
                else cout << "nd number: ";
                break;
            case 3:
                if(x == 13) cout << "th number: ";
                else cout << "rd number: ";
                break;
            default:
                cout << "th number: ";
                break;
        }
        if (inputinvalid(userinput, 1, 1000)) {
            cout << "Please enter a valid number between 1 and 1000!\n";
            --x;
            continue;
        }
        input[x-1] = userinput;
    }
    
    sort(input.begin(), input.end());
    float mean {0.0F};
    for (auto a : input){
        mean += static_cast<float>(a);
    }
    mean /= numinput;
    
    int modes {0};
    vector <int> counter(input[numinput-1], 0);
    vector <int> mode;
    int maxfreq {0};
    for (auto a : input){
        counter[a] += 1;
        if (counter[a] == maxfreq){
            modes += 1;
            mode.emplace_back(a);
        } else if (counter[a] > maxfreq){
            maxfreq = counter[a];
            modes = 1;
            mode.clear();
            mode.emplace_back(a);
        }
    }
    
    int median = input[static_cast<int>( (numinput-1) / 2)];
    
    cout << "The list of numbers entered has the following characteristics:\nThe Minimum is: " << input[0] << "\nThe Maximum is: " << input[numinput-1] << "\nThe Mean is: " << mean << "\nThe Median is: " << median << "\n";
    
    if(modes > 1){
        cout << "This list is multimodal. ";
    }
    cout << "There are " << modes << " modes. The modes are: ";
    for(int x = 0; x < modes-1; x++){
        cout << mode[x] << ", ";
    }
    cout << "and " << mode[modes-1] << endl;
    
    return 0;
}
