#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =20;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e18+7;
const ld PI = 4 * atan((ld) 1);

#define mkp make_pair
#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ms(x , y) memset(x , y , sizeof x);
#define prnt(x)  for(int i = 0 ; i < x.size() ; i ++) cout << x[i] << ' ';
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int h1 , a1 , c1 , h2 , a2;

int main(){
    migmig
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;
    int a[] = {h1 , a1 , c1 , h2 ,a2};
    int cnt= 0;
    while(h2 > 0){
        cnt ++;
        if(h2 - a1 <= 0){
            //cout << "STRIKE";
            break;
        }
        else if(h1 - a2 <=0){
            //cout << "heal" << endl;
            h1+=c1;
        }
        else{
            h2-=a1;
            //cout << "strike" << endl;
        }
        h1-=a2;
    }
    cout << cnt << endl;
    h1 = a[0] , a1 = a[1] , c1 = a[2] , h2 = a[3] , a2 = a[4];
    while(h2 > 0){
        cnt ++;
        if(h2 - a1 <= 0){
            cout << "STRIKE";
            break;
        }
        else if(h1 - a2 <=0){
            cout << "HEAL" << endl;
            h1+=c1;
        }
        else{
            h2-=a1;
            cout << "STRIKE" << endl;
        }
        h1-=a2;
    }



    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
