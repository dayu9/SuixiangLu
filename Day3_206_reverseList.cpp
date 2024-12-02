#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){};
	ListNode(int x,ListNode*p):val(x),next(p){};
	ListNode():val(0),next(nullptr){};

};

//自己的写法，其实也可以改成pre,cur,next的写法,我这种前进两步的写法，需要反复确认下一步非空,不好
ListNode* reverseList(ListNode *head)
{
	ListNode *cur = head;
    if(head ==nullptr)
    {
        return cur;
    }
	
	ListNode *next1 = cur->next;
	if(next1 == nullptr)
	{
		return cur;
	}

	ListNode *next2 = nullptr;
	if(next1->next != nullptr)
	{
		next2 = next1->next;
	}
	
	cur->next = nullptr;
	while(next1!= nullptr & next2!=nullptr)
	{
		next1->next = cur;
		cur = next1;
		next1 = next2;
		next2 = next2->next;
	}
	next1->next = cur;
	return next1;
}


//官方解法
ListNode* reverseList1(ListNode *head)
{
	ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printls(ListNode *list1)
{
	ListNode*cur = list1;
	int count = 0;
	while(cur->next!=nullptr)
	{
		cout<<count<<"\t"<<cur->val<<endl;
		cur = cur->next;
		count ++;
	}
}

ListNode* addHead(ListNode *list1,int val)
{
	ListNode *newhead = new ListNode(val);
	newhead->next = list1;
	return newhead;
}

int main()
{
	ListNode A;
	ListNode *head = &A;
	head = addHead(&A,10);
	head = addHead(head,20);
	head = addHead(head,30);
	head = addHead(head,40);
	printls(head);

	// head = reverseList1(head);
	head = reverseList(head);
	printls(head);
	return 0;
}