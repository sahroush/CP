#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5;
const ll ZERO = 0;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , m ;
vector <int> vec[maxn];
bool mark[maxn];
void dfs(int v){
    mark[v] = 1;
    for (int i = 0 ; i < vec[v].size() ; i ++){
        int u= vec[v][i];
        if (!mark[u]){
            dfs(u);
        }
    }
    cout << v << ' ';
}


int main (){
    migmig
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++){
        int x , y;
        cin >> x >> y;
        vec[x].push_back(y);
    }

    for (int i = 1; i <= n ; i ++){
        if (!mark[i]){
            dfs(i);
        }
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
