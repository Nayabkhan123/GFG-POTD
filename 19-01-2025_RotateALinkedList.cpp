/*
    Given the head of a singly linked list, your task is to left rotate the linked list k times.
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if(head->next==NULL) return head;
        Node* last = head;
        int len=1;
        while(last->next!=NULL){
            last=last->next;
            len++;
        }
        Node*temp;
        for(int i=0;i<k%len;i++){
            temp=head->next;
            head->next=NULL;
            last->next=head;
            last=head;
            head=temp;
        }
        return head;
    }
};
