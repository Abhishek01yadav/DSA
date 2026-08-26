
class Solution {

public:

ListNode*collisionPoint(ListNode* head1,ListNode*head2,int diff){
    ListNode* temp1=head1;

    for(int i=1;i<=diff;i++){
        temp1=temp1->next;

    }

 

    ListNode* temp2=head2;
   


    while(temp1 != temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;






}




    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp1=headA;
         ListNode*temp2=headB;

         int n1=0,n2=0;

         while(temp1){
            n1++;
            temp1=temp1->next;
         }

           while(temp2){
            n2++;
            temp2=temp2->next;

         }

         if(n1< n2){
            return collisionPoint(headB,headA,n2-n1);
         }

         else{
            return collisionPoint(headA,headB,n1-n2);
         }



         
        
return NULL;
        
    }
};