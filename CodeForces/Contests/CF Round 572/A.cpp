#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    ll zero = 0;
    for(ll i = 0; i < n; ++i) if(s[i] == '0') zero++;
    if(n%2 == 0 && n/2 == zero) {
        cout << 2 << '\n';
        cout << s.substr(0, n - 1) << ' ' << s[n - 1] << '\n';
        return 0;
    }

    cout << 1 << '\n' << s << '\n';
    return 0;
}