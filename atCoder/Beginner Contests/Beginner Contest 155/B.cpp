#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    bool ok = 1;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i]%2 == 0 && a[i]%3 != 0 && a[i]%5 != 0) {
            ok = 0;
            break;
        }
    }

    cout << (ok?"APPROVED\n":"DENIED\n");
    return 0;
}