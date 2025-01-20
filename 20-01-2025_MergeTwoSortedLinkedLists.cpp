/*
    Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both 
    lists and return the head of the sorted merged list.

    Constraints:
    1 <= no. of nodes<= 10^3
    0 <= node->data <= 10^5
*/


class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if(head1->data > head2->data){
            Node* temp = head1;
            head1=head2;
            head2=temp;
        }
        Node*list1 = head1;
        Node*list2 = head2;
        Node*prev = NULL;
        
        while(list1 && list2){
            if(list1->data <= list2->data){
                prev = list1;
                list1 = list1->next;
            }
            else{
                Node*temp = list2;
                list2=list2->next;
                temp->next = list1;
                prev->next=temp;
                prev=temp;
            }
        }
        if(list2!=NULL){
            prev->next=list2;
        }
        return head1;
    }
};