#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, d, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> d >> k;
        bool ok = 0;
        for(ll i = 0; i <= d; i += k) {
            //cout << i << ' ';
            if(2 * (i * i) <= d * d && i * i + ((i + k) * (i + k)) > d * d) {
                ok = 1;
                break;
            }
        }

        cout << (ok ? "Utkarsh\n" : "Ashish\n");
    }

    return 0;
}