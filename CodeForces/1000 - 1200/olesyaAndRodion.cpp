#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    if(t == 10) {
        if(n == 1) cout << "-1\n";
        else cout << '1' << string(n - 1, '0') << '\n';
    } else {
        cout << string(n, t + '0') << '\n';
    }

    return 0;
}