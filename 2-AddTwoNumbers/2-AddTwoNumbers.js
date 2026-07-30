// Last updated: 30/07/2026, 10:25:34
function addTwoNumbers(l1, l2) {
    let dummy = new ListNode(0);
    let cur = dummy;
    let carry = 0;

    while (l1 !== null || l2 !== null || carry !== 0) {
        let val1 = l1 ? l1.val : 0;
        let val2 = l2 ? l2.val : 0;

        let total = val1 + val2 + carry;
        carry = Math.floor(total / 10);
        cur.next = new ListNode(total % 10);
        cur = cur.next;

        if (l1) l1 = l1.next;
        if (l2) l2 = l2.next;
    }

    return dummy.next;
}