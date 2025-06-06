/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        goto ret;
    struct ListNode *prev = head, *cur = head->next, *next = cur->next;
    head->next = NULL;
    while (cur) {
        cur->next = prev;
        prev = cur;
        cur = next;
        if(next)
            next = next->next;
    }
    head = prev;
ret:
    return head;
}

// simpler
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head, *next = NULL;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
