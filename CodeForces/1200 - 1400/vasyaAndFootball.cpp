#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, player, t;
string homeN, awayN;
char team, card;
map<ll, ll> home, away;

int main() {
    cin >> homeN >>  awayN;
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> t >> team >> player >> card;
        if(team == 'a') {
            if(card == 'y') away[player]++;
            if(away[player] == 2 || (card == 'r' && away[player] < 2)) {
                away[player] = 3;
                cout << awayN << ' ' << player << ' ' << t << endl;
            }
        } else {
            if(card == 'y') home[player]++;
            if(home[player] == 2 || (card == 'r' && home[player] < 2)) {
                home[player] = 3;
                cout << homeN << ' ' << player << ' ' << t << endl;
            }
        }     
    }

    return 0;
}