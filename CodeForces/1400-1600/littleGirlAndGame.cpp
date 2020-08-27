#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;

    map<char, int> m;

    cin >> s;

    int i = 0;
    
    int a = 0;

    for(int i= 0; i < s.length(); ++i) m[s[i]]++;

    for(auto itr = m.begin(); itr != m.end(); ++itr) {

        if(itr->second % 2 == 1) a++;

    }

   

    if(a%2 == 1 || a == 0) cout <<"First" <<  endl;

    else cout << "Second" << endl;



}