#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    cin >> s;
    for(ll i = 0; i < s.length(); ++i) {
        if((s[i] - '0')%8 == 0) {
            cout << "YES\n" << s[i] << endl;
            return 0;
        }
    }

    for(ll i = 0; i < s.length(); ++i) {
        for(ll j = i + 1; j < s.length(); ++j) {
            if((10 * (s[i] - '0') + (s[j] - '0'))%8 == 0) {
                cout << "YES\n" << s[i] << s[j] << endl;
                return 0;
            }
        }
    }

    for(ll i = 0; i < s.length(); ++i) {
        for(ll j = i + 1; j < s.length(); ++j) {
            for(ll k = j + 1; k < s.length(); ++k) {
                if((100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0'))%8 == 0) {
                    cout << "YES\n" << s[i] << s[j] << s[k] << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}