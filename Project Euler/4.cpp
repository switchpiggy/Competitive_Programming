#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> v;

ll palindrome(ll x) {
    string s = to_string(x);
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] != s[s.length() - i - 1]) return 0;
    }

    return 1;
}

void calculate() {
    for(ll i = 100; i <= 999; ++i) {
        for(ll j = 100; j <= 1e6/i && j <= 999; ++j) {
            if(palindrome(i * j)) v.push_back(i * j);
        }
    }

    return;
}

int main() {
    cin >> t;
    calculate();
    sort(v.begin(), v.end());
    while(t--) {
        cin >> n;
        auto i = lower_bound(v.begin(), v.end(), n);
        while(*i >= n) i--;

        cout << *i << endl;
    }

    return 0;
}