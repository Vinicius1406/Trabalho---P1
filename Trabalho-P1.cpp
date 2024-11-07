#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
};
void printar(struct ListNode* head){
    ListNode* p = head;
    while(p != NULL){
        cout << p->val << endl;
        p = p->next;
    }
}

ListNode* insert(struct ListNode* head,int new_data){

    struct ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = new_data;
    new_node->next = head;
    return new_node;
}

void bubblesort(struct ListNode* head){
    struct ListNode *end,*p,*q;
    int temp;
    for(end = NULL;end != head->next;end=p){
        for(p = head;p->next != end;p=p->next){
            q = p->next;
            if(p->val > q->val){
                temp = p->val;
                p->val = q->val;
                q->val = temp;
            }
        }
    }
}

void insertNode(ListNode *& newList,ListNode* myinsertNode){
    if(newList == NULL){
        newList = myinsertNode;
        return;
    }
    else if(myinsertNode->val <= newList->val){
        myinsertNode->next = newList;
        newList = myinsertNode;
        return;
    }
    else{
        ListNode* current = newList;
        while(current != NULL){
            if(current->next == NULL && myinsertNode->val >= current->val){
                current->next = myinsertNode;
                return;
            }
            if(myinsertNode->val >= current->val && myinsertNode->val <= current->next->val){
                myinsertNode->next = current->next;
                current->next = myinsertNode;
                return;
            }
            current = current->next;
        }
    }
}

ListNode* insertionSort(ListNode *head){
    ListNode *current = head;
    ListNode *newlist = NULL;
    while(current != NULL){
        ListNode* myinsertNode = current;
        current = current->next;
        myinsertNode->next = NULL;
        insertNode(newlist,myinsertNode);
    }
    cout << newlist->val << endl;
    return newlist;
}




ListNode* findTail(ListNode* head){
    ListNode* tail = head;
    while(head != NULL){
        tail = head;
        head = head->next;
    }
    return tail;
}

ListNode* partition(ListNode* head,ListNode* tail){
    ListNode* pivot = head;
    ListNode* pre = head;
    ListNode* curr = head;
    while(curr != tail->next){
        if(curr->val < pivot->val){
            swap(pre->next->val,curr->val);
            pre=pre->next;
        }
        curr = curr->next;
    }
    swap(pivot->val,pre->val);
    return pre;
}
void quicksortOG(ListNode* head,ListNode* tail){
    if(head == NULL || head == tail){
        return;
    }
    ListNode* pivot = partition(head,tail);
    quicksortOG(head,pivot);
    quicksortOG(pivot->next,tail);
}

ListNode* quicksort(ListNode* head){
    ListNode* tail = findTail(head);
    quicksortOG(head,tail);
    return head;
}

ListNode* divideList(ListNode* p){
    ListNode* q,*start2;
    q = p->next->next;
    while(q != NULL && q->next != NULL){
        p = p->next;
        q = q->next->next;
    }
    start2 = p->next;
    p->next= NULL;
    return start2;
}
ListNode* merge(ListNode* p1,ListNode* p2){
    ListNode *startM,*pM;
    if(p1->val <= p2->val){
        startM = p1;
        p1 = p1->next;
    }
    else{
        startM = p2;
        p2 = p2->next;
    }
    pM = startM;
    while(p1!= NULL && p2 != NULL){
        if(p1->val <= p2->val){
            pM->next = p1;
            pM = pM->next;
            p1 = p1->next;
        }
        else{
            pM->next = p2;
            pM = pM->next;
            p2 = p2->next;
        }
    }
    if(p1 == NULL){
        pM->next = p2;
    }
    else{
        pM->next = p1;
    }
    return startM;
}
ListNode* mergeSort(ListNode* start){
    ListNode *start1,*start2,*startM;
    if(start == NULL || start->next == NULL){
        return start;
    }
    start1 = start;
    start2 = divideList(start);
    start1 = mergeSort(start1);
    start2 = mergeSort(start2);
    startM = merge(start1,start2);
    return startM;
}


int main(){
    struct ListNode* head = NULL;
    struct ListNode* head1 = NULL;
    struct ListNode* head0 = NULL;
    head = insert(head,6);
    head = insert(head,3);
    head = insert(head,5);
    head = insert(head,3);
    head = insert(head,8);
    head = insert(head,10);
    head = insert(head,6);
    head = insert(head,3);
    head = insert(head,5);
    head = insert(head,3);
    head = insert(head,8);
    head = insert(head,10);
    head1 = mergeSort(head);
    printar(head1);
}