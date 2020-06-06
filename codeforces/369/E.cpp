#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

struct trio{
    int l , r , ind = 0;
};

int n , m;
trio seg[maxn];
int ans[maxn];
int fen[maxn];

bool cmp (trio i , trio j){
    if(i.l==j.l){
        if(i.r==j.r)
            return(i.ind < j.ind);
        else
            return(i.r < j.r);
    }
    return(i.l > j.l);
}

void add(int pos){
    for(;pos<maxn;pos+=pos&(-pos))
        fen[pos]++;
}

int get(int pos){
    int ans = 0;
    for(;pos;pos-=pos&(-pos))
        ans+=fen[pos];
    return(ans);
}

int main(){
    migmig
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i ++)
        cin >> seg[i].l >> seg[i].r;
    int sz = n;
    for(int i = 1 ; i <= m ; i ++){
        int x , l , r;
        cin >> x >> l;
        if(l > 1)
            seg[++sz] = (trio){1 , l - 1 , i};
        r = l;
        for(int j = 0 ; j < x-1 ; j ++){
            cin >> r;
            if(l + 1 <= r - 1)
                seg[++sz] = (trio){l + 1 , r - 1 , i};
            l = r;
        }
        seg[++sz] = (trio){r + 1 , maxn-1000 , i};
    }
    sort(seg + 1 , seg + sz + 1 , cmp);
    for(int i = 1 ; i <= sz ; i ++)
        if(seg[i].ind)
            ans[seg[i].ind]+=get(seg[i].r);
        else
            add(seg[i].r);
    for(int i = 1 ; i <= m ; i ++)
        cout << n - ans[i] << endl;
    return(0);
}