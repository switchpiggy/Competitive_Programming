#include <bits/stdc++.h>

using namespace std;

int main() {

    string t;

    cin >> t;

    deque<char> d;

    int k = t.length() - 1;

    int i = 0;

    for(; i < t.length(); ++i) {

        if(t[i] == '.') {

            d.push_back('.');

            if(i + 1 < t.length()) d.push_back(t[i + 1]);

            else d.push_back('0');

            if(i + 2 < t.length()) d.push_back(t[i + 2]);

            else d.push_back('0');

            k = i - 1;

        }

    }

    if(!d.size()) {

        d.push_back('.'), d.push_back('0'), d.push_back('0');

    }

    int cnt = 0;

    while(k >= 0) {

        if(t[k] == '-') {

            if(d.front() == ',') d.pop_front();

            d.push_back(')');

            d.push_front('$');

            d.push_front('(');

            auto itr = d.begin();

            for(; itr != d.end(); ++itr) {

                cout << *itr;

            }
            
            return 0;

        }

        d.push_front(t[k]);

        cnt++;

        if(cnt == 3) {

            cnt = 0;

            d.push_front(',');

        }

        k--;

    }

    if(d.front() == ',') d.pop_front();

    d.push_front('$');

    auto it = d.begin();

    for(; it != d.end(); ++it) cout << *it;

    

}   