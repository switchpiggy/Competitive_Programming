#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, u, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll cnt = 0;
        for(ll i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            cnt += (u == x || v == x);
        }

        if(cnt == 1 || n == 1) {
            cout << "Ayush\n";
            continue;
        }

        cout << (n%2 ? "Ashish\n" : "Ayush\n");
    }

    return 0;
}