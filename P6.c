#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int front, rear;
    char items[MAX];
} deque;

void init(deque *d) {
    d->front = MAX/2;
    d->rear = MAX/2 - 1;
}

void insertFront(deque *d, char c) {
    if(d->front == 0) {
        printf("La cola está llena.\n");
        exit(1);
    }
    d->items[--d->front] = c;
}

void insertRear(deque *d, char c) {
    if(d->rear == MAX-1) {
        printf("La cola está llena.\n");
        exit(1);
    }
    d->items[++d->rear] = c;
}

char deleteFront(deque *d) {
    if(d->front > d->rear) {
        printf("La cola está vacía.\n");
        exit(1);
    }
    return d->items[d->front++];
}

char deleteRear(deque *d) {
    if(d->front > d->rear) {
        printf("La cola está vacía.\n");
        exit(1);
    }
    return d->items[d->rear--];
}

int isPalindrome(char *str) {
    deque d;
    init(&d);
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(isalpha(str[i])) {
            insertRear(&d, toupper(str[i]));
        }
    }
    while(d.front < d.rear) {
        if(deleteFront(&d) != deleteRear(&d)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX];
    printf("\n\t*** Bienvenido al revisor de palabras! ***\n");
    printf("Ingrese una palabra: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    if(isPalindrome(str)) {
        printf("'%s' es un palíndromo.\n", str);
    } else {
        printf("'%s' no es un palíndromo.\n", str);
    }
    return 0;
}

