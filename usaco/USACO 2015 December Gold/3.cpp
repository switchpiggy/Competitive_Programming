#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}, n, m, dist[10000001];

struct state {
    ll x, y, dir;
    bool smell;

    ll comp() {
        return smell + 2 * dir + 10 * y + 10000 * x;
    }

    state(ll g, ll b, ll c, bool d) {
        x = g;
        y = b;
        dir = c;
        smell = d;
    }

    static state decomp(ll x) {
        return state(x/10000, (x/10)%1000, (x/2)%5, x%2);
    }

    ll cell(const vector<vector<ll>>& a, ll c, ll b) {
        if(c < 0 || c >= n || b < 0 || b >= m) return -1;
        return a[c][b];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) cin >> a[i][j];
    }

    for(ll i = 0; i <= 10000000; ++i) dist[i] = -1;
    queue<ll> q;

    ll init = state(0, 0, 0, 0).comp();
    q.push(init);
    dist[init] = 0;

    while(!q.empty()) {
        ll f = q.front();
        state st = state::decomp(f);
        q.pop();

        if(st.x == n - 1 && st.y == m - 1) {
            cout << dist[st.comp()] << '\n';
            return 0;
        }

        if(a[st.x][st.y] == 4 && st.dir) {
            ll cur = st.cell(a, st.x + dx[st.dir - 1], st.y + dy[st.dir - 1]);
            if(cur != -1 && cur != 3 && cur != 0) {
                state nxt = state(st.x + dx[st.dir - 1], st.y + dy[st.dir - 1], st.dir, cur == 2);
                if(dist[nxt.comp()] != -1) continue;
                dist[nxt.comp()] = dist[st.comp()] + 1;
                q.push(nxt.comp());
                continue;
            }
        }

        for(ll i = 0; i < 4; ++i) {
            ll cur = st.cell(a, st.x + dx[i], st.y + dy[i]);
            if(cur == 3 && !st.smell) continue;
            if(cur == -1 || cur == 0) continue;

            state nxt = state(st.x + dx[i], st.y + dy[i], i + 1, (st.smell || cur == 2) && cur != 4);
            if(dist[nxt.comp()] != -1) continue;
            dist[nxt.comp()] = dist[st.comp()] + 1;
            q.push(nxt.comp()); 
        }

    }

    cout << "-1\n";
    return 0;
}