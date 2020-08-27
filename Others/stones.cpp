#include <bits/stdc++.h>

using namespace std;

int main() {

    int length, count = 0;

    scanf("%d", &length);

    vector<char> s;

    for(int i = 0; i < length; ++i) {

        char c;

        cin >> c;

        s.push_back(c);

    }   

    for(int i = 1; i < length; ++i) {

        if(s[i] == s[i - 1]) {

            count++;

        }

    }

    printf("%d\n", count);   

}