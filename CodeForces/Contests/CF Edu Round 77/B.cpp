
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(max(a, b) <= 2 * min(a, b) && (a%3 == 2 * b%3 || b%3 == 2 * a%3)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}