#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x;
string s;

int main() {
    cin >> x;
    ll cur = 0;
    for(ll i = 0; i < x; ++i) {
        cin >> s;
        if(s[0] == '+' || s[2] == '+') cur++;
        else cur--;
    }

    cout << cur << endl;
    return 0;
}