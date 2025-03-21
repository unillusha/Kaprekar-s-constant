#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

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

    // Recombine digits into a number
    int result = 0;
    for (int digit : digits) {
        result = result * 10 + digit;
    }

    return result;
}

int make4DigitNumber(int inputNum) {
    if (inputNum < 10) {
        inputNum *= 1000;
    } else if (inputNum < 100) {
        inputNum *= 100;
    } else if (inputNum < 1000) {
        inputNum *= 10;
    }

    return inputNum;
}

int calculateKaprekarSteps(int number, vector<string>& explanations) {
    int steps = 0;

    while (true) {
        int largest = sortDescending(number);
        int smallest = sortAscending(number);

        int difference = largest - smallest;
        steps++;

        // Store the explanation for this step
        string explanation = to_string(largest) + " - " + to_string(smallest) + " = " + to_string(difference);
        explanations.push_back(explanation);

        number = difference; // Update `number` with the new difference
        number = make4DigitNumber(number);

        if (difference == 6174) {
            break;
        }

        if (difference == 0) {
            return -1; // Kaprekar's constant not reached
        }
    }

    return steps;
}

void kaprekarProcess(int originalNumber) {
    vector<string> explanations;
    int steps = calculateKaprekarSteps(originalNumber, explanations);

    if (steps == -1) {
        cout << "Kaprekar's constant not reached because all the digits are the same" << endl;
    } else {
        cout << "Input: " << originalNumber << endl;
        cout << "Output: " << steps << endl;
        cout << "Explanation:" << endl;
        for (const string& exp : explanations) {
            cout << exp << endl;
        }
    }
}

void listStepsForRange(int minNumber, int maxNumber) {
    for (int num = minNumber; num <= maxNumber; num++) {
        vector<string> explanations;
        int steps = calculateKaprekarSteps(num, explanations);

        if (steps != -1) {
            cout << num << "\t" << steps << endl;
        } else {
            cout << num << "\t" << "x" << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // Requirement 1: No command-line argument provided, generate a random 4-digit number
        srand(time(0)); // Seed the random number generator
        int number = rand() % 9000 + 1000; // Generate a random 4-digit number
        kaprekarProcess(number);
    } else if (argc == 2) {
        // Check if the argument is --min=<number> or --max=<number>
        string arg = argv[1];
        if (arg.substr(0, 6) == "--min=") {
            // Requirement 3: List steps for all numbers ≥ the given number
            string minNumberStr = arg.substr(6);
            if (all_of(minNumberStr.begin(), minNumberStr.end(), ::isdigit)) {
                int minNumber = stoi(minNumberStr);
                if (minNumber >= 0 && minNumber <= 9999) {
                    listStepsForRange(minNumber, 9999);
                } else {
                    cout << "Invalid range. Please provide a number between 0 and 9999." << endl;
                }
            } else {
                cout << "Invalid input. Please provide a valid number after --min=." << endl;
            }
        } else if (arg.substr(0, 6) == "--max=") {
            // Requirement 4: List steps for all numbers ≤ the given number
            string maxNumberStr = arg.substr(6);
            if (all_of(maxNumberStr.begin(), maxNumberStr.end(), ::isdigit)) {
                int maxNumber = stoi(maxNumberStr);
                if (maxNumber >= 0 && maxNumber <= 9999) {
                    listStepsForRange(0, maxNumber);
                } else {
                    cout << "Invalid range. Please provide a number between 0 and 9999." << endl;
                }
            } else {
                cout << "Invalid input. Please provide a valid number after --max=." << endl;
            }
        } else {
            // Requirement 2: A 4-digit number is provided as a command-line argument
            string input = argv[1];
            if (input.length() == 4 && all_of(input.begin(), input.end(), ::isdigit)) {
                int number = stoi(input); // Convert string to integer
                number = make4DigitNumber(number);
                kaprekarProcess(number);
            } else {
                cout << "Invalid input. Please provide a 4-digit number." << endl;
                return 1; // Exit the program
            }
        }
    } else {
        cout << "Usage: " << argv[0] << " [--min=<number>] [--max=<number>] [4-digit number]" << endl;
        return 1; // Exit the program
    }

    return 0;
}
