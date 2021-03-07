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
#define point complex<ll>
#define X real()
#define Y imag()

template<class T> T norm(complex<T> a, complex<T> b) {return norm(a - b);}
template<class T> T dist(complex<T> a, complex<T> b) {return abs(a - b);}
template<class T> T dot(complex<T> a, complex<T> b) {return (conj(a) * b).X;}
template<class T> T cross(complex<T> a, complex<T> b) {return (conj(a) * b).Y;}
template<class T> T slope(complex<T> a, complex<T> b) {return tan(arg(b - a));}
template<class T> void rot(complex<T> &a, T theta) {a = a * polar(1.0, theta);}
template<class T> bool collinear(complex<T> a, complex<T> b) {
    return (cross(a, b) == 0);
}
template<class T> bool collinear(complex<T> a, complex<T> b, complex<T> c) {
    return collinear(b - a, b - c);
}
template<class T> bool cw(complex<T> a, complex<T> b) {
    return cross(a, b) < 0;
}
template<class T> bool cw(complex<T> a, complex<T> b, complex<T> c) {
    return cw(b - a, c - b);
}
template<class T> void rot_p(complex<T> &a, T theta, complex<T> p) {a = (a - p) * polar(1.0, theta) + p;}
template<class T> void read(complex<T> &a) {
    T x, y;
    cin >> x >> y;
    a.real(x);
    a.imag(y);
}

ll t;
point x, y, z;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        read(x);
        read(y);
        read(z);
        // cout << x << ' ' << y << ' ' << z << '\n';
        bool c = collinear(x, y, z);
        if(c == 1) cout << "TOUCH\n";
        else {
            c = cw(x, z, y);
            if(c) cout << "LEFT\n";
            else cout << "RIGHT\n";
        }
    }

    return 0;
}