// Author: Nirupam Pal
// Date: 04/08/2023
// Description: This program is used for calculating the root using bisection method

#include <iostream>
#include <math.h>
using namespace std;
#define ERROR 0.001

// Function for which the root is required
// float y(float x) {
//     return pow(x, 2) -1;
// }

float y(float x) {
    return (sqrt(x) - 7);
}

int main() {

    cout << "*-----------------------------------------*-----------------------------------------*" << endl;
    cout << "|                                 Author: Nirupam Pal                               |" << endl;
    cout << "|                                   Date: 04/08/2023                                |" << endl;
    cout << "| Description: This program is used for calculating the root using bisection method |" << endl;
    cout << "*-----------------------------------------*---------------------------------------- *" << endl;

    float x0 = 0, x1 = 0, x2 = 0;
    cout << "The initial guesses should bound the root." << endl;
    cout << "Enter the first guess: ";
    cin >> x0;
    cout << "Enter the second guess: ";
    cin >> x1;

    // Preliminary checks for boundary line conditions
    if (y(x0) == 0) {
        cout << "\nThe root for the function is: " << x0 << endl;
        if (y(x1) == 0) {
            cout << "\nThe root for the function is: " << x1 << endl;
            return 0;
        }
        return 0;
    }
    else if (y(x1) == 0) {
        cout << "\nThe root for the function is: " << x1 << endl;
        if (y(x0) == 0) {
            cout << "\nThe root for the function is: " << x0 << endl;
            return 0;    
        }
        return 0;
    }
    else if (y(x0) == y(x1)) {
        cout << "The guesses are not valid" << endl;
        return 0;
    }
    else if (y(x0)*y(x1) > 0) {
        cout << "The guesses are not valid" << endl;
        return 0;
    }
    // Application of the bisection method
    else {
        for (int i = 0; i >= 0; i++) {
            x2 = (x0 + x1) / 2;
            cout << "Iteration - " << i+1 << ": " << x2 << endl;
            // Checking the error in the computed root
            if (abs(y(x2)) <= ERROR) {
                cout << "\nThe solution has converged!" << endl;
                break;
            }
            else {
                if (y(x0)*y(x2) > 0) {
                    x0 = x2;
                }
                else {
                    x1 = x2;
                }
            }
        }
    }
    // Printing the root for the function
    cout << "\nThe root for the function is: " << x2 << endl;
    return 0;
}
