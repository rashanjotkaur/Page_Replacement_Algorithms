#include <bits/stdc++.h>
using namespace std;
int fifo(int arr[],int n,int s){
    unordered_map <int,bool> ump;
    queue <int> q;
    int fault=0;
    for(int i=0;i<n;i++){
        if(ump[arr[i]]==false){
            fault++;
            if(q.size()==s){
                ump[q.front()]=false;
                q.pop();
            }
            q.push(arr[i]);
            ump[arr[i]]=true;
        }
    }
    return fault;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cout<<fifo(arr,n,s)<<endl;
	}
	return 0;
}
