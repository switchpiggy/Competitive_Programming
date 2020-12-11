#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;
string s = "abc";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n/3; ++i) cout << s;
        for(ll i = 0; i < n%3; ++i) cout << s[i];
        cout << '\n';
    }

    return 0;   
}