#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= 9; ++i) {
        if(n%i == 0 && n/i <= 9) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}