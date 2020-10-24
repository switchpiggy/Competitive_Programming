#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> n >> a >> b;
        if(2 * a < b) cout << (n/2 * (2 * a)) + a * (n%2) << '\n';
        else cout << (n/2 * b) + a * (n%2) << '\n';
    }

    return 0;
}