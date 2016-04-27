/*
Scrivere un programma che riceve in input una linea di caratteri e restituisce
una lista in cui i nodi indicano ciascuno il numero delle occorenze di ciascuno
dei caratteri presenti nella linea di input.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <stdio_ext.h>

typedef struct nodo{
  char c;
  int i;
  struct nodo *next;
}Nodo;

int Controllo(char c);
int k=0;
char str[50];

int main(){
  char buffer[200];
  unsigned int i, j;
  int count;
  Nodo *root=NULL, *l;

  printf("Inserisci la frase: ");
  gets(buffer);
  for(i=0;i<strlen(buffer);i++){
    if(Controllo(buffer[i]) || !isalpha(buffer[i]))
      continue;

    count=0;
    for(j=i;j<strlen(buffer);j++)
      if(buffer[i]==buffer[j])
        count++;

    l=(Nodo *)malloc(sizeof(Nodo));
    l->c=buffer[i];
    l->i=count;
    l->next=root;
    root=l;
  }

  while(root!=NULL){
    printf("%c = %d   --->   ", root->c, root->i);
    root=root->next;
  }
  printf("FINE");

  __fpurge(stdin);
  getchar();
}

int Controllo(char c){
  int ok=1, i;
  for(i=0;i<k && ok;i++)
    if(str[i]==c)
      ok=0;

  if(ok)
    str[k++]=c;
  return(!ok);
}