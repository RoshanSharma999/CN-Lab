// Error detection - CRC(for 16-bits)

#include <bits/stdc++.h>
using namespace std;

// Function to perform XOR operation
string xorOperation(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

// Function to perform CRC division
string crcDivision(string data, string divisor) {
    int divisorLength = divisor.length();
    string temp = data.substr(0, divisorLength);

    int i = divisorLength;
    while (i < data.length()) {
        if (temp[0] == '1')
            temp = xorOperation(divisor, temp) + data[i];
        else
            temp = xorOperation(string(divisorLength, '0'), temp) + data[i];
        i++;
    }
    if (temp[0] == '1')
        temp = xorOperation(divisor, temp);
    else
        temp = xorOperation(string(divisorLength, '0'), temp);

    return temp;
}

int main() {
    string data, receivedData;
    string generator = "11000000000000101"; // CRC-16
    cout << "Enter binary data: ";
    cin >> data;
    // Append 16 zeros
    string appendedData = data + string(16, '0');
    
    // Sender Side CRC calculation
    string remainder = crcDivision(appendedData, generator);
    string transmittedData = data + remainder;
    cout << "\nSender Side:";
    cout << "\nCRC Remainder: " << remainder;
    cout << "\nTransmitted Data: " << transmittedData << endl;

    // Receiver Side
    cout << "\nEnter received data: ";
    cin >> receivedData;
    string receiverRemainder = crcDivision(receivedData, generator);
    cout << "\nReceiver Side:";
    cout << "\nRemainder after division: " << receiverRemainder << endl;

    // Error Detection
    if (count(receiverRemainder.begin(), receiverRemainder.end(), '1') == 0)
        cout << "No Error Detected\n";
    else
        cout << "Error Detected in Data\n";

    return 0;
}
