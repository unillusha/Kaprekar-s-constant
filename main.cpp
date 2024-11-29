#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int sortDescending(int num) {
    vector<int> digits;

    // Extract digits
    while (num > 0) {
        digits.push_back(num % 10); // Extract the last digit
        num /= 10;                 // Remove the last digit
    }

    // Sort in descending order
    sort(digits.begin(), digits.end(), greater<int>());

    for (int i = 0; i < digits.size(); i++){
        cout << digits[i] << " ";
    }
    printf("\n");

    // Recombine digits into a number
    int result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }

    return result;
}

int sortAscending(int num) {
    vector<int> digits;

    // Extract digits
    while (num > 0) {
        digits.push_back(num % 10); // Extract the last digit
        num /= 10;                 // Remove the last digit
    }

    // Sort in ascending order
    sort(digits.begin(), digits.end());
    for (int i = 0; i < digits.size(); i++){
        cout << digits[i] << " ";
    }
    printf("\n");

    // Recombine digits into a number
    int result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }

    return result;
}

int main() {
    string input;
    int number;

    while (true) {
        cout << "Enter a 4-digit number: ";
        cin >> input;

        // Validate input: must be exactly 4 digits and numeric
        if (input.length() == 4 && all_of(input.begin(), input.end(), ::isdigit)) {
            number = stoi(input); // Convert string to integer

            if(number < 10){
                number *= 1000;
            }

            if(number < 100){
                number *= 100;
            }

            if(number < 1000){
                number *= 10;
            }

        } else {
            cout << "Invalid input. Please enter a 4-digit number." << endl;
            continue; // Ask for input again
        }

        int difference = -1; // Initialize to avoid infinite loop

        while (difference != 6174) {
            int largest = sortDescending(number);
            int smallest = sortAscending(number);

            difference = largest - smallest;
            cout << largest << " - " << smallest << " = " << difference << endl;

            number = difference; // Update `number` with the new difference
            if(number < 10){
                number *= 1000;
            }

            if(number < 100){
                number *= 100;
            }

            if(number < 1000){
                number *= 10;
            }

            if (difference == 6174) {
                cout << "Kaprekar's constant reached!" << endl;
                break;
            }

            if(difference == 0){
                cout << "Kaprekar's constant not reached because all the digits are the same" << endl;
                break;
            }
        }
        printf("\n");
    }

    return 0;
}
