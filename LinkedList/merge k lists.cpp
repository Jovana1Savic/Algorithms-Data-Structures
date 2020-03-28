/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){
        
        if (!head1 && !head2) return NULL;
        if (!head1) return head2;
        if (!head2) return head1;
        
        if (head1->val > head2->val)
            return mergeTwoLists(head2, head1);
        
        // First element after which we insert is head1.
        // This is used to avoid checks tail == NULL
        ListNode *cur1 = head1->next;
        ListNode *cur2 = head2;
        ListNode *tail = head1;
        ListNode *head = head1;
        
        while (cur1 && cur2){
            if (cur1->val <= cur2->val){
                // Insert cur1 into list.
                tail = tail->next = cur1;
                cur1 = cur1->next;
            }
            else {
                // Insert cur2 into list.
                tail = tail->next = cur2;
                cur2 = cur2->next;
            }
        }
        
        // Insert leftovers.
        while (cur1){
            tail = tail->next = cur1;
            cur1 = cur1->next;
        }
        
        while (cur2){
            tail = tail->next = cur2;
            cur2 = cur2->next;
        }
        
        tail->next = NULL; // Make sure next is null.
        return head;
    }
 public:   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        
        while (k > 1){
            int j = 0;
            for (int i = 0; i < k - 1; i += 2){
                ListNode* head =  mergeTwoLists(lists[i], lists[i + 1]);
                if (head)
                    lists[j++] = head;
            }
            if (k % 2 && lists[k - 1])
                lists[j++] = lists[k - 1];
            
            k = j;
        }
        if (k == 0) return NULL;
        
        return lists[0];
    }
};