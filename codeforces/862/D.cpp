#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
//#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

int n ;
int pos0 = -1 , pos1 = -1;
int base;
bool found[2];
string s = "";

void ask(int start , int end){
    cout << '?' << ' ';
    string boz = s;
    for (int i = start ; i <= end; i ++){
        boz[i] = '0';
    }
    cout << boz;
    cout << endl;
}

void find0(int l , int r){
    if(r - l == 0){
        pos0=l + 1;
        found[0] = 1;
        return;
    }
    int mid = (l + r)/2;
    ask(l , mid);
    int inp;
    cin >> inp;
    inp = n - inp;
    if(inp!=base -( mid -l +1)){
        find0(l , mid);
    }
    else{
        find0(mid + 1 , r);
    }
}
void find1(int l , int r){
    if(r - l == 0){
        found[1] = 1;
        pos1=l + 1;
        return;
    }
    int mid = (l + r)/2;
    ask(l , mid);
    int inp;
    cin >> inp;
    inp = n - inp;
    if(inp!=base +( mid -l +1)){
        find1(l , mid);
    }
    else{
        find1(mid + 1 , r);
    }
}

void solve (int l , int r){
    if(found[0] and found[1]){
        return;
    }
    int mid = (l + r) / 2;
    int inp;
    ask(l , mid);
    //cout << l << ' ' << mid;
    cin >> inp;
    inp = n - inp;
    if(inp == base-( mid - l +1)){
        pos1=l +1 ;
        find0(mid+1 , r);
        found[1] = 1;
    }
    else if(inp == base +(mid - l + 1)){
        pos0=l + 1;
        find1(mid+1,r);
        found[0] = 1;
    }
    else{
        solve(l,mid);
    }
}

int main(){
    migmig
    cin >> n;
    for (int  i = 0 ; i < n ;  i ++){
        s+='1';
    }
    ask(n , n);
    cin >> base;
    base = n - base;
    solve(0 , n - 1 );
    cout <<"! " <<  pos0 << ' ' << pos1;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
