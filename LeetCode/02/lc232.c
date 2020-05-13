/* lc232.c */

/* LeetCode 232. Implement Queue using Stacks `E` */
/* 1sk | 100% | 14' */
/* A~0e13 */

typedef struct
{
    int head[100];
    int tail[100];
    int headSize;
    int tailSize;
} MyQueue;

/** Initialize your data structure here. */
MyQueue *myQueueCreate()
{
    MyQueue *ret = malloc(sizeof(MyQueue));
    ret->headSize = 0;
    ret->tailSize = 0;

    return ret;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue *obj, int x)
{
    obj->tail[obj->tailSize++] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue *obj)
{
    if (obj->headSize == 0)
        while (obj->tailSize != 0)
            obj->head[obj->headSize++] = obj->tail[--obj->tailSize];

    return obj->head[--obj->headSize];
}

/** Get the front element. */
int myQueuePeek(MyQueue *obj)
{
    if (obj->headSize == 0)
        while (obj->tailSize != 0)
            obj->head[obj->headSize++] = obj->tail[--obj->tailSize];

    return obj->head[obj->headSize - 1];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue *obj)
{
    return !(obj->headSize || obj->tailSize);
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
