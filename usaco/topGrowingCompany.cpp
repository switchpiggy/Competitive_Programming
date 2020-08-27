#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string s;
map<string, ll> prevPos;
vector<string> cur;

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        cin >> s >> k;
        prevPos[s] = k;
    }

    for(ll i = 0; i < n; ++i) {
        cin >> s;
        cur.push_back(s);
    }

    ll ans = INT_MIN;
    string a;

    for(ll i = 0; i < n; ++i) {
        if(prevPos[cur[i]] - 1 - i > ans) {
            if(!prevPos[cur[i]]) {
                prevPos[cur[i]] = n + 1;
            }

            a = cur[i];
            ans = prevPos[cur[i]] - 1 - i;
        }
    }

    cout << a << endl;

    return 0;
}

