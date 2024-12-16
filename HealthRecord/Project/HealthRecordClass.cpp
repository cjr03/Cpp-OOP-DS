//
//  HealthRecordClass.cpp
//  Project
//
//  Created by Cole Roberts on 11/29/22.
//

#include "HealthRecordClass.hpp"
#include <iostream>

HealthRecord::HealthRecord(std::string inputname, int inputheight, int inputweight){
    name = inputname;
    weight = inputweight;
    height = inputheight;
}

void HealthRecord::setName(std::string inputname){
    name = inputname;
    return;
}

std::string HealthRecord::getName(){
    return name;
}

void HealthRecord::setWeight(int inputweight){
    weight = inputweight;
    return;
}

int HealthRecord::getWeight(){
    return weight;
}

void HealthRecord::setHeight(int inputheight){
    height = inputheight;
    return;
}

int HealthRecord::getHeight(){
    return height;
}

float HealthRecord::computeBMI (){
    return static_cast<float>((weight*0.453592F)/(height*height*0.00064516F));
}

void HealthRecord::outputCSV(std::ofstream& outfile){
    outfile << std::fixed << std::setprecision(2);
    outfile << getName() << ',';
    outfile << getHeight() << ',';
    outfile << getWeight() << ',';
    outfile << computeBMI() << '\r' << '\n';
    return;
}


