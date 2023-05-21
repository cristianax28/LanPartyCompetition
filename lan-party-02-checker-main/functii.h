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
// coada
struct Q
{
    ECHIPA *front; // adresa primei echipe din coada
    ECHIPA *rear;  // adresa ultimei echipe din coada
};
typedef struct Q Queue;
struct element
{
    char *name;
    float punctaj;
    struct element *next;
};
typedef struct element ELEM;
// stiva
struct stiva
{
    char *name;
    float punctaj;
    struct stiva *next;
};
typedef struct stiva STACK;
/*stiva pentru castigatori
struct winners
{
    char *name;
    float punctaj;
    struct winners *next;
};
typedef struct winners stackWinner;
//stiva pentru invinsi;
struct loosers
{
    char *name;
    float punctaj;
    struct loosers *next;
};
typedef struct loosers stackLooser;*/
void addAtBeginning(ECHIPA **head, FILE *fisier);
void delete(ECHIPA **head, float min);
void enQueue(Queue *q, ECHIPA *echipa);
Queue *createqueue();
void push(ELEM **top, ECHIPA *stackteam);
int isStackEmpty(ELEM *top);
int isQueueEmpty(Queue *q);
ELEM pop(ELEM **top);
void deleteStack(ELEM **top);
