#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode * point):val(x),next(point){}
};
class Solution203
{
public:
	ListNode *removeElement(ListNode*head, int val)
	{
		ListNode dummyHead(0,head);//创建虚拟头节点，为了删除head
		ListNode *cur = &dummyHead;
		while(cur->next != NULL)
		{
			if(cur->next->val == val)
			{
				cur->next = cur->next->next;
			}
			else//为什么用else，防止跳过去后是空，无法->next
			{
				cur = cur->next;
			}
		}
		return dummyHead.next;
	}

};
int main()
{	
	ListNode L1(10);
	ListNode L2(20,&L1);
	ListNode L3(30,&L2);
	Solution203 A;
	A.removeElement(&L3,10);
	ListNode *cur = &L3;
	while(cur->next != NULL)
	{
		if(cur->next != NULL)
		{
			cout<<"val = "<<cur->val<<endl;
		}
		cur = cur->next;
	}
	return 0;

}
