#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x;
string s;

int main() {
    cin >> t;
    while(t--) {
        cin >> s >> x;
        string w(s.length(), '1');

        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '0') {
                if(i - x >= 0) w[i - x] = '0';
                if(i + x < s.length()) w[i + x] = '0';
            }
        }

        bool ok = 1;
        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '1' && (i - x < 0 || w[i - x] == '0') && (i + x >= s.length() || w[i + x] == '0')) {
                cout << "-1" << endl;
                ok = 0;
                break;
            }
        }

        if(ok) cout << w << endl;
    }   

    return 0; 
}