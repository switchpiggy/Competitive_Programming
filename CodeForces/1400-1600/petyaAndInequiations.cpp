#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;

int main() {
    cin >> n >> x >> y;
    if(n > y) {
        cout << "-1" << endl;
        return 0;
    }
    if((n - 1) + (y - (n - 1)) * (y - (n - 1)) >= x) {
        cout << (y - (n - 1)) << endl;
        for(ll i = 0; i < n - 1; ++i) cout << '1' << endl;
    } else cout << "-1" << endl;

    return 0;
}