#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int k;
    int p;
    int aux;
    int x;
    int y;
    int i;
    int j;

    for (y = 0 ; y < 9 ; y++) {
        for (x = 0 ; x < 9 ; x++) {
            aux = n->sudo[x][y];
            if (n->sudo[x][y] != 0) {
                for (i = 0 ; i < 9 ; i++) {
                    if ((i != x) && (n->sudo[i][y] == aux)) {
                        return 0;
                    }
                }
                for (j = 0 ; j < 9 ; j++) {
                    if ((j != y) && (n->sudo[x][j] == aux)) {
                        return 0;
                    }
                }
                k = (x/3)*3 + y/3;
                for (p = 0 ; p < 9 ; p++) {
                    i = 3*(k/3) + (p/3) ;
                    j = 3*(k%3) + (p%3) ;
                    if (n->sudo[i][j] == aux) {
                        if ((i != x) || (j != y)) {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}


List* get_adj_nodes(Node* n) {
    List* list=createList();
    int i;
    int j;
    int num;
    for (i = 0; i < 9; i++){
      for (j = 0; j < 9; j++){
        if ( n->sudo[i][j] == 0){
          for ( num = 1; num <= 9; num++){
            n->sudo[i][j] = num;
            if (is_valid (n) ){
              Node *newnode = copy(n);
              pushBack(list, newnode);
            }
          }
          n->sudo[i][j] = 0;
          return list;
        }
      }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/