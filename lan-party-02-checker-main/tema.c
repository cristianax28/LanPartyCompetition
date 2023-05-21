#include "functii.h"
void addAtBeginning(ECHIPA **head, FILE *fisier)
{
    int nr_jucatori;
    char nume_echipa[30], firstName[30], secondName[30];
    int points;
    ECHIPA *newNode = (ECHIPA *)malloc(sizeof(ECHIPA));
    // citeste din fisier numarul de jucatori si il baga in lista
    fscanf(fisier, "%d", &nr_jucatori);
    newNode->nr_jucatori = nr_jucatori;
    fgetc(fisier);
    // citeste din fisier numele echipei si il baga in lista
    fscanf(fisier, "%[^\n]", nume_echipa);
    // fgets(nume_echipa,30,fisier);
    fgetc(fisier);
    newNode->nume_echipa = (char *)malloc((strlen(nume_echipa) + 1) * sizeof(char));
    strcpy(newNode->nume_echipa, nume_echipa);
    // aloca memorie pentru un jucator, dupa care citeste pentru fiecare jucator informatii despre el si le pune in lista
    newNode->jucator = (JUCATOR *)malloc((newNode->nr_jucatori) * sizeof(JUCATOR));
    for (int k = 0; k < newNode->nr_jucatori; k++)
    { // fgets(firstName,30,fisier);
        fscanf(fisier, "%s", firstName);
        fgetc(fisier);
        newNode->jucator[k].firstName = (char *)malloc((strlen(firstName) + 1) * sizeof(char));
        strcpy(newNode->jucator[k].firstName, firstName);
        // fgets(secondName,30,fisier);
        fscanf(fisier, "%s", secondName);
        newNode->jucator[k].secondName = (char *)malloc((strlen(secondName) + 1) * sizeof(char));
        strcpy(newNode->jucator[k].secondName, secondName);
        fscanf(fisier, "%d", &points);
        newNode->jucator[k].points = points;
        fgetc(fisier);
    }
    newNode->next = *head;
    *head = newNode;
}
void delete(ECHIPA **head, float min)
{
    if (*head == NULL)
        return;
    ECHIPA *headcopy = (ECHIPA *)malloc(sizeof(ECHIPA));
    headcopy = *head;
    if (headcopy->puncte_echipa == min)
    {
        *head = (*head)->next;
        free(headcopy);
        return;
    }
    ECHIPA *prev = (ECHIPA *)malloc(sizeof(ECHIPA));
    prev = *head;
    headcopy = headcopy->next;
    while (headcopy != NULL)
    {
        if (headcopy->puncte_echipa == min)
        {
            prev->next = headcopy->next;
            free(headcopy);
            return;
        }
        else
        {
            prev = headcopy;
            headcopy = headcopy->next;
        }
    }
}
Queue *createqueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enQueue(Queue *q, ECHIPA *echipa)
{
    ELEM *newNode = (ELEM *)malloc(sizeof(ELEM));
    // atribuie in coada numele echipei si punctajul de echipa
    newNode->name = echipa->nume_echipa;
    newNode->punctaj = echipa->puncte_echipa;
    newNode->next = NULL;
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;
}
void push(ELEM **top, ECHIPA *stackteam)
{
    ELEM *newNode = (ELEM *)malloc(sizeof(ELEM));
    newnode->name = stackteam->nume_echipa;
    newNode->punctaj = stackteam->puncte_echipa;
    newNode->next = *top;
    *top = newNode;
}
int isStackEmpty(ELEM *top)
{
    return top = NULL;
}
ELEM pop(ELEM **top)
{
    if (isEmpty(*top))
        return;
    ELEM *temp = (*top);
    char name = temp->name;
    float punctaj = temp->punctaj;
    *top = (*top)->next;
    free(temp);
}
void deleteStack(ELEM **top)
{
    ELEM *temp;
    while ((*top) != NULL)
        temp = *top;
    *top = (*top)->next;
    free(temp);
}
int isQueueEmpty(Queue *q)
{
    return (q->front == NULL);
}