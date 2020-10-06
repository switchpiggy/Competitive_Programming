#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    string t = s.substr(0, n/2), v;

    if(n%2 == 1) {
        v = s.substr(n/2 + 1);

        if(t < v) t.push_back(s[n/2]);
        else v.push_back(s[n/2]);        
    } else {
        v = s.substr(n/2);
    }

    while(!v.empty()) {
        if(v[0] != '0') break;
        t.push_back(v[0]);
        v.erase(0, 1);
    }

    bool ok = 0;
    if(v.empty() || v[0] == '0') ok = 1;

    while(!t.empty() && (v.empty() || v.back() == '0')) {
        //cout << v << ' ' << t << '\n';
        v.push_back(t.back());
        t.pop_back();
    }

    if(ok) reverse(v.begin(), v.end());
    //cout << v << '\n' << t << '\n';
    cout << stoll(t) + stoll(v) << '\n';
    return 0;
}