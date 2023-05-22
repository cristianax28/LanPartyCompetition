#include "functii.h"
int main(int argc, char *argv[])
{
    ECHIPA *head = (ECHIPA *)malloc(sizeof(ECHIPA));
    head = NULL;
    int nr_echipe;
    int cerinte[5];
    FILE *c, *fisier, *rezultate;
    if ((c = fopen(argv[1], "rt")) == NULL)
    {
        printf("eroare la deschiderea fisierului c");
        exit(1);
    }
    if ((fisier = fopen(argv[2], "rt")) == NULL)
    {
        printf("eroare la deschiderea fisierului fisier");
        exit(1);
    }
    if ((rezultate = fopen(argv[3], "wt")) == NULL)
    {
        printf("eroare la deschiderea fisierului r");
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &cerinte[i]);
    }

    fscanf(fisier, "%d", &nr_echipe);
    for (int i = 0; i < nr_echipe; i++)
    {
        addAtBeginning(&head, fisier);
        fgetc(fisier);
    }
    if (cerinte[0] == 1 && cerinte[1] == 0)
    {
        ECHIPA *head_copy = head;
        for (int i = 0; i < nr_echipe && head_copy != NULL; i++)
        {
            fprintf(rezultate, "%s\n", head_copy->nume_echipa);
            head_copy = head_copy->next;
        }
        fclose(fisier);
        fclose(rezultate);
    }

    // 2
    // calculeaza n maxim putere a lui 2

    
    if (cerinte[1] == 1)
    {
        if ((rezultate = fopen(argv[3], "wt")) == NULL)
        {
            printf("eroare la deschiderea fisierului r");
            exit(1);
        }
        int puncte_echipa, nr_jucatori;
        float min;
        int n = 1;
    //int runde=0;
    while (n * 2 < nr_echipe)
    {
        n = n * 2;
        //runde++;
    }
        // calculeaza punctajul fiecarei echipa
        ECHIPA *head2 = (ECHIPA *)malloc(sizeof(ECHIPA));
        head2 = head;
        while (head2 != NULL)
        {
            head2->puncte_echipa = 0;
            for (int k = 0; k < head2->nr_jucatori; k++)
                head2->puncte_echipa = head2->puncte_echipa + head2->jucator[k].points;
            head2->puncte_echipa = head2->puncte_echipa / (head2->nr_jucatori * (1.0));
            head2 = head2->next;
        }
        // calculeaza minimul si elimina din lista echipele cu punctajul minim pana cand raman n echipe o putere a lui 2 si n este maxim
        while (nr_echipe > n && head != NULL)
        {
            ECHIPA *headcopy2 = (ECHIPA *)malloc(sizeof(ECHIPA));
            headcopy2 = head;
            min = headcopy2->puncte_echipa;
            headcopy2 = headcopy2->next;
            for (int i = 0; i < nr_echipe && headcopy2 != NULL; i++)
            {
                if (headcopy2->puncte_echipa < min)
                    min = headcopy2->puncte_echipa;
                headcopy2 = headcopy2->next;
            }

            delete (&head, min);
            nr_echipe--;
        }
        ECHIPA *headcopy3 = (ECHIPA *)malloc(sizeof(ECHIPA));
        headcopy3 = head;
        while (headcopy3 != NULL)
        {
            fprintf(rezultate, "%s\n", headcopy3->nume_echipa);
            headcopy3 = headcopy3->next;
        }
        free(headcopy3);
    }
    fclose(rezultate);
    fclose(c);
}

/*3

if (cerinte[2] == 1)
{
    int i, nr_runde= 1;
    if ((rezultate = fopen(argv[3], "wt")) == NULL)
    {
        printf("eroare la deschiderea fisierului r");
        exit(1);
    }
    ECHIPA *teamcopy = (ECHIPA *)malloc(sizeof(ECHIPA));
    teamcopy = head;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q = createqueue();
    for (i = 0; i < nr_echipe && teamcopy != NULL; i++)
    {
        enQueue_coada1(q, teamcopy);
        teamcopy = teamcopy->next;
    }
    // return 0;
    fclose(rezultate);
    STACK *winners = (STACK *)malloc(sizeof(STACK));
    winners = NULL;
    STACK *losers = (STACK *)malloc(sizeof(STACK));
    losers = NULL;
    while (nr_runde<=runde)
    {
       //ELEM *team1 = (ELEM*)malloc(sizeof(ELEM));
        //ELEM*team2 = (ELEM*)malloc(sizeof(ELEM));
        /*ECHIPA *headcopy3 = (ECHIPA *)malloc(sizeof(ECHIPA));
        headcopy3 = teamcopy;
        fprintf(rezultate,"--- ROUND NO: %d",nr_runde);
        while (q->front!= NULL && q->front->next!=NULL)
        { fprintf(rezultate,"%s",q->front->name);
        for(int i=0;i<nr_echipe;i++)
        fprintf(rezultate,"%c",' ');
        fprintf(rezultate,"%c",'-');
            if (q->front->punctaj > q->front->next->punctaj)
            {
                q->front->punctaj = q->front->next->punctaj + 1;
                push(&winners, q);
                push(&losers, q);
            }
            else
            {
                q->front->next->punctaj = q->front->next->punctaj + 1;
                push(&winners, q);
                push(&losers, q);
            }
            if (q->front->punctaj == q->front->next->punctaj)
            {
                q->front->punctaj = q->front->punctaj + 1;
                push(&winners, q);
                push(&losers, q);
            }

            if (isQueueEmpty(q))
            {
                while (!isStackEmpty(winners))
                {
                    pop(&winners);
                    enQueue(q, winners);
                }
                while (!isStackEmpty(losers))
                {
                    deleteStack(&losers);
                }
            }
        }
        /*ELEM *top_teams = (ELEM *)malloc(8 * sizeof(ELEM));
        for (i = 0; i < 8; i++)
            top_teams[i] = pop(&winners);*/
           // nr_runde++;
    

    /*if (rounds == 1)
     {
         fprintf(rezultate, "%s    -", headcopy3->next->nume_echipa);
         // ELEM *team1=(ELEM*)malloc(sizeof(team1));
         if (headcopy3->puncte_echipa < headcopy3->next->puncte_echipa)
         {
             push(stackLooser, headcopy3->puncte_echipa->nume_echipa);
             push(stackWinner, headcopy3->next->puncte_echipa->nume_echipa);
             headcopy3->puncte_echipa = headcopy3->puncte_echipa + 1;
         }
         else
         {
             push(stackWinner, headcopy3->puncte_echipa->nume_echipa);
             headcopy3->puncte_echipa = headcopy3->puncte_echipa + 1;
             push(stackLooser, headcopy3->next->puncte_echipa->nume_echipa);
         }
         headcopy3 = headcopy3->next->next;
         fprintf(rezultate, "     -%s\n", headcopy3->next->nume_echipa);
         headcopy3 = headcopy3->next->next;
         /*if(headcopy3->puncte_echipa==headcopy3->next->puncte_echipa)
         {
             push(stackWinner, headcopy3->puncte_echipa->nume_echipa);
             headcopy3->puncte_echipa = headcopy3->puncte_echipa + 1;
             push(stackLooser, headcopy3->next->puncte_echipa->nume_echipa);
         }
         rounds++;
         nr_echipe = nr_echipe / 2;
     }
     else
     {
         while (stackLooser != NULL)
         {
             ECHIPA *top = (ECHIPA *)malloc(sizeof(ECHIPA));

             deleteStack(&top);
         }
         ECHIPA *cpy = (ECHIPA *)malloc(sizeof(ECHIPA));
         cpy = head;
         while (stackWinner != NULL && cpy != NULL)
         {
             for (int i = 0; i < cpy->nr_echipe; i++)
                 fprintf(rezultate, "%s    ", cpy->nume_echipa);
             fprintf(rezultate, "     -%s", cpy->nume_echipa);

             cpy = cpy->next;
             pop(cpy);
             enQueue(&q, cpy);
             rounds++;
             nr_echipe=nr_echipe/2;
         }
         if()
     }*/
