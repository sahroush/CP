/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 2e5 + 1000;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct card{
    int ind;
    int sx=0 , sy=0 , ex=0 , ey=0;
}card[maxn];

int n;
int par[maxn];

vector < int > vec[maxn] , vc;

bool cmp(int i , int j){
    return(card[i].sy > card[j].sy);
}

queue < int > q;

struct seg{
    int seg[maxn*4];
    void build(int v = 1 , int l = 0 , int r = maxn){
        if(r - l == 1){
            seg[v] = vec[l].back();
            return;
        }
        int mid = (l + r)/2;
        build(2*v , l , mid);
        build(2*v + 1 , mid, r);
        if(card[seg[2*v]].sy < card[seg[2*v + 1]].sy)
            seg[v] = seg[2*v];
        else
            seg[v] = seg[2*v + 1];
    }
    void update(int pos , int v = 1 , int l = 0 , int r = maxn){
        if(l > pos or r <= pos)
            return;
        if(r - l == 1){
            if(seg[v] == n + 1)
                return;
            vec[pos].pop_back();
            seg[v] = vec[pos].back();
            return;
        }
        int mid = (l + r)/2;
        update(pos , 2*v , l , mid);
        update(pos , 2*v+1 , mid, r);
        if(card[seg[2*v]].sy < card[seg[2*v + 1]].sy)
            seg[v] = seg[2*v];
        else
            seg[v] = seg[2*v + 1];
    }
    int query(int L , int R , int v = 1 ,  int l = 0 , int r = maxn){
        if(l >= R or r<= L){
            return(n + 1);
        }
        if(L <= l and r <= R){
            return(seg[v]);
        }
        int mid = (l + r)/2;
        int a = query(L , R , 2*v , l , mid);
        int b = query(L , R , 2*v+1 , mid , r);
        if(card[a].sy < card[b].sy)
            return(a);
        return(b);
    }
}seg;

void add(int v){
    int x = card[v].ex+1;
    int y = card[v].ey;    
    int u;
    while(card[(u = seg.query(0 , x))].sy <= y){
        par[u] = v;
        q.push(u);
        seg.update(card[u].sx);
    }
}

int main(){
    migmig
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> card[i].sx >> card[i].sy >> card[i].ex >> card[i].ey;
        card[i].ind = i;
    }
    vc.pb(0);
    for(int i = 1 ; i <= n ; i ++){
        vc.pb(card[i].sx);
        vc.pb(card[i].ex);
    }
    sort(vc.begin() , vc.end());
    vc.resize(unique(vc.begin() , vc.end()) - vc.begin());
    for(int i = 1; i <= n ; i ++){
        card[i].sx = lower_bound(vc.begin() , vc.end() , card[i].sx) - vc.begin();
        card[i].ex = lower_bound(vc.begin() , vc.end() , card[i].ex) - vc.begin();
    }
    
    for(int i = 1 ; i <= n ; i ++ )
        vec[card[i].sx].pb(i);

    card[n + 1].sy = 1e9+100;
    
    for(int i = 0 ; i < maxn ; i ++ )
        vec[i].pb(n + 1),sort(vec[i].begin() , vec[i].end() ,cmp);
    
    fill(par , par + maxn ,  -1);
    
    seg.build();
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        add(cur);
    }
    if(par[n] == -1)
        dokme(-1);
    vector < int > ans;
    int cur = n;
    while(cur!=0){
        ans.pb(cur);
        cur=par[cur];
    }
    cout << ans.size() << endl;
    while(ans.size())
        {
            cout << ans.back() << ' ';
            ans.pop_back();
        }
    
    return(0);
}
