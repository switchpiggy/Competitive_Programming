#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, t, l, tim, team, problem, input, score;
vector<pair<ll, pair<ll, ll>>> scores(100005);
set<pair<ll, pair<ll, ll>>> done;

bool comp(pair<ll, pair<ll, ll>> x, pair<ll, pair<ll, ll>> y) {
    return x.second.second < y.second.second;
}

bool comp2(pair<ll, pair<ll, ll>> x, pair<ll, pair<ll, ll>> y) {
    return x.second.first > y.second.first;
}

bool comp3(pair<ll, pair<ll, ll>>x, pair<ll, pair<ll, ll>> y) {
    return x.first < y.first;
}

void eval(ll tim, ll team, ll problem, ll input, ll score) {
    if(score == 1  && done.find(make_pair(team, make_pair(problem, input))) == done.end()) {
        scores[team].second.first += input * 100;
        done.insert(make_pair(team, make_pair(problem, input)));
        scores[team].second.second += tim;
    }
    return;
}

int main() {
    freopen("scoreboard.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    scanf("%lld", &t);
    for(ll count = 1; count <= t; ++count) {
        scanf("%lld %lld", &n, &l);
        done.clear();

        for(ll i = 1; i <= 100005; ++i) {
            scores[i].first = i;
            scores[i].second.first = 0;
            scores[i].second.second = 0;
        }

        for(ll i = 0; i < l; ++i) {
            scanf("%lld %lld %lld %lld %lld", &tim, &team, &problem, &input, &score);
            eval(tim, team, problem, input, score);
        }

        sort(scores.begin() + 1, scores.begin() + n + 1, comp2);
        for(ll i = 1; i <= n; ++i) {
            ll j = i;
            if(scores[i].second.first == scores[j].second.first) while(scores[i].second.first == scores[j].second.first && j <= n) j++;
            sort(scores.begin() + i, scores.begin() + j, comp);
        }
        for(ll i = 1; i <= n; ++i) {
            ll j = i;
            if(scores[i].second.first == scores[j].second.first && scores[i].second.second == scores[j].second.second && j <= n) while(scores[i].second.first == scores[j].second.first && scores[i].second.second == scores[j].second.second && j <= n) j++;
            sort(scores.begin() + i, scores.begin() + j, comp3);

        }
        printf("Case #%lld: ", count);
        for(ll i = 1; i <= n; ++i) printf("%lld ", scores[i].first);
        printf("\n");
    }

    return 0;
}