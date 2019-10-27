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


int n , m , p , ans = -1;
vector <int> vec[maxn] , start ;
bool mark [maxn];

void dfs(int v , int dist){
    mark[v] = 1;
    ans = max(ans , dist);
    for (int i = 0 ; i < vec[v] . size() ;i ++){
        int u = vec[v][i];
        if (!mark[u]){
            dfs(u , dist+1);
        }
    }
}

int main (){
    migmig;
    cin >> n;
    for (int i = 1; i <= n ; i++){
        cin >> p;
        if(p == -1){
            start.push_back(i);
        }
        else{
            vec[p].push_back(i);
            vec[i].push_back(p);
        }
    }
    for (int i = 0 ; i < start.size() ; i++){
        dfs(start[i] , 1);
    }
    cout << ans;

    return (0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
