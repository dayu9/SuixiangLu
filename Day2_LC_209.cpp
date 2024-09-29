#include<iostream>
#include<vector>
using namespace std;

class Solution209
{

public:
	int minSubArrayLen(vector<int> &arr,int target)
	{
		int left = 0,right = 0;
		int sum_ =0;
		int min_len = arr.size();
		bool real = 0;
		for(int i = 0;i<arr.size();i++)
		{
			sum_ += arr[right];
			while(sum_>=target & left<=right)
			{
				real =1;
				min_len = min_len>right-left+1?right-left+1:min_len;
				sum_ -= arr[left];
				cout<<"left :"<<left<<"\tright: "<<right<<endl;
				left++;
			}
			right++;

		}
		min_len = (real==0)?0:min_len;
		return min_len;
	}

};

int main()
{
	vector<int> arr0 = {3,2,0,4,5,6,7};
	vector<int> arr1 = {0};
	int target = -1;
	Solution209 A;
	int result = A.minSubArrayLen(arr1,target);
	cout<<"result :"<<result<<endl;
	return 0;
}

//old
/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
		int sum = 0;
		for(int i = 0;i<arr.size();i++)
		{
			sum += arr[i];
		}
		if(sum<target)
		{
			return 0;
		}



		int R = 0;
		int min_len = arr.size();
		sum = 0;
		for(int L = 0;L<arr.size();L++)
		{
			while(R<arr.size() && sum<target)
			{
				sum += arr[R];
				R++;
			}

			if(sum>=target && R-L<min_len && R>L)
			{
				min_len = R-L;
			}
			sum -= arr[L];
		}
		return min_len;

    }
};
*/
