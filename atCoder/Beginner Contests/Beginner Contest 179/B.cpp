#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll cur = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a >> b;
        if(a == b) {
            cur++;
        } else cur = 0;

        if(cur >= 3) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}