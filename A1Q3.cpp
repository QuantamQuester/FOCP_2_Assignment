//String Manipulation

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    string cleaned = "";
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c != ' ') {
            if (c >= 'A' && c <= 'Z') 
            c += ('a' - 'A');
            cleaned += c;
        }
    }
    string reversed = "";
    for (int i = cleaned.length() - 1; i >= 0; i--) {
        reversed += cleaned[i];
    }
    return cleaned == reversed;
}

void countFrequency(string str) {
    int freq[256] = {0};
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c != ' ') {
            if (c >= 'A' && c <= 'Z') 
            c += ('a' - 'A');
            freq[c]++;
        }
    }
    cout << "Character frequencies:\n";
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << ": " << freq[i] << endl;
        }
    }
}

void replaceVowels(string &str, char replacement) {
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < vowels.length(); j++) {
            if (str[i] == vowels[j]) {
                str[i] = replacement;
                break;
            }
        }
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    countFrequency(input);
    
    replaceVowels(input, '*');
    cout << "String after replacing vowels: " << input << endl;
    
    return 0;
}
