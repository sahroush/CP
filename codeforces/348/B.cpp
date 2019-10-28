#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5 + 10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , val[maxn];
ll ans= 0 , t = 0 , mlt[maxn] , sml[maxn] ;
vector <int> vec[maxn] , child[maxn];
bool mark[maxn] ;

ll gcd( ll a , ll b){
    if (b==0){
        return(a);
    }
    return(gcd(b , a%b));
}
ll calc(ll a ,  ll b){
    if(a==-1){
        return(-1);
    }
    ll gc = gcd(a , b);
    b/=gc;
    if(t/b < a){
        return(-1);
    }
    return(a*b);
}

void dfs(int v , int p){
    mlt[v] =1;
    if (vec[v].size() == 1 and p!=-1){
        sml[v] = val[v];
        return ;
    }
    ll mn = 1e14;
    for (int i = 0 ; i  < vec[v].size() ; i ++){
        int u = vec[v][i];
        if (u == p) continue;

        dfs(u , v);

        mlt[v] = calc(mlt[u] , mlt[v]);
        if(mlt[v] == -1){
            sml[v] = 0;
            return ;
        }
        mn = min(mn , sml[u]);

    }
    int sz = vec[v].size();
    if(v!=1){
        sz--;
    }
    if(t / mlt[v] < sz){
        sml[v] = 0;
        return ;
    }
    sml[v] = (mn - (mn%mlt[v]))*sz;
    mlt[v]*=sz;
}
int main (){
    //migmig;
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> val[i];
        t+=val[i];
    }
    for (int i = 1; i < n ; i ++){
        int x , y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1 , -1);
    ans = t - sml[1];
    cout << ans;
    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
