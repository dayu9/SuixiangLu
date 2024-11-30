#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){};
	ListNode():val(0),next(nullptr){};
	ListNode(int x,ListNode *p):val(0),next(p){};
};

//遍历1遍，就是用空间换时间
ListNode* removeFromEndNth(ListNode *head,int n)
{
	ListNode *cur = head;
	ListNode *cur_add_n = head;
	while(n--)
	{
		cur_add_n = cur_add_n->next;

	}

	if(cur_add_n==nullptr)//放在while外面更快
	{
		return head->next;
	}

	while(cur_add_n !=nullptr && cur_add_n->next != nullptr)
	{
		cur_add_n = cur_add_n->next;
		cur = cur->next;
	}
	cur->next = cur->next == nullptr ? nullptr:cur->next->next;
	return head;
}


int main()
{
	return 0;
}