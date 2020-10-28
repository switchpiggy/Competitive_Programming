#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[107], q[107], a, b;
bool c[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> a;
    for(ll i = 0; i < a; ++i) {
        cin >> p[i];
        c[p[i]] = 1;
    }
    cin >> b;
    for(ll i = 0; i < b; ++i) {
        cin >> q[i];
        c[q[i]] = 1;
    }

    for(ll i = 1; i <= n; ++i) {
        if(!c[i]) {
            cout << "Oh, my keyboard!\n";
            return 0;
        }
    }

    cout << "I become the guy.\n";
    return 0;
}