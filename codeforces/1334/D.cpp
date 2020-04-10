#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q;
ll n , l , r;
vector <int> ans;
ll sum;

void make(int x){
    int cur = x+1;
    for(int i = 0 ; i < 100000 ; i ++){
        ans.pb(x);
        ans.pb(cur);
        if(cur == n){
            x++;
            cur = x + 1;
            if(x == n){
                break;
            }
        }
        else{
            cur++;
        }
    }
}

bool chk(ll x){
    sum = 0;
    for(int i = 1 ; i < x ; i ++){
        sum+=2*(n - i);
    }
    return(sum < l);
}

int main(){
    migmig
    cin >> q;
    while(q --){
        cin >> n;
        cin >> l >> r;
        //(1 , 2) (1 , 3) (1 , 4) (2 , 3) (2 , 4) (3 , 4) + "1"
        //1:2(n-1) , 2:2(n-2) , 3:3(n-3)
        //find teritory
        //make it
        //print
        //find(o(nlogn)) , make(o(n))
        if(l == n*(n - 1)+1){
            cout << 1 << endl;
            continue;
        }
        ll lb = 1 , rb = n - 1;
        while(rb - lb > 1){
            ll mid = (lb + rb)/2;
            if(chk(mid)){
                lb = mid;
            }
            else{
                rb = mid;
            }
        }
        ans.clear();
        make(lb);
        if(r == n*(n - 1)+1){
            ans.pb(1);
        }
        chk(lb);
        ll go = (r-l)+1;
        int fuck = l - sum -1;
        for(int i = 0 ; i < go ; i ++ ){
            cout << ans[fuck++] << ' ';
        }
        cout << endl;
    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
