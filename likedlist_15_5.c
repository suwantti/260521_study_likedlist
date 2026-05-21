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

int insert(int num, char * name)
{
    data * node = malloc(sizeof(data));

    node -> next = NULL;
    node -> num = num;
    
    if(name != NULL){
        strcpy(node -> name, name);
    }

    if(g_head == NULL){
        g_head = node;
        g_tail = node;
        return 1;
    }
}

int main()
{

}