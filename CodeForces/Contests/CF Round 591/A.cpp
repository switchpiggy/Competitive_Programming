#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n < 4) cout << 4 - n << endl;
        else if(n%2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}