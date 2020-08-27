#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
    ll n, k;
    queue<ll> q;
    set<ll> s;
    s.clear();
    scanf("%lld %lld", &n, &k);

    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        if(!s.count(temp)) {
            if(q.size() >= k) {
                s.erase(q.front());
                q.pop();
            }
            q.push(temp);
            s.insert(temp);
        }   
    }

	vector<ll> res;
    res.clear();
    while(!q.empty()) {
		res.push_back(q.front());
		q.pop();
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for(ll i = 0; i < res.size(); ++i) printf("%lld ", res[i]);
}