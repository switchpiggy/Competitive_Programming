#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s, t;
map<string, ll> m;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> s >> t;
        if(s.substr(0, 2) != t) m[s.substr(0, 2) + t]++;
    }

    ll cnt = 0;

    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        string newStr = itr->first.substr(2) + itr->first.substr(0, 2);
        //cout << newStr << endl;
        if(m.count(newStr)) {
            cnt += itr->second * (m.find(newStr)->second);
        }
    }

    printf("%lld\n", cnt/2);

    return 0;
}