#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){};
	ListNode(int x):val(x),next(nullptr){};
	ListNode(int x,ListNode *p):val(x),next(p){};
};


void changePairs(ListNode *pre,ListNode *cur)
{
	ListNode *next1 = cur->next;
	pre->next = next1;
	cur->next = next1->next;
	next1->next = cur;
}

ListNode * swapPairs0(ListNode *head)
{
	if(head == nullptr || head->next == nullptr)
	{
		return head;
	}
	ListNode *dummyHead = new ListNode(0,head);
	ListNode *pre = dummyHead;
	while(pre->next != nullptr && pre->next->next != nullptr)
	{	
		changePairs(pre,pre->next);
		pre = pre->next;	
	}
	ListNode *ans = dummyHead->next;
	delete dummyHead;
	return ans;
};

ListNode * swapPairs(ListNode *head)
{
	ListNode *dummyHead = new ListNode(0,head);
	ListNode *temp = dummyHead;
	while(temp->next != nullptr && temp->next->next!=nullptr)
	{	
		ListNode *node1 = temp->next;
		ListNode *node2 = node1->next;
		temp->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		temp = node1;
	}
	ListNode *ans = dummyHead->next;
	delete dummyHead;
	return ans;
};



void printLS(ListNode *head)
{
	ListNode *cur = head;
	int count  = 0;
	while(cur->next != nullptr)
	{
		cout<<"count :"<<count<<"\t"<<cur->val<<endl;
		count++;
		cur= cur->next;
	}
	cout<<"count :"<<count<<"\t"<<cur->val<<endl;
}
int main()
{	
	ListNode A(10);
	ListNode B(20,&A);
	ListNode C(30,&B);
	ListNode D(40,&C);
	ListNode E(50,&D);
	ListNode F(60,&E);
	ListNode G(70,&F);
	ListNode H(80,&G);
	printLS(&H);
	swapPairs0(&H);
	cout<<endl;
	printLS(&G);
	return 0;
}