#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << (abs(b - a) + 9)/10 << endl;
    }

    return 0;
}