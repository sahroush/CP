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

int n , m;

vector < int > vec[maxn];

bool state[maxn] , target[maxn];
int cnt = 0;
bool mark[maxn];
vector <int> ans;
int wtf = 0;

void dfs(int v  , int ftw , int level){
    if (mark[v]) return;
    mark[v] = 1;
    if (level%2 == ftw%2 and ftw!=0){
        state[v] = !state[v];
    }
    if (state[v] != target[v]){
        cnt ++ ;
        ans.push_back(v);
        ftw++;
    }
    for (int u = 0; u < vec[v].size() ; u ++){
        if (!mark[vec[v][u]]){
            dfs(vec[v][u] , ftw , level++);
        }
    }
    return ;
}

int main(){
    migmig;
    cin >> n >> m;
    cout<< n*m/2;

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
