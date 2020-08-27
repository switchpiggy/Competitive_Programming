#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, p[200005], res[200005];
vector<ll> v;
bool visited[200005];

int main() {
    scanf("%lld", &q);

    while(q--) {
    	memset(visited, 0, sizeof(visited));
        scanf("%lld", &n);
        for(ll i = 1; i <= n; ++i) scanf("%lld", &p[i]);

        for(ll i =1; i <= n; ++i) {
            if(visited[i]) continue;

            ll cur = p[i];
            v.clear();
            v.push_back(i);
            visited[i] = 1;

            while(cur != i) {
                cur = p[cur];
                v.push_back(cur);
                visited[cur] = 1;
            }

            for(ll j = 0; j < v.size(); ++j) res[v[j]] = v.size();
        }

        for(ll i = 1; i <= n; ++i) printf("%lld ", res[i]);

        printf("\n");
    }
    


}