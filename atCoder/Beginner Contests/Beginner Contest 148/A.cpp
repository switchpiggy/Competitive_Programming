#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for(ll i = 1; i <= 3; ++i) {
        if(i != a && i != b) {
            cout << i << '\n';
            return 0;
        }
    }
}