#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    cin >> s;

    if(s[0] == '9') cout << '9';

    else if(s[0] >= '5') cout << '9' - s[0];

    else cout << s[0];

    for(int i = 1; i < s.length(); ++i) {

        if(s[i] >= '5') cout << '9' - s[i];

        else cout << s[i];

    }

}   