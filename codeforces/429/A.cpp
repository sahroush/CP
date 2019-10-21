#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , m ;
vector < int > vec[maxn];
bool state[maxn] , target[maxn];
int cnt = 0;
int dist[maxn];
bool mark[maxn];
vector <int> ans;

void dfs2(int v  ,int  cntodd ,int  cnteven ){
    if (mark[v]) return;
    if (dist[v]%2 == 0 and cnteven%2 == 1){
        state[v] = !state[v];
    }
    else if (dist[v]%2 ==1 and cntodd%2 == 1){
        state[v] = !state[v];
    }
    if (state[v]!= target[v]){
        state[v] = target[v];
        cnt++;
        ans.push_back(v);
        if (dist[v]%2 == 0){
            cnteven++;
        }
        else{
            cntodd++;
        }
    }
    mark[v] = 1;
    for (int u = 0; u < vec[v].size() ; u ++){
        if (!mark[vec[v][u]]){
            dfs2(vec[v][u] , cntodd , cnteven);
        }
    }
    return ;
}

void dfs1(int v  , int  cntdist){
    if (mark[v]) return;
    mark[v] = 1;
    dist[v] = cntdist;
    cntdist++;
    for (int u = 0; u < vec[v].size() ; u ++){
        if (!mark[vec[v][u]]){
            dfs1(vec[v][u] , cntdist);
        }
    }
    return ;
}

int main(){
    migmig;
    fill(state , state + maxn , 0);
    fill(target , target + maxn , 0);
    fill(mark , mark + maxn , 0);
    cin >> n;
    int x , y;
    for (int i = 0 ; i  < n-1 ; i ++){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i = 1 ; i <= n ; i ++){
        cin >> state[i];
    }
    for (int i = 1 ; i <= n ; i ++) cin >> target[i];
    dfs1(1 , 0 );
    fill(mark , mark + maxn , 0);
    dfs2(1 , 0 , 0 );
    cout << cnt << endl;
    for (int i = 0 ; i < cnt ; i ++){
        cout << ans[i] << '\n';
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
