#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string i, have, a, s, t;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll j = 0; j < n; ++j) {
        cin >> i >> have >> a >> s >> i >> have >> a >> t;
        cout << "Uh! " << t << '-' << s << '!' << '\n';
    }

    return 0;
}