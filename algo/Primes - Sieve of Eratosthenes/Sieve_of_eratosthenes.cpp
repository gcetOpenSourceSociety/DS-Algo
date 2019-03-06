#include<bits/stdc++.h>
#define MAX 3000
using namespace std;

vector<int> primes;

void sieve(void){
	bool prime[MAX+1];
	memset(prime, true, sizeof(prime));
	for(int i=2; i<=MAX; ++i){
		if(prime[i]==true
		){
			primes.push_back(i);
			for(int j=i*2; j<=MAX; j=j+i)
				prime[j]=false;
		}
	}
	sort(primes.begin(),primes.end());
}

int main(){
	int n;
	cin>>n;
	sieve();
	for(int i=0; i<n; ++i)
		cout<<primes[i]<<endl;
	return 0;
}

