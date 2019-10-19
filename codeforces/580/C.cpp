#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , m;
bool cat[maxn];
vector < int > vec[maxn];

int val[maxn];
int cnt = 0;
bool mark[maxn];

void dfs(int v){

    if (cat[v-1] ) {
        val[v]++;
    }
    else if (val[v] <= m){
        val[v] = 0;
    }
    mark[v] = 1;
    bool f = 0;
    for (int u = 0; u < vec[v].size() ; u ++){
        if (!mark[vec[v][u]]){
            val[vec[v][u]] = max(val[vec[v][u]] , val[v]);

            dfs(vec[v][u]);
            f = 1;
        }
    }
    if (f == 0 ){
        if (val[v] <= m){
            cnt++;
        }
    }
    return ;
}

int main(){
    migmig
    fill(val , val+maxn , 0);
    fill(cat , cat + maxn , 0);
    fill(mark , mark+maxn , 0);
    cin >> n >> m;
    for (int i = 0  ; i  < n ; i ++){
        cin >> cat[i];
    }
    int x , y;
    for (int i =0 ; i < n-1 ; i  ++ ){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);

    }
    dfs(1);
    
    cout << cnt;
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
