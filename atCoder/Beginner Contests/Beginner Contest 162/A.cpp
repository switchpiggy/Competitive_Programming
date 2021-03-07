#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    cin >> s;
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == '7') {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}