#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
vector<ll> v;

ll getAns(char a) {
    v.clear();
    v.push_back(-1);
    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] == a) v.push_back(i);
    }
    v.push_back(s.length());

    ll maxn = 0;
    for(ll i = 0; i < v.size() - 1; ++i) {
        maxn = max(maxn, v[i + 1] - v[i]);
    }

    return maxn;
}

int main() {
    ll ans = INT_MAX;
    cin >> s;
    for(char c = 'a'; c <= 'z'; ++c) {
        ans = min(ans, getAns(c));
    }

    cout << ans << endl;
}