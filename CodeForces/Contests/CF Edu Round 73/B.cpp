#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i%2 == j%2) cout << 'B';
            else cout << 'W';
        }

        cout << '\n';
    }

    return 0;
}