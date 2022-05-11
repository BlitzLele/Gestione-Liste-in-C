//Sorrentino Samuele
//4 INA

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef struct list_element                             //Dichiarazione della lista
{
	char nome[20];
	char cognome[20];
    int eta;
	float stipendio;
    struct list_element *next;
}
item;

typedef item *list;

list input(char nome[], char cognome[], int eta, float stipendio, list l);                              //Funzione in cui l'utente inserisce i dati nella lista
void output(list l);                                                                                    //Funzione in cui il programma stampa i dati della lista
list modifica(list l);
list cancella(list l);
void max_min(list l);
float media(list l);
void ricerca(list l);
void intestazione();

int main()
{
    intestazione();
    list root=NULL;
    list tmp=NULL;
    list l;
    int i;                                              //Variabile usata nei cicli e come indice
    int scelta;                                         //Variabile che viene usata nel menù di scelta
    char nome[20];
    char cognome[20];
    int eta; 
    float stipendio;
    int controllo;                                      //Variabile per il controllo della Lista

    do
    {
        printf("\n");
        printf("\n");
        printf ("Scegli una tra queste operazioni:\n\n");
        printf("(1)Inserimento Ordinato di una Persona nella Lista\n"); 
        printf("(2)Stampare la Lista\n");
        printf("(3)Aggiornare i Dati di una Persona\n");
        printf("(4)Cancellare una Persona dalla Lista\n");
        printf("(5)Ricercare l'Eta' Maggiore e Minore nella Lista\n");
        printf("(6)Visualizzare la Media degli Stipendi degli Persone\n");
        printf("(7)Ricercare una Persona nella Lista\n");
        printf("(0)Uscire dal Programma\n");
        printf("\n");
        printf("\n");
        printf("La tua scelta: \t");
        scanf ("%d", &scelta);
            switch (scelta)
            {
                case 1:;

                        printf("\n");
                        controllo++;
                        printf("Inserisci il Nome: ");
                        scanf("%s", nome);
                        printf("Inserisci il Cognome: ");
                        scanf("%s", cognome);
                        printf("Inserisci lo Stipendio: ");
                        scanf("%f", &stipendio);
                        printf("Inserisci l'Eta': ");
                        scanf("%d", &eta);
                        root=input(nome,cognome,eta,stipendio,root);
                        break;

                case 2:;

                        printf("\n");
                        if(controllo < 1) 
                        {
                            printf("\nImpossibile Eseguire la Richiesta! Lista attualmente vuota.\n");
                        } 
                        else 
                        {
                            output(root);
                        }              
                        break;

                case 3:;

                        printf("\n");
                        if(controllo < 1) 
                        {
                            printf("\nImpossibile Eseguire la Richiesta! Lista attualmente vuota.\n");
                        } 
                        else 
                        {
                            l=root;
                            root=modifica(root);
                        }
                        break;

                case 4:;

                        printf("\n");
                        if(controllo < 1) 
                        {
                            printf("\nImpossibile Eseguire la Richiesta! Lista attualmente vuota.\n");
                        } 
                        else 
                        {
                            controllo--;
                            l=root;
                            root=cancella(root);
                        }
                        break;

                case 5:;

                        printf("\n");
                        if(controllo < 1) 
                        {
                            printf("\nImpossibile Eseguire la Richiesta! Lista attualmente vuota.\n");
                        } 
                        else 
                        {
                            l=root;
                            max_min(root);
                        }
                        break;

                case 6:;

                        printf("\n");
                        if(controllo < 1) 
                        {
                            printf("\nImpossibile Eseguire la Richiesta! Lista attualmente vuota.\n");
                        } 
                        else 
                        {
                            l=root;
                            printf("La Media degli Stipendi della Lista e'--> %0.2f \n", media(root));
                        }
                        break;

                case 7:; 

                        printf("\n");
                        if(controllo < 1) 
                        {
                            printf("\nImpossibile Eseguire la Richiesta! Lista attualmente vuota.\n");
                        }
                        else 
                        {
                            l=root;
                            ricerca(root);
                            /*
                            if (tmp != NULL)
                            {
                                printf("\nLa Persona e' stata Trovata\n");
                                printf("\nNome: %s", tmp->nome);
                                printf("\nCognome: %s", tmp->cognome);
                                printf("\nEta: %d", tmp->eta);
                                printf("\nStipendio: %f\n", tmp->stipendio);
                            }
                            else
                            {
                                printf("Errore! Questa Persona non e' Presente Nella Lista\n");
                            }
                        }
                        */
                        }
                        break;

                case 0:;

                        printf("\n");
                        printf("Uscita in Corso dal Programma");
                        sleep(2);
                        exit(1);
                        break;
            }
    }
    while(scelta!=0);
}

list input(char nome[], char cognome[], int eta, float stipendio, list l)                               
{
    printf("\n");
    list prec=NULL;
    list tmp=NULL;
    list patt=l;
    int flag=0;
    while (patt != NULL && !flag)
    {
        if(strcmp(cognome, patt->cognome)<0)
        {
            flag=1;
        }
        else if(strcmp(cognome, patt->cognome)==0 && strcmp(nome, patt->nome)<0)
        {
            flag=1;
        }
        if (flag==0)
        {
            prec=patt;
            patt=patt->next;
        }
    }
    tmp=(list)malloc(sizeof(item));
    strcpy(tmp->nome, nome);
    strcpy(tmp->cognome, cognome);
    tmp->eta=eta;
    tmp->stipendio=stipendio;
    tmp->next=patt;
    if (patt == l)
    {
        return tmp;
    }
    else
    {
        prec->next=tmp;
    }
    return l;
}

void output(list l)               
{
    int i;
    printf("La lista contiene i seguenti dati: \n");
    while(l != NULL)
        {
            printf("\n");
            printf("Nome: %s\n", l->nome);
            printf("Cognome: %s\n", l->cognome);
            printf("Stipendio: %f\n", l->stipendio);
            printf("Eta': %d\n", l->eta);
            l=l->next;
        }
}

list modifica(list l) 
{
    list tmp=NULL;
    int i=0;
    char cognome[20];
    int scelta;
    tmp=l;

    printf("Inserisci il Cognome della Persona da Modificare: ");
    scanf("%s", &cognome[i]);
    while(tmp != NULL)
	{
	    if(strcmp(cognome, tmp->cognome)==0)
		{
			printf("Il Cognome Inserito e' stato Trovato \n");
		
		    /*
		    while(tmp != NULL)
		    {
		        printf("(%d) %s %s\n", i, tmp->nome, tmp->cognome);
		        tmp=tmp->next;
		        i++;
		    }
		    printf("\n-> ");
		    do
		    {
		        scanf("%d", &scelta);
		    }
		    while(scelta<1 || scelta>i);
		
		    tmp=l;
		
		    for(i=1 ; i!=scelta ; i++) 
		    {
		        tmp=tmp->next;
		    }
		    */
		    printf("\nModifica del contatto: \n\n");
		    printf("Inserisci il Nome: ");
		    scanf("%s", tmp->nome);
		    printf("Inserisci il Cognome: ");
		    scanf("%s", tmp->cognome);
		    printf("Inserisci lo Stipendio: ");
		    scanf("%f", &tmp->stipendio);
		    printf("Inserisci l'Eta': ");
		    scanf("%d", &tmp->eta);
	    
	    	return l;
		}
		else
		{
			tmp=tmp->next;
		}
	}
}

list cancella(list l) 
{
    int i=0;
    int scelta;
    char cognome[20];
    list prec=NULL;
    list succ=NULL;
    list tmp=NULL;
    tmp=prec=l;
	
	printf("Inserisci il Cognome della Persona da Cancellare: ");
	scanf("%s", &cognome[i]);
	while(tmp != NULL)
	{
	    if(strcmp(cognome, tmp->cognome)==0)
		{
			printf("Il Cognome Inserito e' stato Trovato \n");
			/*
		    while(tmp != NULL)
		    {
		        printf("(%d) %s %s\n", i, tmp->nome, tmp->cognome);
		        tmp=tmp->next;
		        i++;
		    }
		    printf("\n-> ");
		    do
		    {
		        scanf("%d", &scelta);
		    }
		    while(scelta < 1 || scelta > i);
		
		    tmp=prec;
		    
		    //Si scala la lista per trovare il contatto
		
		    if(scelta == 1) 
		    {
		        tmp=tmp->next;
		        free(prec);
		    } 
		    */
	    	tmp=tmp->next;
	        free(prec);
	        sleep(1);
	        printf("Il Cognome Inserito e' stato Cancellato \n");
	    }
	}
    return tmp;
}

void max_min(list l)
{
    int max;
    int min;
    list tmp=l;
    max=l->eta;
    min=l->eta;
    l=l->next;
    while (l != NULL)
    {
        if(max < l->eta)
        {
            max = l->eta;
        }
        if(min > l->eta)
        {
            min = l->eta;
        }
        l=l->next;
    }
    l=tmp;
    while (l != NULL)
    {
        if(max == l->eta)
        {
            printf("La Persona con Eta' Maggiore e': \n\n");
            printf("Nome: %s\n", l->nome);
            printf("Cognome: %s\n", l->cognome);
            printf("Stipendio: %f\n", l->stipendio);
            printf("Eta': %d\n", l->eta);
        }
        l=l->next;
    }
    l=tmp;
    printf("\n");
    while (l != NULL)
    {
        if(min == l->eta)
        {
            printf("La Persona con Eta' Minore e': \n\n");
            printf("Nome: %s\n", l->nome);
            printf("Cognome: %s\n", l->cognome);
            printf("Stipendio: %f\n", l->stipendio);
            printf("Eta': %d\n", l->eta);
        }
        l=l->next;
    }
}

float media(list l)
{
    list tmp=l;
    int cont=0;
    int somma=0;
    float media;  
    
    while (tmp != NULL)
    {
        somma=somma+tmp->stipendio;
        tmp=tmp->next;
        cont++;
    }
    tmp=l;
    while (tmp != NULL)
    {
        if (tmp->stipendio <= media)
        {
            printf("%s %s possiede uno Stipendio Minore o Uguale rispetto alla Media\n\n", tmp->cognome, tmp->nome);
            tmp=tmp->next;
        }
        else
        {
            printf("%s %s possiede uno Stipendio Maggiore rispetto alla Media\n\n", tmp->cognome, tmp->nome);
            tmp=tmp->next;
        }
    }
    media=somma/cont;
}

void ricerca(list l)
{
    int i=0;
    int meta;
    char cognome[20];
    list tmp=l;
    
    printf("Inserisci il Cognome della Persona da Cercare: ");
    scanf("%s",&cognome);
    
    while(tmp != NULL)
    {
        i++;
        tmp=tmp->next;
    }
    tmp=l;
    meta=i/2;
    for(i=0 ; i<meta ; i++)
    {
        tmp=tmp->next;
    }
    tmp=l;
    if(strcmp(tmp->cognome,cognome)==0)
    {
        printf("Il Cognome e' stato Trovato al centro della Lista nella Posizione %d",i);
    }

    if(strcmp(tmp->cognome, cognome)>0)
    {
        tmp=l;
        for(i=0; i<meta; i++)
        {    
            if(strcmp(tmp->cognome,cognome)==0)
            {
                printf("Il Cognome e' stato Trovato nella Lista partendo dal Basso");
            }
            tmp=tmp->next;
        }
    }

    if(strcmp(tmp->cognome, cognome)<0)
    {
        while(tmp != NULL)
        {
            if(strcmp(tmp->cognome,cognome)==0)
            {
                printf("Il Cognome e' stato Trovato nella Lista partendo dall'Alto");
            }
            tmp=tmp->next;
        }
    }
}

void intestazione()                                                     
{
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n" , 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c\tSORRENTINO SAMUELE 4 INA\t  %c \n", 179, 179);
    printf(" %c      GESTIONE LISTE 2021/2022          %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c                                        %c\n", 179, 179);
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n" , 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}
