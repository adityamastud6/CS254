#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int kthSmallest( vector<int>& nums, int N, int K){
	
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		pq.push(nums[i]);
		if (pq.size() > K)
			pq.pop();
	}
	return pq.top();
}

int main(){
    int n,k; cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
	cout << "K'th smallest element is "<< kthSmallest(nums,n, k);
	return 0;
}

