#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct locate
{
int id;
int x;
int y;
int z;
struct locate * next;

} locate_t;

locate_t *last(locate_t *head){
if (head == NULL) {
    return NULL;
}
else{
    while (head->next) {
        head = head->next;
    }
    return head;
}
}

locate_t *pushb(locate_t * head,int id, int x, int y, int z)
{
    locate_t * tmp = last(head);
    locate_t * current = (locate_t*)malloc(sizeof(locate_t)); // выделение памяти
    current->id = id;
    current->x = x;
    current->y = y;
    current->z = z;
    tmp->next = current;
    if(tmp == NULL){ // проверка на выделение памяти
        printf("Не выделина память\n");
        return NULL;
    }
    else
        return head;
}

int main()
{
    locate_t* test = NULL;
    test = pushb(test,1, 3, 2, 1);
    test = pushb(test,2, 1, 2, 3);
    if  (test)
    printf("%d", test->id);
    

    return 0;
}
