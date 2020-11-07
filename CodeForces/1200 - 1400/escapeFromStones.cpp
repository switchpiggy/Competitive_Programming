#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
vector<ll> a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'l') b.push_back(i + 1);
        else a.push_back(i + 1);
    }

    reverse(b.begin(), b.end());

    for(ll i : a) cout << i << '\n';
    for(ll i : b) cout << i << '\n';
    return 0;
}