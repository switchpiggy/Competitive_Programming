#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool visited[200005];

int main() {
    string s, t;
    map<char, int> cnt;
    ll yay = 0, whoops = 0;

    cin >> s >> t;
    for(ll i = 0; i < t.length(); ++i) {
    	cnt[t[i]]++;
    	//cout << t[i] << endl;
    }

    for(ll i = 0; i < s.length(); ++i) {
        if(cnt[s[i]]) {
            cnt[s[i]]--;
            yay++;
            visited[i] = 1;
            continue;
        }
    }

    for(ll i = 0; i < s.length(); ++i) {
        if(visited[i]) continue;

        char c = s[i];
        if(islower(c)) c = toupper(c);
        else c = tolower(c);
        
        //cout << c << ' ' << cnt[c] << ' ' << endl;

        if(cnt[c]) {
            cnt[c]--;
            whoops++;
        }
    }

    printf("%lld %lld", yay, whoops);
}