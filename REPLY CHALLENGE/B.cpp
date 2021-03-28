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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
#define point complex<ld>
#define X real()
#define Y imag()

void fileIO() {
    freopen("test.txt", "w", stdout);
    freopen("input-party-5923.txt", "r", stdin);
}

template<class T> struct seg {
    complex<T> a, b;
    seg() {}
    seg(complex<T> x, complex<T> y) {
        a = x, b = y;
    }

    T len() {
        return dist(a, b);   
    }
};

bool comp(point a, point b) {
    if(a.X == b.X) return a.Y < b.Y;
    return a.X < b.X;
}

template<class T> T norm(complex<T> a, complex<T> b) {return norm(a - b);}
template<class T> T dist(complex<T> a, complex<T> b) {return abs(a - b);}
template<class T> T dot(complex<T> a, complex<T> b) {return (conj(a) * b).X;}
template<class T> T cross(complex<T> a, complex<T> b) {return (conj(a) * b).Y;}
template<class T> T slope(complex<T> a, complex<T> b) {return tan(arg(b - a));}
template<class T> void rot(complex<T> &a, T theta) {a = a * polar(1.0, theta);}
template<class T> bool collinear(complex<T> a, complex<T> b) {return (cross(a, b) == 0);}
template<class T> bool collinear(complex<T> a, complex<T> b, complex<T> c) {return collinear(b - a, c - b);}
template<class T> bool ccw(complex<T> a, complex<T> b) {return cross(a, b) > 0;}
template<class T> bool ccw(complex<T> a, complex<T> b, complex<T> c) {return ccw(b - a, c - a);}
template<class T> void rot_p(complex<T> &a, T theta, complex<T> p) {a = (a - p) * polar(1.0, theta) + p;}
template<class T> void read(complex<T> &a) {
    T x, y;
    cin >> x >> y;
    a.real(x);
    a.imag(y);
}

template<class T> bool intersect(seg<T> x, seg<T> y) {
    if(x.a == y.a || x.a == y.b || x.b == y.a || x.b == y.b) return 1;
    if(collinear(x.a, x.b, y.a) && collinear(y.b, x.a, x.b) && collinear(x.a, y.a, y.b) && collinear(x.b, y.a, y.b)) {
        vector<point> v = {x.a, x.b, y.a, y.b};
        sort(all(v), comp);
        if((v[0] == x.a && v[1] == x.b) || (v[1] == x.a && v[0] == x.b)) return 0;
        if((v[0] == y.a && v[1] == y.b) || (v[1] == y.a && v[0] == y.b)) return 0;

        return 1;
    }
    ll c = cross(x.b - x.a, y.a - x.a), d = cross(x.b - x.a, y.b - x.a), e = cross(y.b - y.a, x.a - y.a), f = cross(y.b - y.a, x.b - y.a);
    if(c) c /= abs(c);
    if(d) d /= abs(d);
    if(e) e /= abs(e);
    if(f) f /= abs(f);
    return (c != d) && (e != f);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ":" << " ";
        
    }
}