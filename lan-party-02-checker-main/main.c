#include "functii.h"
int main(int argc, char *argv[])
{
    ECHIPA *head = (ECHIPA *)malloc(sizeof(ECHIPA));
    head = NULL;
    int nr_echipe;
    int cerinte[5];
    //deschiderea fisierelor
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
    //citirea din fisierul c a vectorului de cerinte
    for (int i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &cerinte[i]);
    }
    fscanf(fisier, "%d", &nr_echipe);
    //se formeaza lista prin adaugarea elementelor la inceput
    for (int i = 0; i < nr_echipe; i++)
    {
        addAtBeginning(&head, fisier);
        fgetc(fisier);
    }
    //afisarea listei
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
    int runde = 0;//numarul de runde de la task 3
    int n = 1;
    while (n * 2 < nr_echipe)
    {
        n = n * 2;
        runde++;
    }

    if (cerinte[1] == 1)
    {if ((rezultate = fopen(argv[3], "wt")) == NULL)
    {
        printf("eroare la deschiderea fisierului r");
        exit(1);
    }
        
        int puncte_echipa, nr_jucatori;
        float min;
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
            free(headcopy2);
        }
        //afisarea echipelor ramase
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

    // 3

    if (cerinte[2] == 1)
    {if ((rezultate = fopen(argv[3], "wt")) == NULL)
    {
        printf("eroare la deschiderea fisierului r");
        exit(1);
    }
        int i, nr_runde = 1;
        // crearea cozii si adaugarea elementelor din lista in coada
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
        // stiva de castigatori
        STACK *winners = (STACK *)malloc(sizeof(STACK));
        winners = NULL;
        // stiva de invinsi
        STACK *losers = (STACK *)malloc(sizeof(STACK));
        losers = NULL;
        while (nr_runde <= runde)
        {
            fprintf(rezultate, "--- ROUND NO: %d", nr_runde);

            while (q->front != NULL)
            {
                // se compara echipele si se pun castigatorii in lista de castigatori, iar invinsii in lista de invinsi
                if (q->front->punctaj > q->front->next->punctaj)
                {
                    q->front->punctaj = q->front->next->punctaj + 1;//se adauga un punct echipei castigatoare
                    push(&winners, q);
                    q->front = q->front->next;
                    push(&losers, q);
                }
                else if (q->front->punctaj < q->front->next->punctaj)
                {
                    push(&losers, q);
                    q->front = q->front->next;
                    q->front->punctaj = q->front->punctaj + 1;
                    push(&winners, q);
                }
                else
                {
                    q->front->punctaj = q->front->next->punctaj + 1;
                    push(&winners, q);
                    q->front = q->front->next;
                    push(&losers, q);
                }
                q->front = q->front->next;
                //se elibereaza stiva de pierzatori
                while (!isStackEmpty(losers))
                {
                    pop(&losers);
                }
                //din stiva de castigatori se extrag echipele si se pun inapoi in coada pentru a se forma alte meciuri 
                while (!isStackEmpty(winners))
                {
                    enQueue(q, winners);
                    pop(&winners);
                    winners = winners->next;
                }
                nr_runde++;// creste numarul de runde
            }
        }
        free(winners);
        free(losers);
    }
    
}
