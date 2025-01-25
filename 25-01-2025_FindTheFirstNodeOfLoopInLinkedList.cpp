/*
    Given a head of the singly linked list. If a loop is present in the list then return the first node of 
    the loop else return NULL.

    Custom Input format:
    A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which 
    the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.
*/

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};