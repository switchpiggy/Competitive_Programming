#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y, z, t;

int main() {
    cin >> t;
    while(t--) {
        cin >> x >> y >> z;

        if(x == y && x >= z) {
            cout << "YES" << endl;
            cout << x << ' ' << z << " 1" << endl;
        } else if(x == z && x >= y) {
            cout << "YES" << endl;
            cout << x << ' ' << y << " 1" << endl;
        } else if(y == z && y >= x) {
            cout << "YES" << endl;
            cout << y << ' ' << x << " 1" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}