// 206. Reverse Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p, *c, *n; // (p)revious; (c)urrent; (n)ext


    if (head == NULL)
        return head;

    p = head;
    c = p->next;
    while (c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    head->next = NULL;

    return p;
}
