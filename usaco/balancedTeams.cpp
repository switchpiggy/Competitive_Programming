#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll playerCount[4], team[16], skill[16], ans = INT_MAX;

void backtrack(ll cur) {
    if(cur == 16) {
        ll teamSkill[4];
        for(ll i = 0; i < 16; ++i) teamSkill[team[i]] += skill[i];

        ll maxs = max(max(teamSkill[0], teamSkill[1]), max(teamSkill[2], teamSkill[3]));
        ll mins = min(min(teamSkill[0], teamSkill[1]), min(teamSkill[2], teamSkill[3]));

        ans = min(ans, maxs - mins);
    }

    for(ll i = 0; i < 4; ++i) {
        if(playerCount[i] < 4) {
            playerCount[i]++;
            team[cur] = i;
            backtrack(cur + 1);
            playerCount[i]--;
        }
    }
}

int main() {
    for(ll i = 0; i < 16; ++i) scanf("%lld", &skill[i]);
    backtrack(0);

    printf("%lld\b", ans);

    return 0;
}