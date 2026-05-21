#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int num;
    char name[20];
    struct data * next;
}data;

data * g_head = NULL;
data * g_tail = NULL;

void print_All()
{
    data * temp = g_head;

            while(temp->next){
            printf("=====s=====\n");
            printf("num : %d\n", temp -> num);
            printf("name : %s\n", temp -> name);
            printf("=====e=====\n");
                        
            temp = temp -> next;
            }
        
            printf("=====s=====\n");
            printf("num : %d\n", temp -> num);
            printf("name : %s\n", temp -> name);
            printf("=====e=====\n");
}

int insert(int num, char * name)
{
    data * node = malloc(sizeof(data));

    node -> num = num;
    
    if(name != NULL){
        strcpy(node -> name, name);
    }

    node -> next = NULL;

    if(g_head == NULL){
        g_head = node;
        g_tail = node;
        return 1;
    }
    else{
        data * temp = g_head;

        while(temp -> next){
                temp = temp -> next;
        }
    
            temp -> next = node;
            g_tail = node;
            return 1;
    }
    return 0;
}

data * statck_pop()
{
    if(g_head == NULL){
        return NULL;
    }

    data * node;
    memcpy(node, g_tail,sizeof(data));

    data * temp = g_head;
    data * before = NULL;

        while(temp -> next){
            before = temp;
            temp = temp -> next;
        }
            g_tail = before;
            if(g_tail == NULL){
                g_tail = NULL;
            }
  
    free(g_tail);

    return node;
}

int main()
{
    char name[20] = "";

    for(int i=0; i<10; i++){
        sprintf(name, "test%d",i);
        insert(i, name);
    }
    print_All();

    data * node1 = statck_pop();

    printf("pop num : %d\n", node1 -> num);
    printf("pop name : %s\n", node1 -> name);

    print_All();
}