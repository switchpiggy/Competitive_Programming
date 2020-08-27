#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        if(n == 1 || m == 1 || (n == 2 && m == 2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}