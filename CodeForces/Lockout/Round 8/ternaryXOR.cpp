#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        string max, min;
        bool ok = 0;
        for(ll i = 0; i < n; ++i) {
            if(s[i] == '2') {
                if(ok) {
                    max += '0';
                    min += '2';
                } else {
                    max += '1';
                    min += '1';
                }
            } else if(s[i] == '1') {
                if(ok) {
                    max += '0';
                    min += '1';
                } else {
                    max += '1';
                    min += '0';
                    ok = 1;
                }
            } else {
                max += '0';
                min += '0';
            }
        }

        cout << min << '\n' << max << '\n';
    }
}