/*
    CODECHEF PROBLEM URL= https://www.codechef.com/problems/XORXORSUM
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// binary exponentiation
ll binpow(ll a,ll b){
    ll res=1;
    while(b!=0){
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}


int main() {
    // taking the input
	ll n;
	cin>>n;
	vector<ll> s;
	for(int i=0;i<n;i++){
	    ll a;
	    cin>>a;
	    s.push_back(a);
	}
    // sorting so that we can use upper boud and lower bound
	sort(s.begin(),s.end());
	ll ans=0;
	for(auto it=s.rbegin();it!=s.rend();it++){
	    ll x=*it;
	    ll y=*it;
	    vector<ll> bit;
	    while(x!=0){
	        if(x%2) bit.push_back(1);
	        else bit.push_back(0);
	        x/=2;
	    }
        // for each value in the array creating the required number 'b' such that a^b=2*(a&b)
	        ll nextxor=0;
	        vector<ll> temp;
	        for(int i=0;i<bit.size();i++){
	            ll t=(nextxor^bit[i]);
	            nextxor=(t&bit[i]);
	            temp.push_back(t);
	        }
	        ll b=0;
	    // cross cheaking the required condition once again  
	        for(int i=0;i<temp.size();i++) if(temp[i]==1) b+=binpow(2,i);
	        auto itt=lower_bound(s.begin(),s.end(),b);
	        if(itt!=s.end()&&*itt==b&&((y^b)==(2*(y&b)))) ans++;
	}
	cout<<ans<<endl;
}