/*
    Given the head a linked list, the task is to reverse every k node in the linked list. If the number of 
    nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and 
    must be reversed.
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node*prev=NULL,*curr=head,*next=curr;
        int cnt=0;
        while(curr && cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next) head->next = reverseKGroup(next,k);
        return prev;
    }
};


class Solution {
  public:
    vector<Node*> reverse(Node* curr,int k){
        Node* initial = curr;
        Node*prev = NULL;
        Node*next = curr;
        while(k--){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        if(curr)
        initial->next=curr;
        else initial->next = NULL;
        return {prev,curr,initial};
    }
    Node *reverseKGroup(Node *head, int k) {
        if(k==1) return head;
        Node*temp = head;
        int cnt=0;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        auto output = reverse(head,k);
        Node*outputNode = output[0];
        Node*newNode = output[1];
        Node*prev = output[2];
        for(int i=1;i<cnt/k;i++){
            output = reverse(newNode,k);
            prev->next=output[0];
            newNode=output[1];
            prev=output[2];
        }
        
        if(cnt%k){
            output = reverse(newNode,cnt%k);
            prev->next=output[0];
        }
        
        return outputNode;
    }
};