#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, totSleep, fAlarm, alarm, fallTime;

int main() {
    scanf("%lld", &n);
    while(n--) {
        scanf("%lld %lld %lld %lld", &totSleep, &fAlarm, &alarm, &fallTime);
        if(totSleep <= fAlarm) {
            printf("%lld\n", fAlarm);
            continue;
        }

        if(fallTime >= alarm) {
            printf("-1\n");
            continue;
        }

        printf("%lld\n", fAlarm + ((totSleep - fAlarm) + (alarm - fallTime) - 1)/(alarm - fallTime) * (alarm));
    }

    return 0;
}