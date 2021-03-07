#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t, i;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t >> a >> b >> i;
    if(i == s) cout << a - 1 << ' ' << b << '\n';
    else cout << a << ' ' << b - 1 << '\n';

    return 0;
}