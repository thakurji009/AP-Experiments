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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode temp(0, head);
            ListNode* prev = &temp;
    
            while(head){
                if(head->next && head->val == head->next->val){
                    int same = head->val;
                    while(head && head->val == same){
                        head = head->next;
                    }
                    prev->next = head;
                }
                else{
                    prev = head;
                    head = head->next;
                }
            }
            return temp.next;
        }
    };
    
    