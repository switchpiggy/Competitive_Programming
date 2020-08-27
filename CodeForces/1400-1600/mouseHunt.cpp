#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)

#define mp make_pair
#define pb push_back

#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define sqr(a) ((a) * (a))

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
    out << "[";
    forn(i, sz(v)) {
        if(i) out << ", ";
        out << v[i];
    }
    return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n;
vector<int> a, c;

inline bool read() {
    if(!(cin >> n))
        return false;
    c.assign(n, 0);
    a.assign(n, 0);

    forn(i, n)
        assert(scanf("%d", &c[i]) == 1);
    forn(i, n) {
        assert(scanf("%d", &a[i]) == 1);
        a[i]--;
    }
    return true;
}

vector< vector<int> > cycles;

vector<char> used;
vector<int> path;

void dfs(int v) {
    path.push_back(v);
    used[v] = 1;

    int to = a[v];
    if(used[to] != 2) {
        if(used[to] == 1) {
            cycles.emplace_back();

            int id = sz(path) - 1;
            while(path[id] != to)
                cycles.back().push_back(path[id--]);
            cycles.back().push_back(to);
        } else
            dfs(to);
    }
    path.pop_back();
    used[v] = 2;
}

inline void solve() {
    used.assign(n, 0);

    forn(i, n) {
        if (!used[i])
            dfs(i);
    }

    li ans = 0;
    for(auto &cur : cycles) {
        int mn = c[cur[0]];
        for(int v : cur)
            mn = min(mn, c[v]);
        ans += mn;
    }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}