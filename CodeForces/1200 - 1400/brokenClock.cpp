#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    ll cnt = 0;

    if(n == 12) {
        if(s[0] == '0' && s[1] == '0') s[0] = '1';
        else if(s[0] == '1' && s[1] > '2') s[1] = '0';
        else if((s[0] - '0') * 10 + s[1] - '0' > 12) {
            if(s[1] == '0') s[0] = '1';
            else s[0] = '0';
        }

        ll x = (s[3]  - '0') * 10 + s[4] - '0';
        if(x > 59) {
            s[3] = '0';
        }
        
    } else {
        ll x = (s[0] - '0') * 10 + s[1] - '0';
        if(x > 23) {
            s[0] = '0';
        }

        x = (s[3] - '0') * 10 + s[4] - '0';
        if(x > 59) {
            s[3] = '0';
        }
    }

    cout << s << endl;

    return 0;
}