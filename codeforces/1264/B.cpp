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
 
int a , b , c , d;
 
int main(){
    migmig
    cin >> a >> b >> c >> d;
    //a taa 1 b taa 2 c taa 3 d taa 4
    //b>=a va c>=d
    if(a == b + 1 and c==d and c ==0){
        cout << "YES" << endl;
        
        for (int i = 0 ; i < b ; i ++){
            cout << "0 1 ";
        }
        cout <<'0';
        return(0);
    }
    if(d == c + 1 and a==b and b ==0){
        cout << "YES" << endl;
        for (int i = 0 ; i < c ; i ++){
            cout << "3 2 ";
        }
        cout <<'3';
        return(0);
    }
    if(a > b or d > c or abs((b - a) - (c - d)) > 1 ){
        dokme("NO");
    }
    cout << "YES" << endl;
    if(b-a == c - d and c - d == 0){
    	
        for (int i = 0 ; i < a ; i ++){
            cout <<"0 1 ";
        }
        //cout <<' ';
        //cout <<' ';
        for (int i = 0 ; i < d  ; i ++){
            cout << "2 3 ";
        }
    }
    else if(b - a == c - d){
        for (int i = 0 ; i < a ; i ++){
            cout <<"0 1 ";
        }
        //cout <<' ';
        for (int i = 0 ; i < b - a ; i ++){
            cout << "2 1 ";
        }
        //cout <<' ';
        for (int i = 0 ; i < d ; i ++){
            cout << "2 3 ";
        }
    }
    else if(b-a > c - d){
        for (int i = 0 ; i < d ; i ++){
            cout << "3 2 ";
        }
        //cout << ' ';
        for (int i = 0 ; i < a ; i ++){
            cout <<"1 0 ";
        }
        cout <<"1 ";
        for (int i =0  ; i < c - d ; i ++){
            cout << "2 1 ";
        }
    }
    else{
        for (int i = 0 ; i < a ; i ++){
            cout <<"0 1 ";
        }
        for (int i = 0 ; i < d ; i ++){
            cout << "2 3 ";
        }
        //cout << ' ';
        cout <<"2 ";
        for (int i =0  ; i < b - a ; i ++){
            cout << "1 2 ";
        }
    }
    cout << endl;
 
 
    return(0);
}
 
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.