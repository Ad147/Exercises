// lc155.cpp

// LeetCode 155. Min Stack `E`
// acc | 73%* | 21'
// A~0d26

class MinStack
{
private:
    vector<int> stack;
    size_t topIdx;
    vector<int> minElms;

public:
    MinStack() : stack(10000), topIdx{0}, minElms{}
    {
        minElms.push_back(INT_MAX);
    }

    void push(int x)
    {
        stack[++topIdx] = x;
        if (x <= minElms.back())
            minElms.push_back(x);
    }

    void pop()
    {
        if (stack[topIdx] == minElms.back())
            minElms.pop_back();
        topIdx--;
    }

    int top()
    {
        return stack[topIdx];
    }

    int getMin()
    {
        return minElms.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
