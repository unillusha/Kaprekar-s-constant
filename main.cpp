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

void kaprekarProcess(int originalNumber) {
    int number = originalNumber; // Use a separate variable for the process
    int steps = 0;
    vector<string> explanations; // Store explanations for each step

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
            cout << "Kaprekar's constant not reached because all the digits are the same" << endl;
            return;
        }
    }

    // Display the output in the required format
    cout << "Input: " << originalNumber << endl; // Print the original input
    cout << "Output: " << steps << endl;
    cout << "Explanation:" << endl;
    for (const string& exp : explanations) {
        cout << exp << endl;
    }
}

int main(int argc, char* argv[]) {
    int number;

    if (argc == 1) {
        // No command-line argument provided, generate a random 4-digit number
        srand(time(0)); // Seed the random number generator
        number = rand() % 9000 + 1000; // Generate a random 4-digit number
    } else if (argc == 2) {
        // A number is provided as a command-line argument
        string input = argv[1];
        if (input.length() == 4 && all_of(input.begin(), input.end(), ::isdigit)) {
            number = stoi(input); // Convert string to integer
            number = make4DigitNumber(number);
        } else {
            cout << "Invalid input. Please provide a 4-digit number." << endl;
            return 1; // Exit the program
        }
    } else {
        cout << "Usage: " << argv[0] << " [4-digit number]" << endl;
        return 1; // Exit the program
    }

    kaprekarProcess(number);

    return 0;
}
