#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

/*链表栈创建函数*/
liststack stack_create()
{
   liststack L=(liststack)malloc(sizeof(linkstack));
   if(L == NULL)
   {
    printf("the memory assigning failed!\n");
    return NULL;
   }
   L->data = 0;
   L->next = NULL;
   return L;
}

/*入栈函数*/
data_t stack_push(liststack L, data_t value)
{
 //判断栈指针L的内存分配是否成功
   if(L==NULL)
   {
      printf("the memory assigning for head failed!\n");
      return -1;
   }
 //创建入栈的新结构体指针
   liststack p = (liststack)malloc(sizeof(linkstack));
   if(p==NULL)
   {
      printf("the memory assigning for insert failed!\n");
      return -1;
   }
 //插入新节点
   p->data = value;
   p->next = NULL;
   p->next = L->next;
   L->next = p; 
   printf("push:%d\n", p->data);
   return 0;
}

/*栈顶元素查看函数*/
data_t stack_topcheck(liststack L)
{
 //判断栈指针L的内存分配是否成功
   if(L==NULL)
   {
      printf("the memory assigning for head failed!\n");
      return -1;
   }
 //返回栈顶元素
 return L->next->data;
}

/*出栈函数*/
data_t stack_pop(liststack L)
{
 //判断栈指针L的内存分配是否成功
   if(L==NULL)
   {
      printf("the memory assigning for head failed!\n");
      return -1;
   }
 //删除节点
   liststack q;
   data_t t;
   q = L->next;
   t = L->next->data;
   L->next = q->next;
   free(q);
   return t;
}

/*栈空判断函数*/
int stack_emptycheck(liststack L)
{
 //判断栈指针L的内存分配是否成功
   if(L==NULL)
   {
      printf("the memory assigning for head failed!\n");
      return -1;
   }
   if(L->next == NULL)
   {
      printf("the stack is empty, there is no need to pop!\n");
      return -1;
   }
   return 0;
}

/*栈空间释放函数：删除所有节点包括头节点*/
int stack_free(liststack L)
{
  //判断栈指针L的内存分配是否成功
   if(L==NULL)
   {
      printf("the memory assigning for head failed!\n");
      return -1;
   }
   while(L!=NULL)
   {
      liststack q = L;
      L = L->next;
      free(q); 
   }
   return 0;
}
