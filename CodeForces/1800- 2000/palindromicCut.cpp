#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
map<char, ll> occ;
vector<string> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        occ[s[i]]++;
    }

    bool ok = 0;
    char odd = '.';
    for(auto a = occ.begin(); a != occ.end(); ++a) {
        char i = a->first;
        if(occ[i]%2 == 1) {
            if(!ok) {
                ok = 1;
                odd = i;
                continue;
            }

            res.push_back(string(occ[i], i));
            occ[i] = 0;
        }
    }

    deque<char> q;
    while(occ[odd]) {
        occ[odd]--;
        q.push_front(odd);
    }

    for(auto a = occ.begin(); a != occ.end(); ++a) {
        char i = a->first;
        while(occ[i]) {
            q.push_back(i);
            q.push_front(i);
            occ[i] -= 2;
        }
    }

    cout << (ll)res.size() + !q.empty() << '\n';
    for(ll i = 0; i < (ll)res.size(); ++i) cout << res[i] << ' ';
    while(!q.empty()) {
        cout << q.front();
        q.pop_front();
    }

    return 0;
}