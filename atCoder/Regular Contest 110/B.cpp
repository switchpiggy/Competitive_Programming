#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
string t = "110";

void no() {
    cout << "0\n";
    exit(0);
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    ll ans = 0;
    if(s == "1") {
        cout << 20000000000 << '\n';
        return 0;
    }

    for(ll i = 0; i < n - 1; ++i) {
        if(i < n - 2 && s[i] == s[i + 1] && s[i + 1] == s[i + 2] && s[i] == '1') no();
        if(s[i] == s[i + 1] && s[i] == '0') no();
    }

    ll cur = -1;
    for(ll i = 0; i < 3; ++i) {
        bool ok = 1;
        for(ll j = 0; j < n; ++j) {
            if(s[j] != t[(j + i)%3]) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            cur = i;
            break;
        }
    }

    if(cur == -1) cout << "0\n";
    else cout << ((ll)3e10 - cur - n)/3 + 1 << '\n';
    return 0;
}