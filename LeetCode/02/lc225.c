// lc225.c

// LeetCode 225. Implement Stack using Queues `E`
// ERR | | 50'
// A~0e10

#define MAX 100

typedef struct
{
    int queue[MAX];
    int head;
    int tail;
    int size;
} MyStack;

/** Initialize your data structure here. */
MyStack *myStackCreate()
{
    MyStack *p = malloc(sizeof(MyStack));
    p->head = p->tail = p->size = 0;

    return p;
}

/** Push element x onto stack. */
void myStackPush(MyStack *obj, int x)
{
    obj->queue[obj->tail++] = x;
    // obj->tail = obj->tail == MAX ? 0 : obj->tail;
    obj->size++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack *obj)
{
    for (int i = 0; i < obj->size - 1; i++)
    {
        myStackPush(obj, obj->queue[obj->head++]);
        // obj->head = obj->head == MAX ? 0 : obj->head;
    }

    int ret = obj->queue[obj->head++];
    // obj->head = obj->head == MAX ? 0 : obj->head;
    obj->size--;
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack *obj)
{
    for (int i = 0; i < obj->size - 1; i++)
    {
        myStackPush(obj, obj->queue[obj->head++]);
        // obj->head = obj->head == MAX ? 0 : obj->head;
    }

    int ret = obj->queue[obj->head];
    myStackPush(obj, obj->queue[obj->head++]);
    // obj->head = obj->head == MAX ? 0 : obj->head;
    return ret;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack *obj)
{
    return obj->size == 0;
}

void myStackFree(MyStack *obj)
{
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
