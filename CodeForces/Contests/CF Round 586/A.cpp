#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll z, o, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'z') z++;
        else if(s[i] == 'o') o++;
    }

    for(ll i = 0; i < o - z; ++i) cout << '1' << ' ';
    for(ll i = 0; i < z; ++i) cout << '0' << ' ';
    return 0;
}