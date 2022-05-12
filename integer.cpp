// Copyright (c) 2022 Michael Clermont All rights reserved
//
// Created by: Michael Clermont
// Created on: May 2022
// This program is to record integers until the user ends it

#include <iostream>
#include <string>

int main() {
    // this function is to record integers until the user ends it
    std::string userEnd;
    int counter = 0;
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    int numbersEntered;

    // process & output
    while (true) {
        try {
            if (counter == 1) {
                std::cout <<
                "Do you want to end the program and get your results (Y/N): ";
                std::cin >> userEnd;
            } else if (counter == 0) {
                std::cout << "Enter a number to record: ";
                std::cin >> numbersEntered;
            }
            if (userEnd == "Y" || userEnd == "y") {
                std::cout << "\nPositive numbers: "
                << positiveCount << ", negative numbers: "
                << negativeCount << ", zeros: " << zeroCount << std::endl;
                break;
            } else if (userEnd == "N" || userEnd == "n") {
                std::cout << "Enter a number to record: ";
                std::cin >> numbersEntered;
            } else if (userEnd != "Y" || userEnd != "y"
            || userEnd != "N" || userEnd != "n") {
                counter = counter + 1;
                if (numbersEntered > 0) {
                    positiveCount = positiveCount + 1;
                } else if (numbersEntered < 0) {
                    negativeCount = negativeCount + 1;
                } else if (numbersEntered == 0) {
                    zeroCount = zeroCount + 1;
                }
                continue;
            } else {
                std::cout << "That is not yes or no." << std::endl;
                break;
            }
            if (numbersEntered > 0) {
                positiveCount = positiveCount + 1;
            } else if (numbersEntered < 0) {
                negativeCount = negativeCount + 1;
            } else if (numbersEntered == 0) {
                zeroCount = zeroCount + 1;
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid input." << std::endl;
            break;
        }
    }
    std::cout << "\nDone." << std::endl;
}
