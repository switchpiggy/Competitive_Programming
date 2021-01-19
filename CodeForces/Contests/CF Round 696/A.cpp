#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        string res;
        res += '1';
        ll last = (res[0] - '0') + (s[0] - '0');
        for(ll i = 1; i < n; ++i) {
            if(last == 2) {
                if(s[i] == '0') {
                    res += '1';
                    last = 1;
                } else {
                    res += '0';
                    last = 1;
                }
            } else if(last == 0) {
                if(s[i] == '1') {
                    res += '1';
                    last = 2;
                } else {
                    res += '1';
                    last = 1;
                }
            } else {
                if(s[i] == '1') {
                    res += '1';
                    last = 2;
                } else {
                    res += '0';
                    last = 0;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}