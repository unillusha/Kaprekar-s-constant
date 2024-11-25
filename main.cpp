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

int sortAscending(int num){
    vector<int> digits;

    // Extract digits
    while (num > 0) {
        digits.push_back(num % 10); // Extract the last digit
        num /= 10;  // Remove the last digit
    }

    // Sort in ascending order
    sort(digits.begin(), digits.end(), less<int>());

    // Recombine digits into a number
    int result = 0;
    for (int digit : digits) {
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

        int difference;

        while(difference != 6174){
            int largest = sortDescending(input);
            int smallest = sortAscending(input);

            difference = largest - smallest;
            cout << largest << "-" << smallest << "=" << difference << endl;
            input = difference;

            if(difference == 6174){
                cout << "Kaprekar's constant reached!" << endl;
                break;
            }
        }
        break;

    }

    return 0;
}
