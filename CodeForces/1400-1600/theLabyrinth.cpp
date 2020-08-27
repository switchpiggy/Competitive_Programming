#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1010;

int n, m;
char a[N][N];

inline bool read() {
	if (!(cin >> n >> m)) return false;
	forn(i, n) assert(scanf("%s", a[i]) == 1);
	return true;
}

int sz[N * N];
int tt, num[N][N];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
	sz[tt]++;
	num[x][y] = tt;

	forn(i, 4) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (min(xx, yy) < 0 || xx >= n || yy >= m) continue;
		if (num[xx][yy] != -1 || a[xx][yy] != '.') continue;
		dfs(xx, yy);
	}
}

char ans[N][N];

inline void solve() {
	tt = 0;
	forn(i, n) forn(j, m) num[i][j] = -1;

	forn(i, n)
		forn(j, m)
			if (num[i][j] == -1 && a[i][j] == '.') {
				sz[tt] = 0;
				dfs(i, j);
				tt++;
			}

#ifdef SU1
	forn(i, n) {
		forn(j, m) cerr << num[i][j] << ' ';
		cerr << endl;
	}
#endif

	forn(i, n)
		forn(j, m) {
			if (a[i][j] == '.') {
				ans[i][j] = '.';
				continue;
			}
			int cur[4] = { -1, -1, -1, -1 };
			forn(k, 4) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (min(x, y) < 0 || x >= n || y >= m) continue;
				if (a[x][y] != '.') continue;
				cur[k] = num[x][y];
			}
			sort(cur, cur + 4);
			int szcur = int(unique(cur, cur + 4) - cur);
			int ans = 1;
			forn(k, szcur)
				if (cur[k] != -1)
					ans += sz[cur[k]];
			ans %= 10;
			::ans[i][j] = char('0' + ans);
		}

	forn(i, n) puts(ans[i]);
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    while (read()) {
		solve();
		//break;
	}
	
    return 0;
}