class Solution {
public:
    ListNode* sortList(ListNode* h) {
        if (!h || !h->next) return h;
        ListNode* m = h;
        ListNode* f = h;
        while (f->next && f->next->next) {
            m = m->next;
            f = f->next->next;
        }
        ListNode* s = m->next;
        m->next = NULL;
        ListNode* l = sortList(h);
        ListNode* r = sortList(s);
        ListNode* d = new ListNode(0);
        ListNode* c = d;
        while (l && r) {
            if (l->val <= r->val) {
                c->next = l;
                l = l->next;
            } else {
                c->next = r;
                r = r->next;
            }
            c = c->next;
        }
        c->next = l ? l : r;
        return d->next;
    }
};