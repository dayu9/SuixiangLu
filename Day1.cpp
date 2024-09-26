#include<iostream>
#include<vector>
using namespace std;



// Day1, 704 ,2分查找
class Solution_704
{
	// Method A, [ , ]
	// 注意1：
		//	这道题的需要注意点在于边界的选取，左右边界更新时的新值
		//  与终止条件的==
		//  最核心的办法，循环不变量，参考下面注释

	// 注意2：
		// 为什么用 left + (right-left)/2;————防止越界
public:
	int search1(vector<int>& arr, int value)
	{
		int left = 0;
		int right = arr.size()-1;
		while(left<=right)
		{
			// 循环不变量：
            // nums[left-1] < target
            // nums[right+1] >= target
			int mid = left + (right-left)/2;
			
			if(arr[mid]==value ) return mid;
			else if(arr[mid]<value) left = mid+1;
			else right = mid-1;
		}
		return -1;
	}
	
	// Methoed2 [ , )
	int search2(vector<int> &arr, int value)
	{
		int left = 0;
		int right = arr.size();
		while(left<right)
		{
			int mid = left + (right-left)/2;
			if(arr[mid]==value ) return mid;
			
			else if(arr[mid]<value) left = mid+1;
			else right = mid;
		}
		return -1;
	}
};

int main()
{
	Solution_704 A;
	vector<int> arr ={-1,0,3,5,9,12};
	int result = A.search1(arr,-1);
	 result = A.search2(arr,10);
	cout<< result<<endl;
	return 0;
}

