#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<string> v;

ll subs(string s) {
    ll ans = 0, cur = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 's') cur++;
        else ans += cur;
    }

    return ans;
}

bool cmp(string s, string t) {
    return subs(s + t) > subs(t + s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), cmp);

    string res;
    for(string s : v) res += s;
    cout << subs(res) << '\n';
    return 0;
}