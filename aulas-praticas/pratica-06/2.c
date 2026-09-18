struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans;
    ans = (struct ListNode *) malloc(sizeof(struct ListNode));
    ans->next = NULL;

    int carry = 0;
}

void NewNode (struct ListNode *head, int value) {
    struct ListNode *newNode;
    newNode = (struct ListNode *) malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    struct ListNode *prev;

    for (prev = head; prev->next)
}
