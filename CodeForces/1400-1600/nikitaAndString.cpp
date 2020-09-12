#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll b[5007];

int main() {
    cin >> s;

    for(ll i = 0; i < s.length(); ++i) if(s[i] == 'b') b[i]++;    
    for(ll i = 1; i < s.length(); ++i) b[i] += b[i - 1];

    ll ans = INT_MAX;

    for(ll i = 0; i < s.length(); ++i) {
        for(ll j = i; j < s.length(); ++j) {
            if(s[i] == 'b' && s[j] == 'b') {
                ans = min(ans, b[i - 1] + b[s.length() - 1] - b[j] + (j - i + 1 - (b[j] - b[i] + 1)));
            }
        }
    }

    if(ans == INT_MAX) ans = 0;
    cout << (ll)s.length() - ans << '\n';
    return 0;
}