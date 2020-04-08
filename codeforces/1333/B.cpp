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
int n;
int a[maxn] , b[maxn];

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        int neg = 0 , pos = 0;
        for(int i = 0 ; i < n ; i ++){
            cin >> a[i];
            if(a[i] == -1){
                neg++;
            }
            if(a[i] == 1){
                pos ++ ;
            }
        }
        for(int i = 0 ; i < n ; i ++){
            cin >> b[i];
        }
        bool ok = 1;
        for(int i =  n - 1 ; i >= 0 ; i --){
            if(a[i] == 1){
                pos--;
            }
            if(a[i] == -1){
                neg--;
            }
            if(b[i] > a[i]){
                if(pos){
                    continue;
                }
                else{
                    ok = 0;
                    break;
                }
            }
            if(b[i] < a[i]){
                if(neg){
                    continue;
                }
                else{
                    ok = 0;
                    break;
                }
            }
        }
        if(ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }


    return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
//kuxtal jach uts chuchul u u páajtal máak jach táaj meyajilo'ob le castigadas tumen ch'aik descansos.
