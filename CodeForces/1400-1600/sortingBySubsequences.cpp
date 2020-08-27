#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

    ll cnt = 1, ans = 0;
    ll n, nxt[100005], used[100005], temp;
	vector<pair<ll, ll>> v;

bool comp(pair<ll, ll>x, pair<ll, ll> y) {
    return x.first < y.first;
}

int main() {

    scanf("%lld", &n);
    //cout << n << endl;
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        //cout << temp << ' ' << i <<  ' ' << endl;
        v.push_back(make_pair(temp, i));
    }

    sort(v.begin(), v.end(), comp);
    //cout << "sorted" << endl;

    for(ll i = 0; i < n; ++i) {
        nxt[v[i].second] = i;
    }

    for(ll i = 0; i < n; ++i) {
        if(used[i] != 0)  continue;
        else {
            ll u = i;
            while(used[u] == 0) {
                used[u] = cnt;
                //cout << u << endl;
                u = nxt[(int)u];
            }
            cnt++;
            ans++;
        }
    }

    vector<ll> res[ans];
    printf("%lld\n", ans);
    for(int i = 0; i < n; ++i) {
        res[used[i] - 1].push_back(i + 1);
    }
    for(int i = 0; i < ans; ++i) {
        printf("%lld ", (ll)res[i].size());
        for(int j = 0; j < (int)res[i].size(); ++j) printf("%lld ", res[i][j]);
        printf("\n");
    }

    return 0;
}