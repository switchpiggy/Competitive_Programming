#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
long double x;

long double apothem(long double x) {
    return 1.000000/(2.000000 * tan((180.000000/x) * 3.1415926535/180.000000));
}

long double radius(long double x) {
    return 1.000000/(2.000000 * sin((180.000000/x) * 3.1415926535/180.000000));
}

int main() {
    scanf("%lld", &n);
    while(n--) {
        cin >> x;
        //cout << x << endl;
        cout << fixed << setprecision(16) << radius(x * 2.000000) * 2.000000 << endl;
    }    

    return 0;
}