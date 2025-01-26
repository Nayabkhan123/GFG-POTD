/*
    Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked 
    list is connected back to a node in the same list. The task is to remove the loop from the linked list 
    (if it exists).

    Custom Input format:

    A head of a singly linked list and a pos (1-based index) which denotes the position of the node to 
    which the last node points to. If pos = 0, it means the last node points to null, indicating there 
    is no loop.

    The generated output will be true if there is no loop in list and other nodes in the list remain 
    unchanged, otherwise, false.
*/

void removeLoop(Node* head) {
    Node* slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(!fast || !fast->next) return;

    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    while(slow->next!=fast){
        slow=slow->next;
    }
    slow->next=NULL;
}

class Solution {
  public:
    void removeLoop(Node* head) {
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
            prev=fast;
            fast=fast->next;
            if(slow==fast) {
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    prev=fast;
                    fast=fast->next;
                }
                prev->next=NULL;
            }
        }
    }
};