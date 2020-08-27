#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, a, b, c;
vector<pair<ll, ll>> v;
bool visited[105];

bool isEdge(ll a, ll b, ll c, ll d) {
	if((c < a && a < d) || (c < b && b < d)) return true;
    return false;
}

bool dfs(ll cur, ll goal) {
	//printf("OK %lld\n",cur);
    if(cur == goal) return true;

	visited[cur] = 1;
    for(int i = 0; i < v.size(); ++i) {
        if(!visited[i] && i != cur && isEdge(v[cur].first, v[cur].second, v[i].first, v[i].second)) {
            if(dfs(i, goal)) return true; 
        } 
    }

    return false;
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);

        if(a == 1) v.push_back(make_pair(b, c));

        if(a == 2) {
        	memset(visited, 0, sizeof(visited));
            if(dfs(b - 1, c - 1)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}