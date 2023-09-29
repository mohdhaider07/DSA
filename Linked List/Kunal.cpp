#include <iostream>
using namespace std;

// Happy number

// calculate sum
int calculate_sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum = sum + (n % 10) * (n % 10);
        n = n / 10;
    }

    return sum;
}
bool isHappy(int n)
{
    int s = n;
    int f = n;
    while (f != 1)
    {
        s = calculate_sum(s);
        f = calculate_sum(f);
        f = calculate_sum(f);
        if (f == 1)
        {
            return true;
        }
        if (s == f)
        {
            return false;
        }
    }
    return true;
}

// reversing of the linked list
// ListNode* reverseList(ListNode* head) {
//         if(!head||!head->next){
//           return head;
//         }
//         ListNode* prev=head;
//         ListNode* next=head->next;
//           while(next){
//             ListNode* temp=next->next;
//             next->next=prev;

//             prev=next;
//             next=temp;

//           }
//         head->next=NULL;
//         return prev;
//     }

// reverse list 2
/*
ListNode* reverseList(ListNode* head,int rev_need) {
        if(!head||!head->next){
          return head;
        }
        ListNode* prev=head;
        ListNode* next=head->next;

          while(rev_need--){
            ListNode* temp=next->next;
            next->next=prev;

            prev=next;
            next=temp;


          }
        head->next=next;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if(!head||!head->next||left==right){
          return head;
        }

        int rev_need=right-left;

        if(left==1){
           ListNode* temp=head;
         head= reverseList(temp,rev_need);
        }else {
          ListNode* prevNode=head;
        ListNode* nextNode=head->next;
        left--;
        while(left!=1){
          prevNode=nextNode;
          nextNode=nextNode->next;
          left--;

        }
       prevNode->next = reverseList(nextNode,rev_need);
        }



         return head;
    }
    */

int main()
{
    cout << endl
         << isHappy(10);
    cout << "\nCode end";
    return 0;
}