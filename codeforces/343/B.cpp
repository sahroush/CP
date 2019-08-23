#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

stack<char> st;
string str;

int main(){
    migmig;

    cin >> str;
	int n = str.size();
    for(int i=0;i<n;i++){
        if (st.empty()){
        	st.push(str[i]);
		}
		else if (st.top()!=str[i]){
			st.push(str[i]);
		}
		else{
			st.pop();
		}
    }
    if (st.empty()) cout << "Yes";
    else cout << "No";
 
    return (0);
}
