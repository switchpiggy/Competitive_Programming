#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, x, n, m;

int main() {
    cin >> t;
    while(t--) {
        cin >> x >> n >> m;
        while(n && x/2 + 10 < x) {
            n--;
            x = x/2 + 10;
            if(x <= m * 10) break;
        }

        x -= m * 10;

        if(x <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}