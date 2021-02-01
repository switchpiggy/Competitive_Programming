#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238
#define flout cout << fixed << setprecision(12)
ld a, b, h, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    flout;
    cin >> a >> b >> h >> m;
    ld mins = (60 * h + m) * 6;
    ld hours = mins/12;
    cout << sqrt((a * cos(mins * PI/180) - (b * cos(hours * PI/180))) * (a * cos(mins * PI/180) - (b * cos(hours * PI/180)))  + (a * sin(mins * PI/180) - (b * sin(hours * PI/180))) * (a * sin(mins * PI/180) - (b * sin(hours * PI/180)))) << '\n';
    return 0;
}