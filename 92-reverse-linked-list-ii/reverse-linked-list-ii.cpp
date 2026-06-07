/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if( head == NULL) return head;
        if( left == right ) return head;
        
        int pos = 1;
        ListNode* t = head;
        ListNode* before = NULL;

        while(t!=NULL){
            if(pos<left){
                before = t;
                t = t -> next;
                pos++;
                continue;
            }

            ListNode* prev = NULL;
            ListNode* curr = t;

            //pos = left
            int times = right - left + 1;
            while(times--){
            
            ListNode* next = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = next;
            }

            if(before){
            before -> next = prev;
            }
            else{
            head = prev;
            }

            t -> next = curr;
            break;

        }
            return head;
    }
};