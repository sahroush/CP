#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e2 + 10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);


int n , m;
vector <int> vec[maxn][maxn];
bool mark[maxn];
int s , e;


void dfs(int v , int c){
    mark[v] = 1;
    for (int i = 0 ; i < vec[v][c].size() ; i++){
        int u = vec[v][c][i];
        if (!mark[u]){
            dfs(u , c);
        }
    }
}


int main (){
    migmig;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
        int a , b , c;
        cin >> a >> b >> c;
        vec[a][c].push_back(b);
        vec[b][c].push_back(a);
    }
    int q;
    cin >> q;
    while (q--){
        cin >> s >> e;
        int ans = 0;
        for (int i = 1;  i <= m; i ++){
            dfs(s , i);
            if (mark[e]){
                ans++;
            }
            fill(mark , mark+maxn , 0);
        }
        cout << ans << endl;
    }




    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
