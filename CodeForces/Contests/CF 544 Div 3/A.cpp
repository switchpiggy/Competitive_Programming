#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    a = stoll(s.substr(0, 2));
    b = stoll(s.substr(3));
    c = stoll(t.substr(0, 2));
    d = stoll(t.substr(3));

    ll ave = 60 * a + b + ((60 * c + d) - (60 * a + b))/2;

    if(ave/60 < 10) cout << 0;
    cout << ave/60 << ':';
    if(ave%60 < 10) cout << 0;
    cout << ave%60 << '\n';

    return 0;
}