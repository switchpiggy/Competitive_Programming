#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, nike = 0, poly = 0;
string a, b, x, y;

void processRound(char c, char d) {
    if(c == d) return;
    if(c == 'P' && d == 'R') nike++;
    else if(c == 'S' && d == 'P') nike++;
    else if(c == 'R' && d == 'S') nike++;
    else if(d == 'P' && c == 'R') poly++;
    else if(d == 'S' && c == 'P') poly++;
    else if(d == 'R' && c == 'S') poly++;

    return;
}

int main() {
    scanf("%lld", &n);
    cin >> a >> b;

    ll gcf = (a.length() * b.length())/__gcd(a.length(), b.length());

    while(x.length() != gcf) x += a;
    while(y.length() != gcf) y += b;

    for(ll i = 0; i < gcf; ++i) {
        processRound(x[i], y[i]);
    }

    nike *= n/gcf;
    poly *= n/gcf;

    for(ll i = 0; i < n%gcf; ++i) {
        processRound(x[i], y[i]);
    }

    printf("%lld %lld\n", poly, nike);
    return 0;
}