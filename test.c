#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

int main(int argc, char *argv[])
{
   liststack L=stack_create();
   stack_push(L,2);
   stack_push(L,8);
   stack_push(L,10);
   stack_push(L,55);
   stack_push(L,21);
   stack_push(L,22);
   printf("the top of the liststack is %d\n",stack_topcheck(L));
   if((stack_emptycheck(L))==0)
   {
      printf("not empty!\n");
   }

   while(!stack_emptycheck(L))
   {
     printf("pop:%d\n",stack_pop(L));
   }
   stack_free(L);
   return 0;
}
