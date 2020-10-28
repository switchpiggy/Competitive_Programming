#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
string h = "hello";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll cur = 0;
    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == h[cur]) cur++;
        if(cur == 5) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}