#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s, t;
vector<ll> b;
vector<ll> a;

int main() {
    cin >> n >> s >> t;

    if(n == 1 && s[0] != t[0]) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < s.length(); ++i) {
        if(s[i] != t[i]) {
            if(s[i] == 'a') a.push_back(i + 1);
            else b.push_back(i + 1);
        }
    }

    if(a.size()%2 != b.size()%2) {
        cout << "-1\n";
        return 0;
    }

    cout << a.size()/2 + b.size()/2 + (a.size()%2) * 2 << '\n';
    for(ll i = 0; i + 1 < a.size(); i += 2) {
        cout << a[i] << ' ' << a[i + 1] << '\n';
    }

    for(ll i = 0; i + 1 < b.size(); i += 2) {
        cout << b[i] << ' ' << b[i + 1] << '\n';
    }

    if(a.size()%2 == 1) {
        cout << a[a.size() - 1] << ' ' << a[a.size() - 1] << '\n';
        cout << a[a.size() - 1] << ' ' << b[b.size() - 1] << '\n';
    }

    return 0;
}