#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    ll cnt = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'a') cnt++;
    }

    cout << min((ll)s.length(), cnt * 2 - 1) << '\n';
    return 0;
}