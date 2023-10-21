#include <bits/stdc++.h>
using namespace std;

bool isPallingdrom(string str, int left, int right) {
    if (left > right) return true;
    if (str[left] != str[right]) return false;
    return isPallingdrom(str, left+1, right-1);
}

int main() {
    string str;
    cin >> str;
    if (isPallingdrom(str, 0, str.size() - 1))
        cout <<"\n String " << str << " is pallingdrom";
    else 
        cout <<"\n String " << str << " is  not pallingdrom";
}

/*

abcdcba

abccba

abcd

*/




