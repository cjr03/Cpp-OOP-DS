//
//  HealthRecordClass.hpp
//  Project
//
//  Created by Cole Roberts on 11/29/22.
//

#ifndef HealthRecordClass_hpp
#define HealthRecordClass_hpp

#include <stdio.h>
#include <string>
#include <fstream>


class HealthRecord {
private:
    std::string name;
    int height;
    int weight;
public:
    HealthRecord(std::string inputname = "", int inputheight = 1, int inputweight = 0);
    ~HealthRecord(){};
    void setName(std::string inputname);
    std::string getName();
    void setWeight(int inputweight);
    int getWeight();
    void setHeight(int inputheight);
    int getHeight();
    float computeBMI();
    void outputCSV(std::ofstream& outfile);
};

#endif /* HealthRecordClass_hpp */
