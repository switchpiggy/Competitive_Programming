#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'o') x++;
        else {
            x = max(0ll, x - 1);
        }
    }

    cout << x << '\n';
    return 0;
}