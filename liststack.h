typedef int data_t;
typedef struct node{
data_t data;
struct node *next;
}linkstack, *liststack;
liststack stack_create();
data_t stack_push(liststack L, data_t value);
data_t stack_topcheck(liststack L);
data_t stack_pop(liststack L);
int stack_emptycheck(liststack L);
int stack_free(liststack L);
