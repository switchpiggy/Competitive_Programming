#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    if(n == 1) {
        cout << 1 << endl << 1 << ' ' << 1 << endl;
        return 0;
    }
    cout << (n/2) + 1 << endl;
    for(ll i = 0; i < n/2; ++i) cout << 1 << ' ' << i + 1 << endl;
    for(ll i = 0; i < n - (n/2); ++i) cout << 1 + n/2 << ' ' << i + 1 << endl;
    return 0;
}