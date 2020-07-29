// Best Method using two maps
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int lru(int arr[],int n,int frames){
	int fault = 0;
	map <int,int> mem;
	map <int,int> exist;
	for(int i=0;i<n;i++){
	   // Case 1: Memory has space && Page is not in memory
		if(mem.size()<frames && (exist.find(arr[i])==exist.end())){
				mem[i] = arr[i];
				exist[arr[i]]=i;
				fault++;
		}
		// Case 2: Memory has no space && Page is not in memory
		else if(exist.find(arr[i])==exist.end()){
			fault++;
			
			auto p = mem.begin();
			int f = p->first;
			int s = p->second;
			
			mem.erase(f);
			exist.erase(s);
			
			mem[i] = arr[i];
			exist[arr[i]] = i;
		}
		// Case 3: Page is in Memory
		else{
			int rem = exist[arr[i]];
			mem.erase(rem);
			exist.erase(arr[i]);
				
				// update when page already present in memory
			mem[i] = arr[i];
			exist[arr[i]]=i;
		}
	}
	return fault;
}

int main(){
 	int t;
 	cin>>t;
 	while(t--){
 		int n;
	    cin>>n;
        int arr[n];
	    for(int i=0;i<n;++i)
		    cin>>arr[i];
	   	int frames;
	   	cin>>frames;
	   	cout<<lru(arr,n,frames)<<endl;
	 }
	 return 0;
}
