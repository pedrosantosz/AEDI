void NewNode (struct ListNode *head, int value);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ans;
    ans = (struct ListNode *) malloc(sizeof(struct ListNode));
    ans->next = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        int soma;
        
        if (l1 != NULL && l2 != NULL) {
            soma = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1 != NULL) {
            soma = l1->val + carry;
            l1 = l1->next;
        }
        else {
            soma = l2->val + carry;
            l2 = l2->next;
        }

        int digit = soma % 10;
        carry = soma / 10;

        NewNode(ans, digit);     
    }

    if (carry != 0) {
        NewNode(ans, carry);
    }

    return ans->next;
}

void NewNode (struct ListNode *head, int value) {
    struct ListNode *newNode;
    newNode = (struct ListNode *) malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    struct ListNode *prev;

    for (prev = head; prev->next != NULL; prev = prev->next);

    prev->next = newNode;
}