#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dominance true
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b, ll md = mod) {
    ll res = 1;while(b){if(b&1){res=(a*res)%mod;}a=(a*a)%mod;b>>=1;}return(res);
}

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


struct line{
    int l , r , id;
};

int n;
int l[maxn] , r[maxn];
vector < int > vecl , vecr;
map< int , int >  posl , posr;
vector < line > s;
int ans[maxn];

indexed_set st;

bool cmp(line i , line j){
    return(i.l < j.l);
}

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < n; i ++){
        cin >> l[i] >> r[i];
        vecl.pb(l[i]);
        vecr.pb(r[i]);
        line ln;
        ln.l = l[i] , ln.r = r[i] , ln.id = i;
        s.pb(ln);
    }
    sort(s.begin() , s.end() , cmp);
    sort(vecl.begin() , vecl.end());
    sort(vecr.begin() , vecr.end());
    for (int i = 0 ; i < n ; i ++){
        posl[vecl[i]] = n- (i+1);
        posr[vecr[i]] = (i);
    }
    for (int i = 0 ; i < n ; i ++){
        st.insert(r[i]);
    }
    for (int i = 0 ; i < n ; i ++){
        ans[s[i].id] =  st.order_of_key(s[i].r);
        st.erase(s[i].r);
    }
    for (int i = 0 ; i < n ; i ++){
        cout << ans[i] << endl;
    }




    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
