#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n, temp;
        cin >> n;
        vi odds;
        bool flag = false;
        for(int i = 0; i < n; ++i) {
            cin >> temp;
            if(temp%2 == 0 && !flag) {
                flag = true;
                printf("1\n%d\n", i + 1);
            } else odds.push_back(i + 1);
        }
        if(!flag && odds.size() >= 2) printf("2\n%d %d\n", odds[0], odds[1]);
        else if(!flag) printf("-1\n");
    }

}