/* 
You are given the heads of two non-empty singly linked lists, head1 and head2, that intersect 
at a certain point. Return that Node where these two linked lists intersect.

Note: It is guaranteed that the intersected node always exists.

In the custom input you have to give input for CommonList which pointed at the end of both 
head1 and head2 to form a Y-shaped linked list.
Examples:

Input: head1: 10 -> 15 -> 30, head2: 3 -> 6 -> 9 -> 15 -> 30
Output: 15
Explanation: From the above image, it is clearly seen that the common part is 15 -> 30, 
whose starting point is 15. 
*/


//using two pointer technique
Node* intersectPoint(Node* head1, Node* head2) {
    Node* temp1=head1, *temp2=head2;
    while(temp1!=temp2){
        temp1=temp1->next;
        if(temp1==NULL) temp1=head2;
        temp2=temp2->next;
        if(temp2==NULL) temp2=head1;
    }
    return temp1;
}

// using difference in node count
int getLength(Node* head){
    Node* temp = head;
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}
Node* intersectPoint(Node* head1, Node* head2) {
    int n = getLength(head1);
    int m = getLength(head2);
    int diff;
    if(n>m){
        diff = n-m;
        while(diff--) head1=head1->next;
    }
    else{
        diff = m-n;
        while(diff--) head2=head2->next;
    }
    while(head1!=head2){
        head1=head1->next;
        head2=head2->next;
    }
    return head1;
}

// using set
Node* intersectPoint(Node* head1, Node* head2) {
    unordered_set<Node*>s;
    Node* temp=head1;
    while(temp){
        s.insert(temp);
        temp=temp->next;
    }
    temp=head2;
    while(temp){
        if(s.count(temp)>0) return temp;
        temp=temp->next;
    }
    return NULL;
}
