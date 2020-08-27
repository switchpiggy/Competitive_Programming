#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y;

int main() {
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << (x * y + 1)/2 << endl;
    }

    return 0;
}