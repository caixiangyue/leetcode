/**
 * Author: Lanqing Ye
 * Date: 2019-10-11
 */
 
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> sta,chache;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sta.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!sta.empty()){
            chache.push(sta.top());
            sta.pop();
        }
        int res = chache.top();
        chache.pop();
        while(!chache.empty()){
            sta.push(chache.top());
            chache.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        while(!sta.empty()){
            chache.push(sta.top());
            sta.pop();
        }
        int res = chache.top();
        while(!chache.empty()){
            sta.push(chache.top());
            chache.pop();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sta.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
