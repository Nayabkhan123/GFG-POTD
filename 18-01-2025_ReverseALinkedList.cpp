/*
    Given the head of a linked list, the task is to reverse this list and return the reversed head.
*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node*prev = NULL;
        while(head){
            Node*forw=head->next;
            head->next = prev;
            prev=head;
            head=forw;
        }
        head=prev;
        return head;
    }
};