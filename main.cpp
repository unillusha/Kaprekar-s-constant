#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sortDescending(int num){
    vector<int> digits; // store the individual digits of the input number

    // Extract digits
    while (num > 0) {
        digits.push_back(num % 10); // Extract the last digit
        num /= 10;  // Remove the last digit
    }

    // Sort in descending order
    sort(digits.begin(), digits.end(), greater<int>());

    // Recombine digits into a number
    int result = 0;
    for (int digit : digits) {
        // shifts the current number to the left
        // & appends the current digit to the right
        result = result * 10 + digit;
    }

    return result;
}

int main()
{

    while (true){
        int input;
        cout << "Enter a 4-digit number: ";
        cin >> input;

        // Call the sortDescending function and display the result
        int sortedDesc = sortDescending(input);
        cout << "Digits in descending order: " << sortedDesc << endl;
    }

    return 0;
}
