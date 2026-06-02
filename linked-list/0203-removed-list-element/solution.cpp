//直接移除结点方法
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 定义一个名叫 removeElements 的函数，它接收一个链表头指针 head 和一个整数 val，
        // 函数的作用是删除链表中所有值等于 val 的节点，最后返回删除后的新链表头指针。
        while (head != NULL && head->val == val) { // 注意这里不是if
            //当 head 不是空指针，并且 head 指向的节点值等于 val 时，就进入循环。
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
//时间复杂度: O(n)
//空间复杂度: O(1)

//设置一个虚拟头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
//删除的关键在于先用*temp保存，再跳过*temp,最后删除*temp