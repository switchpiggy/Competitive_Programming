#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, nxt[100005];
bool visited[100005];
vector<ll> ans;

void dfs(ll x) {
    ll a = 0;
    stack<ll> s;
    s.push(x);

    while(!s.empty()) {
        ll t = s.top();
        //cout << t << endl;
        s.pop();
        
        if(visited[t]) {
            ans.push_back(a);
            return;
        }
        visited[t] = 1;
        a++;

        s.push(nxt[t]);
    }
    return;
}

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &nxt[i]);
    }

    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) dfs(i);
    }
    sort(ans.begin(), ans.end());

    if(ans.size() == 1) {
        printf("%lld\n", ans[0] * ans[0]);
        return 0;
    }

    ll count = 0;
    for(ll i = 0; i < ans.size() - 2; ++i) {
        count += ans[i] * ans[i];
    }

    count += (ans[ans.size() - 1] + ans[ans.size() - 2]) * (ans[ans.size() - 1] + ans[ans.size() - 2]);

    printf("%lld", count);

}