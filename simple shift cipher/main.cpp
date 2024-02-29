
#include <iostream>
#include <string>

using namespace std;

string encryptSubstitution(const string& plainText, int shift) {
    string cipherText = "";


    for (char ch : plainText) {
        if (isalpha(ch)) {
            char shiftedChar = ch + shift;


            if (islower(ch)) {
                shiftedChar = 'a' + (shiftedChar - 'a') % 26;
            }

            else if (isupper(ch)) {
                shiftedChar = 'A' + (shiftedChar - 'A') % 26;
            }


            cipherText += shiftedChar;
        } else {

            cipherText += ch;
        }
    }

    return cipherText;
}

string decryptSubstitution(const string& cipherText, int shift) {

    return encryptSubstitution(cipherText, -shift);
}

int main() {
    string plainText, cipherText, decryptedText;
    int shift;

    cout << "Enter the plain text: ";
    getline(cin, plainText);
    cout << "Enter the key : ";
    cin >> shift;

    cipherText = encryptSubstitution(plainText, shift);
    cout << "Encrypted text: " << cipherText << endl;

    decryptedText = decryptSubstitution(cipherText, shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
