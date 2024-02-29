#include <iostream>
#include <string>
#include <algorithm>
#include <random>
using namespace std;
string generateRandomKey() {
    string key = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 g(rd());
    shuffle(key.begin(), key.end(), g);
    return key;
}

string encrypt(const string& text, const string& key) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            char mapped_char = key[ch - base];
            result += mapped_char;
        } else {
            result += ch;
        }
    }
    return result;
}

string decrypt(const string& text, const string& key) {
    string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            char mapped_char;

            for (size_t i = 0; i < key.size(); ++i) {
                if (key[i] == ch) {
                    mapped_char = 'a' + i;
                    break;
                }
            }
            result += mapped_char;
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    string key = generateRandomKey();

    string ciphertext = encrypt(text, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}

