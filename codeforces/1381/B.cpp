#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e3;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int q , n;
int p[maxn];
bitset < maxn > bit , amoo;

int main(){
    migmig
    cin >> q;
    while(q -- ){
        cin >> n;
        for(int i = 0 ; i < 2*n ; i ++){
            cin >> p[i];
        }
        vector < int > vec;
        vec.clear();
        int cur = 0 , cnt = 0;
        for(int i = 0 ; i < n+n ; i ++){
            if(p[i] > p[cur]){
                cur = i;
                vec.pb(cnt);
                cnt = 0;
            }
            cnt++;
        }
        vec.pb(cnt);
        sort(vec.begin() , vec.end());
        bit = 0;
        bit[0] =1;
        for(int i : vec){
            amoo = bit << i;
            bit|=amoo;
        }
        if(bit[n]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }



    return(0);
}