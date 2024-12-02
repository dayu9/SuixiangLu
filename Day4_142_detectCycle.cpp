#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){};
	ListNode():val(0),next(nullptr){};
	ListNode(int x,ListNode *p):val(0),next(p){};
};

//环形问题，迅速想到追及问题，想到快慢针，
ListNode *detecCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	if(fast== nullptr) return nullptr;
	while(fast->next!=nullptr)
	{
		fast = fast->next;
		if(fast->next == nullptr)
		{
			return nullptr;
		}
		fast = fast->next;
		slow = slow->next;
		if(fast == slow)
		{
			ListNode *newslow =head;
			while(newslow != slow)
			{
				newslow = newslow->next;
				slow = slow->next;
			}
			return slow;
		}
	}
	return nullptr;

};

int main()
{
	return 0 ;
}