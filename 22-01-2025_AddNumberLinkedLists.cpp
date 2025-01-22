/*
    Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task 
    is to return the head of the linked list representing the sum of these two numbers.

    For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked 
    list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

    Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the 
    output list.
*/

class Solution {
  public:
    Node* reverse(Node*head){
        Node*curr=head;
        Node*prev=NULL;
        Node*next=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* n1=reverse(num1);
        Node* n2=reverse(num2);
        Node* ans=new Node(-1);
        Node*res=ans;
        int carry=0;
        while(n1 || n2 || carry){
            int sum = carry;
            if(n1) {
                sum+=n1->data;
                n1=n1->next;
            }
            if(n2) {
                sum+=n2->data;
                n2=n2->next;
            }
            int digit = sum%10;
            ans->data = digit;
            carry=sum/10;
            if(n1 || n2 || carry){
                Node* temp=new Node(-1);
                ans->next=temp;
                ans=temp;
            }
        }
        ans = reverse(res);
        while(ans->data==0) ans=ans->next;
        return ans;
    }
};