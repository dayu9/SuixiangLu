#include<iostream>
using namespace std;

struct ListNode{
    int val ;
    ListNode *next  = nullptr;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *newnode):val(x),next(newnode){}
};



class MyLinkedList {
private:
    int size;
    ListNode *head;

public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode;
    }
    int getsize()
    {
        return this->size;
    }

    int get(int index) {
        if(index>=this->size || index<0)
        {
            cout<<"get index Error, Boundary Error"<<endl;
            return -1;
        }
        ListNode *cur  = this->head->next;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->val;        
    }
    
    void addAtHead(int val) {
        ListNode *newnode = new ListNode(val);
        newnode->next = head->next;
        head->next = newnode;
        this->size++;
        // cout<<"addAtHead function"<<endl;
        // cout<<"head next.val\t"<<head->next->val<<endl;
        // cout<<"size :\t"<<this->getsize()<<endl<<endl;
    }
    
    void addAtTail(int val) {
        int count = this->size;
        ListNode *cur = this->head;
        ListNode *newtail = new ListNode(val);
        while(count--)//size -1 是末尾坐标，-2是前1位
        {
            cur = cur->next;
        }
        cur->next = newtail;
        this->size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>this->size || index<0)
        {
            cout<<"addAtIndex Boundary Error"<<endl;
            return ;
        }
        // if(index == 0 )
        // {
        //     this.addAtHead(val);
        //     return ;
        // }
        ListNode *newNode = new ListNode(val);
        ListNode *cur = this->head;
        
        // int count = -1;//也可以都不减1，为了更好理解，count对应当前访问的顺序个数，index-1 是为了停留在前1位
        // while(count < index-1)
        // {
        //     cur = cur->next;
        //     count++;
        // }

        while(index--)
        {
            cur = cur->next;
        }
        // cout<<"index :"<<index<<"\tcount :"<<count<<endl;
        newNode->next = cur->next;
        cur->next = newNode;
        this->size ++;
        // cout<<"1\t"<<cur->val<<endl;
        // cout<<"2\t"<<newNode->val<<endl;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>this->size-1)
        {
            cout<<"addAtIndex Boundary Error"<<endl;
            return ;
        }

        ListNode *cur  = this->head;
        // int count =  -1;
        // while(count++<index)
        while(index--) //index到0的步数，等于index-1到head的步数
        {
            cur  = cur->next;;
        }
        ListNode *temp = cur->next;
        cur->next = cur->next->next;

        delete temp;
        this->size --;
        return ;
    }
};


int main()
{
    MyLinkedList A;
    A.addAtHead(10);
    A.addAtHead(20);
    A.addAtIndex(0,100);
    A.addAtIndex(1,200);
    A.addAtIndex(4,200);

    // cout<<A.get(0)<<endl;
    // cout<<A.get(1)<<endl;
    // cout<<A.get(2)<<endl;
    // cout<<A.get(3)<<endl;
    // cout<<A.get(4)<<endl;
    // cout<<A.get(5)<<endl;

    for(int i =0;i<A.getsize();i++)
    {
        cout<<i<<"\t"<<A.get(i)<<endl;
    }

    return 0;
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */