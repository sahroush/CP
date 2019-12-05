#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

const ll maxn =10e5+10;
const ld SADAT = 7.84e-17;
const ll INF = 1e9;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define random_init mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>bool checkmin(T &a,T b){return a > b ? a = b, 1 : 0;}
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int q , n , a[maxn] , g , s , b;
map <int , int> mp;
vector < int > vec;

int chk(int x){
    x--;
    int mn= vec[x];
    int cnt = 0;
    for (int i = 0 ; i < n ; i ++){
        if(a[i] >= mn ){
            cnt++;
        }
    }
    if(cnt + g + s > n/2){
        return(0);
    }
    return(cnt);
}

int main(){
    migmig
    cin >> q;
    while(q -- ){
        b = 0 , s = 0 , g = 0;
        int mx = 0;
        cin >> n;
        for (int i = 0 ; i < n ; i ++){
            cin >> a[i];
            mx = max(mx , a[i]);
        }
        int cnt = 0 ;
        for (int i = 0 ; i < n;  i ++){
            if(a[i] == mx){
                a[i] = -1;
                cnt++;
            }
        }
        g = cnt;

        mp.clear();
        vec.clear();
        for (int i = 0 ; i < n;  i++){
            if(a[i] > -1){
                mp[a[i]]++;
                if(mp[a[i]] == 1){
                    vec.pb(a[i]);
                }
            }
        }
        sort(vec.begin() , vec.end());
        reverse(vec.begin() , vec.end());
        cnt = 0 ;
        int pos = 0;
        for (int i = 0; i < vec.size() ; i ++){
            cnt+=mp[vec[i]];
            pos = i;
            if(cnt > g){
                s = cnt;
                break;
            }
        }
        cnt= 0 ;
        for (int i =pos+1  ; i <vec.size() ; i ++ ){
            cnt+=mp[vec[i]];
            if(cnt + g + s > n / 2){
                cnt-=mp[vec[i]];
                b = cnt;
                break;
            }
        }


        if(g + s + b <= n and g > 0  and s > 0 and b > 0 and g < s and g < b){
            cout << g  << ' '<< s  << ' '<< b << endl;
        }
        else{
            cout <<"0 0 0" << endl;
        }

    }


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
