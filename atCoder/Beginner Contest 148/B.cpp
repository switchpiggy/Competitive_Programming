#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> t;
    for(ll i = 0; i < n; ++i) cout << s[i] << t[i];
}