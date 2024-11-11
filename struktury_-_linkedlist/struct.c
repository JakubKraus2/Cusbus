#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int value;
    struct node * next;
};


int main(int argc, char* argv[])
{

    // ....

    struct node node2 = {1, NULL};
    struct node head = {1, &node2};
    struct node * node1 = &head;

    do {
        // ...

        node1 = node1->next;
    }
    while (node1 != NULL);


    return 0;
}