#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, t;
vector<pair<ll, pair<ll, ll>>> cows;
set<pair<ll, ll>> wait;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &k, &t);
        cows.push_back(make_pair(k, make_pair(i, t)));
    }

    ll ans = 0;

    sort(cows.begin(), cows.end());

    ll nxt = 1, cur_finished = cows[0].first + cows[0].second.second;

    while(!wait.empty() || nxt < n) {
        while(nxt < n && cows[nxt].first <= cur_finished) {
            wait.insert(make_pair(cows[nxt].second.first, nxt));
            nxt++;
        }

        if(wait.empty() && nxt < n) {
            cur_finished = cows[nxt].first + cows[nxt].second.second;
            nxt++;
        } else if(!wait.empty()) {
            auto itr = wait.begin();
            ans = max(ans, cur_finished - cows[itr->second].first);
            cur_finished += cows[itr->second].second.second;
            wait.erase(itr);
        }
    }

    printf("%lld\n", ans);

    return 0;
}