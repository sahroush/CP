#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll maxn = 2100;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n , m;
pii inp[10];
queue <pii> q;
bool mark[maxn][maxn];

int main (){
    file_init
    migmig
    int k;
    cin >> n >> m >> k;
    for (int i =0 ; i < k; i ++){
        int x , y;
        cin >> x >> y;
        mark[x][y] = 1;
        inp[i] = make_pair(x , y);
        q.push(inp[i]);
    }
    int x , y;
    while (!q.empty()){
        pii v = q.front();
        q.pop();
        x = v.first , y = v.second;
        if (x + 1 <= n and !mark[x+1][y]){
            mark[x+1][y] = 1;
            q.push({x+1 , y});
        }
        if (x - 1 > 0 and !mark[x-1][y]){
            mark[x-1][y] = 1;
            q.push({x-1 , y});
        }
        if (y + 1 <= m and !mark[x][y+1]){
            mark[x][y+1] = 1;
            q.push({x , y+1});
        }
        if (y - 1 > 0 and !mark[x][y-1]){
            mark[x][y-1] = 1;
            q.push({x , y-1});
        }
        if (q.empty()){
            cout << x << ' ' << y;
        }
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you wiint come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
