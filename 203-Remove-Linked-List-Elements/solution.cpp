/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p=NULL, *q=NULL;  
        while(head!=NULL&&head->val==val){  //对于队首的情况  
            p=head;  
            head=head->next;  
            delete p;  
        }  
        p=head;  
        while(p!=NULL&&p->next!=NULL){  
            if(p->next->val==val){  
                q=p->next;  
                p->next=q->next;  
                delete q;  
            }else{  
                p=p->next;  
            }  
        }  
        return head; 
    }
};