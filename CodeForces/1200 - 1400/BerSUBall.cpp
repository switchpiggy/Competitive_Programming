#include <bits/stdc++.h>

using namespace std;

int main() {

    int b, g;

    int count = 0;

    vector<int> boy, girl;

    scanf("%d", &b);

    for(int i = 0; i < b; ++i) {

        int c;

        scanf("%d", &c);

        boy.push_back(c);

    }

    scanf("%d", &g);

    for(int i = 0; i < g; ++i) {

        int c;

        scanf("%d", &c);

        girl.push_back(c);

    }

    sort(boy.begin(), boy.end());

    sort(girl.begin(), girl.end());

    for(int i = 0; i < b; ++i) {

        for(int j = 0; j < g; ++j) {

            if(abs(boy[i] - girl[j]) <= 1) {

                count++;

                girl[j] = 1000;

                break;

            } 

        }

    }

    printf("%d", count);

} 