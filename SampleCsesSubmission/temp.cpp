#include <iostream>
using namespace std;

// A function to print a substring.
void printSubstring(string str, int left, int right){
    for (int i = left; i <= right; i++)
        cout << str[i];
}

// A function to get the longest palindromic substring 
// in the a given string using Brute Force Approach.
void longestPalSubstring(string str){
    // Getting length of the input string
    int n = str.size();

    // All substrings of length 1 are palindromes
    int maxLength = 1;
    
    int start = 0;

    // Checking all the substrings
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int flag = 1;

            // Checking for a palindromic subtring
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            // If substring is palindromic
            if (flag && (j - i + 1) > maxLength){
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    // Printing the longest Palindromic substring
    // cout << "The Longest Palindromic Substring is: ";
    printSubstring(str, start, start + maxLength - 1);
}

// Driver Code
int main(){
    string str;
    cin>>str;
    longestPalSubstring(str);
    return 0;
}