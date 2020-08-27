#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

map<ll, ll> occurence;

bool checkAlien() {

    for(auto itr = occurence.begin(); itr != occurence.end(); ++itr) {
        if(itr->second >= 4) {
            itr->second -= 4;
            return true;
        }
    }

    return false;

}

int main() {

    ll temp;
    for(int i = 0; i < 6; ++i) {
        scanf("%lld", &temp);
        occurence[temp]++;
    }

    if(!checkAlien()) {
        printf("Alien");
        return 0;
    }

    bool flag = false;

    for(auto itr = occurence.begin(); itr != occurence.end(); ++itr) {
        if(itr->second == 2) {
            printf("Elephant");
            flag = true;
            break;
        }
    }

    if(!flag) printf("Bear");

}