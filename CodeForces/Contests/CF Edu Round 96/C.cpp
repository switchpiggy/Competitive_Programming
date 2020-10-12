#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;

        cout << 2 << '\n';
        ll prev = n;
        for(ll i = n - 1; i >= 1; --i) {
            cout << prev << ' ' << i << '\n';
            prev = (prev + i + 1)/2;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    }

    return 0;
}