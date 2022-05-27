// Copyright (c) 2022 Hunter Connolly All rights reserved
// Created by: Hunter Connolly
// Created on: May 16, 2022
// This program calculates the surface area and volume of a cone

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

float CalcSurfaceArea(float radius, float height) {
    // declare variable
    float surfaceArea;

    // calculate surface area
    surfaceArea = M_PI * radius * (radius + sqrt(pow(height, 2)
+ pow(radius, 2)));

    // return the surface area
    return surfaceArea;
}

float CalcVolume(float radius, float height) {
    // declare variable
    float volume;

    // calculate volume
    volume = M_PI * pow(radius, 2) * height / 3;

    // return the volume
    return volume;
}

int main() {
    // declare variables
    std::string playAgain;
    std::string units;
    std::string radiusAsString;
    std::string heightAsString;
    float userRadius;
    float userHeight;
    float volume;
    float surfaceArea;
    int counter = 0;

    // greet the user
    std::cout << "This program calculates the volume and surface "
"area of a cone!\n";
    std::cout << "\n";

    // ask if they want to play
    std::cout << "Would you like to calculate the surface area "
"and volume of a cone? (y/n): ";
    std::cin >> playAgain;

    while (playAgain == "yes" || playAgain == "y") {
        // get the user input
        std::cout << "What units are you using? (mm, cm, etc.): ";
        std::cin >> units;
        std::cout << "What is the radius of your cone? (" << units << "): ";
        std::cin >> radiusAsString;
        std::cout << "What is the height of your cone? (" << units << "): ";
        std::cin >> heightAsString;
        std::cout << "";

        try {
            // cast the radius and height
            userRadius = std::stof(radiusAsString);
            userHeight = std::stof(heightAsString);

            // call the functions
            surfaceArea = CalcSurfaceArea(userRadius, userHeight);
            volume = CalcVolume(userRadius, userHeight);

            // display the surface area and volume of the code
            std::cout << "\n";
            std::cout << "The surface area of your cone is: " << std::fixed <<
    std::setprecision(2) << std::setfill('0') <<surfaceArea << units << "^2\n";
            std::cout << "The volume of your cone is: " << std::fixed <<
    std::setprecision(2) << std::setfill('0') << volume << units << "^3\n";
            std::cout << "\n";

            // ask the user if they would like to play again
            std::cout << "Would you like to play again?: ";
            std::cin >> playAgain;
            std::cout << "\n";

            // if the enter yes then the program will continue
            // if they enter anything else then the program will end
            if (playAgain == "yes" || playAgain == "y") {
                continue;
            } else {
                std::cout << "Thanks for playing!!";
                break;
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid input please enter a valid number!!\n";
            std::cout << "\n";
            continue;
        }
    }
}
