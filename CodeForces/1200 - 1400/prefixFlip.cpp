#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        ll k = 0;
        for(ll i = 0; i < a.length(); ++i) {
            if(a[i] != b[i]) {
                k += 3;
                if(i == 0) k-= 2;
            }
        }

        cout << k << ' ';
        for(ll i = 0; i < a.length(); ++i) {
            if(a[i] != b[i]) {
                cout << i + 1 << ' ';
                if(i == 0) continue;
                cout << 1 << ' ';
                cout << i + 1 << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}