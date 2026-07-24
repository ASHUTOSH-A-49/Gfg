#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	int n = arr.size();
	int low = 0,high = n-1;
	while(low<=high){
		int mid = low+(high-low)/2;
		if(mid==0){
			if(arr[mid]!=arr[mid+1])return arr[mid];
			low = mid+1;
		}else if(mid==n-1){
			if(arr[mid-1]!=arr[mid]) return arr[mid];
			high = mid-1;
		}else{
			if(arr[mid]==arr[mid-1]) {
				if(mid&1) low = mid+1;
				else high = mid-1;
			}else if(arr[mid]==arr[mid+1]){
				if(mid&1) high = mid-1;
				else low = mid+1;
			}else return arr[mid];
		}
	}
	return 0;



}
