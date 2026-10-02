/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int length = 0;

    for (struct ListNode *current = head; current != NULL; current = current->next) {
        length++;
    }

    int middle = length / 2;

    int i = 0;
    struct ListNode *current;
    for (current = head; current != NULL && i < middle; current = current->next) {
        i++;
    }
    
    return current;
}
