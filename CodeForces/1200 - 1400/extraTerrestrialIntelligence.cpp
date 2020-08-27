#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
vector<ll> v;
set<ll> diff;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%lld", &n);
    cin >> s;

    for(ll i = 0; i < n; ++i) {
        if(s[i] - '0' == 1) v.push_back(i);
    }

    for(ll i = 0; i < v.size() - 1; ++i) diff.insert(v[i + 1] - v[i]);

    if(diff.size() == 1) printf("YES\n");
    else printf("NO\n");

    return 0;
}