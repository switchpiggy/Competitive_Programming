#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;

    string s = to_string(n);
    string t = s.substr(0, 1) + s.substr(2, 1) + s.substr(4, 1) + s.substr(3, 1) + s.substr(1, 1);

    n = stoi(t);
    ll cur = n;

    for(ll i = 0; i < 4; ++i) {
        cur *= n;
        cur %= 100000;
    }

    if(cur == 0) cout << "0000";
    cout << cur << endl;
}