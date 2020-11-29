#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    long double a = 0, b = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '?') {
            if(i < n/2) a += 4.5;
            else b += 4.5;
        } else {
            if(i < n/2) a += (s[i] - '0');
            else b += (s[i] - '0');
        }
    }

    if(fabsl(a - b) <= 1e-7) cout << "Bicarp\n";
    else cout << "Monocarp\n";
    return 0;
}