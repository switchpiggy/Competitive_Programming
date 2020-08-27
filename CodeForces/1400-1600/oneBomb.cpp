#include <bits/stdc++.h>
 
using namespace std;
 
#define IoFast ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long int
#define float long double
#define foor(i, a, b) for ( int (i) = (a); (i)<(b); (i)++ )
#define foor2(i, a, b) for( int (i) = (a); (i)>(b); (i)-- )
#define foorl(i, a, b) for ( ll (i) = (a); (i)<(b); (i)++ )
#define foorl2(i, a, b) for( ll (i) = (a); (i)>(b); (i)-- )
#define mp make_pair
#define f1 first
#define f2 second
#define pb push_back
#define pii pair<int,int>
#define vpii vector <pii>
#define vi vector<int>
#define sz(a) (int) a.size( )
#define fillArr(n, a) foor(i, 0, n) cin >> a[i];
#define print(a) cout << #a << endl;
#define umax(a,b) a = max ( a, b )
#define umin(a,b) a = min ( a, b )
#define all(k) k.begin ( ), k.end( )
#define rall(k) k.rbegin ( ), k.rend( )
#define clean(k) memset( k, 0, sizeof(k) )
#define endl '\n'
 
int n,m,X;
const int maxn = 1e3 + 20;
int x[maxn], y[maxn];
 
int main(){
	IoFast;
	cin >> n >> m;
	string ar[n];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ar[i] = s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '*'){
				X ++;
				x[j] ++;
				y[i] ++;
			}
		}
	}
	if (X == 0){
		cout << "YES\n1 1" << endl;
		return 0;
	}
	bool ans = 0;
	int x1,x2;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (((ar[i][j] == '*' && x[j] + y[i] == X + 1 ) || (ar[i][j] == '.' && x[j] + y[i] == X ))  && !ans ){
				//cout << i << " " << j << endl;
				ans = 1;
				x1 = j + 1;
				x2 = i + 1;
			}
		}
	}
	if (ans){
		cout << "YES"  << endl;
		cout << x2 << " " << x1 << endl;
	}
	else
		cout << "NO" << endl;
 
	//cout << x[0] << " " << y[0] << endl;
}