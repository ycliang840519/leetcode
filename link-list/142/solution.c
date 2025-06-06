// when they first met, move the slower one to head,
// then increment both faster and slower by one,
// when they meet for the second time, the position is the start of the cycle,
// there's one special case, when the cycle starts at head,
// the encounter point will always be at head

// ref: https://ithelp.ithome.com.tw/articles/10344849
// ref: https://medium.com/%E5%81%8F%E5%81%8F%E7%9A%84%E6%BC%94%E7%AE%97%E6%B3%95%E7%AD%86%E8%A8%98/%E5%88%B7%E9%A1%8C%E7%AD%86%E8%A8%98-leetcode-linked-list-cycle-%E9%A1%8C%E7%B5%84-c844f8a07c82

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}
