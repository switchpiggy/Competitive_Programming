#include <bits/stdc++.h>
using namespace std;

//Find out the position we need each element in a to be in, and then find the first number that is less than the previous, and the last number that is more than the next. Then, reverse the array between these numbers, and find out if it is sorted.
// Sometimes, when we cannot find a simple solution, use a more complex solution that is still in the restrictions of the problem.
// NOTE: std::reverse(iterator1, iterator2) reverses the array between two elements. 

typedef long long int ll;

ll n, a[100005], l = -1, r = -1, sorted[100005];
map<ll, ll> pos;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        sorted[i] = a[i];
    }

    sort(sorted, sorted + n);

    for(ll i = 0; i < n; ++i) {
        pos[sorted[i]] = i;
    }

    for(ll i = 0; i < n; ++i) {
        a[i] = pos[a[i]];
    }

    for(ll i = n - 1; i >= 0; --i) {
        if(a[i] != i) {
            r = i;
            break;
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(a[i] != i) {
            l = i;
            break;
        }
    }

    if(r == -1 || l == -1) {
        printf("yes\n1 1\n");
    } else {
        reverse(a + l, a + r + 1);
        bool flag = true;
        
        for(ll i = 0; i < n; ++i) {
            if(a[i] != i) {
                flag = false;
                break;
            }
        }

        if(!flag) printf("no\n");
        else {
            printf("yes\n%lld %lld\n", l + 1, r + 1);
        }
    }


}