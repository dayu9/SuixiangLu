#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){};
	ListNode():val(0),next(nullptr){};
	ListNode(int x,ListNode *p):val(0),next(p){};
};

ListNode * getIntersectionNode(ListNode *head1,ListNode *head2)
{
	ListNode *A = head1;
	ListNode *B = head2;

	while(A!=B)
	{
		A = A == nullptr?head2:A->next;
		B = B == nullptr?head1:B->next;
	}
	return A;
}

int main()
{


	return 0;
}