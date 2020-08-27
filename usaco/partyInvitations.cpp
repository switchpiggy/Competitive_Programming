#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, g;
bool used[1000007];
vector<set<ll>> groups;
vector<ll> in[1000007];
queue<ll> q;

int main() {
    scanf("%lld %lld", &n, &g);
    //cout << n << endl << g << endl;

    for(ll i = 0; i < g; ++i) {
        set<ll> s;
        ll sz, temp;
        scanf("%lld", &sz);

        for(ll j = 0; j < sz; ++j) {
            scanf("%lld", &temp);
            temp--;
            s.insert(temp);
            in[temp].push_back(i);
        }

        groups.push_back(s);
    }

    ll cnt = 0;

    q.push(0);
    used[0] = 1;

    while(!q.empty()) {
        ll f = q.front();
        q.pop();

        cnt++;

        for(ll i = 0; i < (ll)in[f].size(); ++i) {
            groups[in[f][i]].erase(f);
            if(groups[in[f][i]].size() == 1) {
                ll last = *(groups[in[f][i]].begin());
                if(!used[last]) {
                	used[last] = 1;
                    q.push(last);
                    
                }
            }
        }
    }

    printf("%lld\n", cnt);
    return 0;
}