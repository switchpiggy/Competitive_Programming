#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<string> v;
ll n, m;
vector<ll> bars(107);

ll calcAns() {
    stack<ll> s;

    ll ans = 0;

    ll i = 0;
    while(i < m) {
        if(s.empty() || bars[s.top()] <= bars[i]) {
            s.push(i);
            i++;
            continue;
        }

        ll t = s.top();
        s.pop();

        ll temp;

        if(s.empty()) temp = bars[t] * i;
        else temp = bars[t] * (i - s.top() - 1);

        ans = max(ans, temp);
    }

    while(!s.empty()) {
        ll t = s.top();
        s.pop();

        ll temp;

        if(s.empty()) temp = bars[t] * i;
        else temp = bars[t] *  (i - s.top() - 1);

        ans = max(ans, temp);
    }

    return ans;
}

int main() {
    scanf("%lld %lld", &n, &m);
    v.resize(n);
    for(ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll finalAns = 0;

    for(char c = 'a'; c <= 'z'; ++c) {
    	bars.resize(m, 0);
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(v[i][j] != c) bars[j] = 0;
                else bars[j]++;
            }
            
            finalAns = max(finalAns, calcAns());
        }
    }

    printf("%lld\n", finalAns);

    return 0;
}