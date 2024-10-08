#include<iostream>
#include<vector>
using namespace std;

//螺旋矩阵59题 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。


// 注意：二维数组的定义
class Solution59
{

public:
	vector<vector<int>> generateMatrix(int n)//24_10_08
	{
		vector<vector<int>> arr(n,vector<int>(n,0));
		int left = 0, bot = 0;
		int right = n-1,up = n-1;
		int i =0, j =0;
		int value = 1;
		while(left<=right && bot <= up && value<=n*n)
		{
			while(j<=right)
			{
				arr[i][j++] = value++;
			}
			j--;//数组越界，调整回来
			
			i++;// 更改下一轮循环起始位置
			bot ++;// 调整边界
			

			while(i<=up)
			{
				arr[i++][j] = value++;
			}
			i--;
			
			right--;
			j--;
		
			while(j>=left)
			{
				arr[i][j--] = value++;
			}
			j++;
			
			up--;
			i--;

			while(i>=bot)
			{
				arr[i--][j] = value++;
			}
			i++;
			
			left++;
			j++;

		}


		for(int ii = 0;ii<n;ii++)
		{
			for(int jj =0;jj<n;jj++)
			{
				cout<<arr[ii][jj]<<"\t";
			}
			cout<<endl;
		}
		return arr;
	}

};

int main()
{
	vector<int> arr0 = {3,2,0,4,5,6,7};
	vector<int> arr1 = {0};
	int n = 5;
	vector<vector<int>> arr(n,vector<int>(n,0));

	bool show = 0;
	int target = -1;
	Solution59 A;

	arr =A.generateMatrix(n);
	if(show)
	{
		for(int ii = 0;ii<n;ii++)
		{
			for(int jj =0;jj<n;jj++)
			{
				cout<<arr[ii][jj]<<"\t";
			}
			cout<<endl;
		}
	}
	// cout<<"result :"<<result<<endl;
	return 0;
}




// 1008之前写的答案

/*
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n));
		int left  = 0;
		int right = n-1;
		int top    = 0;
		int bottom = n-1;

		int add   = 1;
		int value = 1;
		int i=0,j = 0;

		while(value <= n*n)
		{
			while(top<=j && j<=bottom)
			{
				arr[i][j] = value;
				value+=1;
				j+= add;
			}
			j -= add;  // j 此时已越界，需要调整回来
			i += add;  // i 值更新

			while(left<=i && i<=right)
			{
				arr[i][j] = value;
				value+=1;
				i+= add;
			}
			i -= add; // i 此时已越界，需要调整回来
			j -= add; // j 值更新
			

			if(add>=0)
			{
				left += 1;
				bottom -= 1;
			}
			else
			{
				right -= 1 ;
				top += 1 ;
			}
			add *= -1;

		}
		return arr;
    }
};
*/