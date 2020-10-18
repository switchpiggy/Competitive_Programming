#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> q;

        if(q == 1) {
            cout << "Neither\n";
            continue;
        }

        bool ok = 0;
        for(ll i = 2; i * i <= q; ++i) {
            if(q%i == 0) {
                cout << "Composite\n";
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "Prime\n";
    }

    return 0;
}