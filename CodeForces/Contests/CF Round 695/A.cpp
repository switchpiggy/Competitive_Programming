#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s = "0123456789";
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 1) {
            cout << 9 << '\n';
            continue;
        } else if(n == 2) {
            cout << 98 << '\n';
            continue;
        } else if(n == 3) {
            cout << 989 << '\n';
            continue;
        }

        cout << 989;
        for(ll i = 0; i < n - 3; ++i) {
            cout << i%10;
        }
        cout << '\n';
    }
}