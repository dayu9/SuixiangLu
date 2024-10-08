#include<iostream>
#include<vector>
using namespace std;
#include <climits>

class Solution209
{

public:
	int departLand(vector<int> &arr,int target)
	{
		return 0;		
	}

};

int main()
{
	bool show = 0;

	int n,m;
	int sum_all;
	int result;

	cout<<"Please input the value of n and m:"<<endl;
	cin>>n>>m;
	vector<vector<int>> arr(n,vector<int>(m,0));
	vector<int> sum_col(n,0);	
	vector<int> sum_vol(m,0);	
	// define the value

	cout<<"Please input the value of arr"<<endl;
	for(int i=0;i<n*m;i++)
	{
		cin>>arr[i/m][i%m];
	}

    for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
			sum_col[i] += arr[i][j];
			sum_vol[j] += arr[i][j]; 
			sum_all+= arr[i][j];
        }
    }
    result = sum_all;
	if(n>=1)
	{	
		for(int i = 1;i<n;i++)
		{
			sum_col[i] += sum_col[i-1];
			// result   = result<abs(sum_all-sum_col[i]-sum_col[i])?result:abs(sum_all-sum_col[i]-sum_col[i]);
			result   = min(result,abs(sum_all-sum_col[i]-sum_col[i]));
		}
	}

	if(m>=1)
	{
		for(int j = 1;j<m;j++)
		{
			sum_vol[j] += sum_vol[j-1];
			// result   = result<abs(sum_all-sum_vol[j]-sum_vol[j])?result:abs(sum_all-sum_vol[j]-sum_vol[j]);
			result   = min(result,abs(sum_all-sum_vol[j]-sum_vol[j]));
		}
	}

	if(show)
	{
		cout<<"arr :"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cout<<arr[i][j]<<"\t";
			}
			cout<<endl;
		}

		cout<<"sum_col :";
		for(int i=0;i<n;i++)
		{
			cout<<sum_col[i]<<"\t";
		}

		cout<<endl<<"sum_vol :";
		for(int j = 0;j<m;j++)
		{
			cout<<sum_vol[j]<<"\t";
		}
		cout<<endl;
		
	}
	cout<<result<<endl;
	return result;
}
