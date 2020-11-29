#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool ok = 1;
        if(k%3 == 0) {
            ll m = n%(k + 1);
            if(m%3 == 0 && m != k) ok = 0;
        } else {
            if(n%3 == 0) ok = 0;
        }

        cout << (ok ? "Alice\n" : "Bob\n");
    }

    return 0;
}