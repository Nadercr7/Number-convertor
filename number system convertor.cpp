#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int convertToDecimal(string num, int base) {
    int decimal = 0;
    int power = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digitValue = 0;
        if (isdigit(num[i])) {
            digitValue = num[i] - '0';
        } else {
            digitValue = num[i] - 'A' + 10;
        }
        decimal += digitValue * power;
        power *= base;
    }
    return decimal;
}

string convertFromDecimal(int num, int base) {
    stringstream ss;
    do {
        int rem = num % base;
        if (rem < 10) {
            ss << rem;
        } else {
            ss << char('A' + rem - 10);
        }
        num /= base;
    } while (num != 0);
    string result = ss.str();
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num;
    int fromBase, toBase;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the base of the number: ";
    cin >> fromBase;

    cout << "Enter the base to convert: ";
    cin >> toBase;

    if (fromBase < 2 || fromBase > 16 || toBase < 2 || toBase > 16) {
        cout << "Invalid base. Please enter a base between 2 and 16." << endl;
        return 1;
    }

    int decimal = convertToDecimal(num, fromBase);
    string result = convertFromDecimal(decimal, toBase);

    cout << "Converted number: " << result << endl;

    return 0;
}
