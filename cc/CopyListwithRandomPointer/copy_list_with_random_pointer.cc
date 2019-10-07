/**
 * Author: Lanqing Ye
 * Date: 2019-10-03
 */
/* 

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

*/ 

/*

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

//Fun One : Has Map  O(n) O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node *pNode = head;
        unordered_map<Node*,Node*> map;
        while(pNode != NULL){
            Node *copy = new Node(pNode -> val);
            map[pNode] = copy;
            pNode = pNode -> next;
        }
        pNode = head;
        while(pNode != NULL){
            map[pNode] -> next = map[pNode -> next];
            map[pNode] -> random = map[pNode -> random];
            pNode = pNode -> next;
        }
        return map[head];
        
    }
};
 
// Fun Two O(n) O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)    return head;
        Node *pNode = head;
        while(pNode != NULL){
            Node *copy = new Node(pNode -> val);
            copy -> next = pNode -> next;
            pNode -> next = copy;
            pNode = pNode -> next -> next;
        }
        pNode = head;
        while(pNode != NULL){
            pNode -> next -> random = pNode -> random ? pNode -> random -> next : nullptr;
            pNode = pNode -> next -> next;
        }
        pNode = head;
        Node *pHead = head -> next;
        Node *pNext = pHead;
        while(pNode != NULL){
            pNode -> next = pNode -> next -> next;
            pNext -> next = pNext -> next ? pNext -> next -> next : nullptr;
            pNode = pNode -> next;
            pNext = pNext -> next;
        }
        return pHead;
    }
};

 