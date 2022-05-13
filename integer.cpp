// Copyright (c) 2022 Michael Clermont All rights reserved
//
// Created by: Michael Clermont
// Created on: May 2022
// This program is to record integers until the user ends it

#include <iostream>
#include <string>
#include <limits>

int main() {
    // this function is to record integers until the user ends it
    char userEnd;
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    int numbersEntered;

    // process & output
    while (true) {
        try {
            std::cout << "Enter a number to record: ";
            std::cin >> numbersEntered;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
                throw "error";
            }
            if (numbersEntered > 0) {
                positiveCount = positiveCount + 1;
            } else if (numbersEntered < 0) {
                negativeCount = negativeCount + 1;
            } else if (numbersEntered == 0) {
                zeroCount = zeroCount + 1;
            }
            std::cout <<
            "Do you want to end the program" <<
            "and get your results (Y/N (default N)): ";
            std::cin >> userEnd;
            if (std::cin.fail()) {
                std::cin.clear();
                throw "error";
            }
            if (userEnd == 'Y' || userEnd == 'y') {
                std::cout << "\nPositive numbers: "
                << positiveCount << ", negative numbers: "
                << negativeCount << ", zeros: " << zeroCount << std::endl;
                break;
            }
        } catch (const char* error) {
            std::cout << "\nInvalid input, try again." << std::endl;
            numbersEntered = 0;
            continue;
        }
    }
    std::cout << "\nDone." << std::endl;
}
