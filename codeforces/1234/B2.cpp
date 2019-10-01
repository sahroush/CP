#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2085;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n , k;
deque <int> vec;
int inp;
//std::deque<int>::iterator it;
set <int> st;

int main(){
    migmig
    cin >> n >> k;
    for (int i=0  ; i < n;  i++){
        cin >> inp;
        if (vec.size() == 0){
            vec.push_back(inp);
            st.insert(inp);
        }
        else{

            //it = std::find (vec.begin(), vec.end(), inp);
            if (st.count(inp) == 0){
                vec.push_front(inp);
                st.insert(inp);
            }
            if (vec.size() == k+1){
                st.erase(vec[k]);
                vec.pop_back();

            }
        }
    }
    cout << vec.size() << endl;
    for (int i = 0 ; i < vec.size() ; i ++){
        cout << vec[i] << '\t';
    }

    return(0);
}



//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
