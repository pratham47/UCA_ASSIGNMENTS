typedef struct {
    int top;
    int top_min;
    int arrVal[10000];
    int minVal[10000];
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack)*1);
    stack->minVal[0] = INT_MAX;
    stack->top = -1;
    stack->top_min = -1;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    int min = obj->minVal[obj->top_min];
    if((x <= min) || (obj->top_min == -1))
    {
        obj->top_min = obj->top_min + 1;
        obj->minVal[obj->top_min] = x;
    }
    obj->top = obj->top + 1;
    obj->arrVal[obj->top] = x;
}

void minStackPop(MinStack* obj) {
  if(obj->arrVal[obj->top] == obj->minVal[obj->top_min])
  {
      obj->top_min = obj->top_min - 1;
  }
  obj->top = obj->top - 1;
}

int minStackTop(MinStack* obj) {

  return obj->arrVal[obj->top];
}

int minStackGetMin(MinStack* obj) {
  return obj->minVal[obj->top_min];
}

void minStackFree(MinStack* obj) {
    free(obj);
}
