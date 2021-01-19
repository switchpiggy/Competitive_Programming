#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
ld a, b, m, vx, vy, vz, eps = 1e-12;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    cin >> a >> b >> m >> vx >> vy >> vz;
    vx /= -vy;
    vz /= -vy;
    vy = 1.0;
    ld x = a/2, y = m, z = 0;

    while(y > 0) {
        ld nxtX = LLONG_MAX, nxtZ = LLONG_MAX;
        if(vx != 0) {
            if(vx < eps) nxtX = -x/vx;
            else nxtX = (a - x)/vx;
        }

        if(vz != 0) {
            if(vz < eps) nxtZ = -z/vz;
            else nxtZ = (b - z)/vz;
        }

        if(nxtX != LLONG_MAX && nxtX - nxtZ < eps) {
            nxtX = min(y, nxtX);
            y -= nxtX;
            x = x + nxtX * vx;
            z = z + vz * nxtX;
            vx = -vx;
            //vz = -vz;
        } else {
            nxtZ = min(y, nxtZ);
            y -= nxtZ;
            z = z + nxtZ * vz;
            x = x + vx * nxtZ;
            vz = -vz;
            //vx = -vx;
        }
    }

    cout << x << ' ' << z << '\n';
    return 0;
}