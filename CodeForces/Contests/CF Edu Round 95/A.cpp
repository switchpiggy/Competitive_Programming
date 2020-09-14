#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, y, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> x >> y >> k;
        //need k + yk sticks;
    cout <<  (k + y * k - 1 + x - 2)/(x - 1) + k << '\n';
    }

    return 0;
}