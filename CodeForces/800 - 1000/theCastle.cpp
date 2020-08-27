
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct Tile  Tile;

ll height, width;

const int west = 1;
const int east = 4;
const int north = 2;
const int south = 8;

struct Tile {
    ll visited = 0;
    ll room;
    ll wall;
};

ll roomsize[2505];

Tile castle[55][55];

void floodfill(ll x, ll y, ll room) {
    if(castle[x][y].visited) {
    	assert(castle[x][y].room == room);
        return;
    }

    castle[x][y].visited = 1;
    castle[x][y].room = room;

    roomsize[room]++;

    ll w = castle[x][y].wall;

    if(x > 0 && !(w & west)) floodfill(x - 1, y, room);
    if(x + 1 < width && !(w & east)) floodfill(x + 1, y, room);
    if(y > 0 && !(w & north)) floodfill(x, y - 1, room);
    if(y + 1 < height && !(w & south)) floodfill(x, y + 1, room);
}

int main() {

    ll rooms = 0, maxRoom = -1, rx, ry, ans = 0, temp;
    char rDir;

    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    //input routine
    scanf("%lld %lld", &width, &height);
    for(ll j = 0; j < height; ++j) {
        for(ll i = 0; i < width; ++i) {
        	scanf("%lld", &temp);
        	castle[i][j].wall = temp;
        }
    }

    for(ll i = 0; i < width; ++i) {
        for(ll j = 0; j < height; ++j) {
            if(!castle[i][j].visited) {
				floodfill(i, j, rooms++);
            }
        }
    }

    maxRoom = roomsize[0];;

    for(ll i = 1; i < rooms; ++i) {
        maxRoom = max(maxRoom, roomsize[i]);
    }

    //check removing Northern and Eastern walls of each compartment

    for(ll i = 0; i < width; ++i) {
        for(ll j = height - 1; j >= 0; --j) {

            if(j > 0 && castle[i][j].room != castle[i][j - 1].room) {
                ll n =roomsize[castle[i][j].room] + roomsize[castle[i][j - 1].room];
                if(n > ans) {

                    ans = n;

                    rx = i;

                    ry = j;

                    rDir = 'N';
                }
            }

            if(i < width - 1 && castle[i][j].room != castle[i + 1][j].room) {
                ll n = roomsize[castle[i][j].room] + roomsize[castle[i + 1][j].room];
                if(n > ans) {

                    ans = n;

                    rx = i;

                    ry = j;

                    rDir = 'E';
                }

            }

        }
    }

    printf("%lld\n", rooms);
    printf("%lld\n", maxRoom);
    printf("%lld\n", ans);
    printf("%lld %lld %c\n", ry + 1, rx + 1, rDir);
}
