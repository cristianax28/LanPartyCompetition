#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char *firstName;
    char *secondName;
    int points;
};
typedef struct Player JUCATOR;
struct echipa
{
    JUCATOR *jucator;
    char *nume_echipa;
    int nr_jucatori;
    float puncte_echipa;
    struct echipa *next;
};
typedef struct echipa ECHIPA;
void addAtBeginning(ECHIPA **head, FILE *fisier);
void delete(ECHIPA **head, float min);
//coada

struct element
{
    char *name;
    float punctaj;
    struct element *next;
};

typedef struct element ELEM;
struct Q
{
    ELEM *front; // adresa primei echipe din coada
    ELEM *rear;  // adresa ultimei echipe din coada
};
typedef struct Q Queue;
// stiva
struct stiva
{
    char *stiva_name;
    float stiva_punctaj;
    struct stiva *next;
};
typedef struct stiva STACK;
typedef struct loosers stackLooser;
void addAtBeginning(ECHIPA **head, FILE *fisier);
void delete(ECHIPA **head, float min);
void enQueue(Queue *q, STACK *echipa);
Queue *createqueue();
void push(STACK **top, Queue *stackteam);
int isStackEmpty(STACK *top);
int isQueueEmpty(Queue *q);
void pop(STACK **top);
void enQueue_coada1(Queue *q, ECHIPA *echipa);
