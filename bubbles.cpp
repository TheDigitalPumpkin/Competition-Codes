#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std; 
   typedef struct Node
   {
       int key;
       int right;
       int left;
       int rightKey;
       int leftKey;
   } Node; 
      
   typedef struct BST
   {
       Node **vet;
       int numberOfNodes;
       int size;
   } BST; 
      
   Node node; 
   void fillBST(BST *bst, int inicio, int fim, int indice)
   {
      Node *no = (Node*) malloc(sizeof(Node)); 
      no->key = (inicio + fim) / 2; 
      no->leftKey = no->key - inicio - 1;
     
      if(fim - inicio != 2)
      {
         no->left = 2 * indice + 1;
         fillBST(bst, inicio, no->key, no->left);
      } 
     
      else
      {
         no->left = 0;
         no->right = 0;
         no->rightKey = 0;
         bst->vet[indice] = no;
         return;
      } 
     
      if(no->key < bst->numberOfNodes)
      {
         if( fim > bst->numberOfNodes )
         {
            no->rightKey = bst->numberOfNodes - no->key;
         } 
        
         else
         {
            no->rightKey = fim - no->key - 1;
         } 
        
         no->right = 2 * indice + 2;
         fillBST( bst, no->key, fim, no->right );
      }
     
      else 
      {
         no->right = 0;
         no->rightKey = 0;
      } 
     
      bst->vet[indice] = no;
   } 
   
   BST *criaBST(int numberOfNodes)
   {
      BST *bst = (BST*) malloc(sizeof(BST));
      bst->numberOfNodes = numberOfNodes; 
      int root = 1; 
      
      while( numberOfNodes != 1 )
	  {
         root <<= 1;
         numberOfNodes >>= 1;
      } 
      
      bst->vet = (Node**) malloc(root * 2 * sizeof(Node*));
      bst->size = 2 * root;
      memset(bst->vet, '\0', bst->size * sizeof(Node*)); 
      
      if(root != 1)
	  {
         fillBST(bst, 0, bst->size, 0);
      } 
      
      else
	  {
         Node *no = (Node*) malloc(sizeof(Node));
         no->key = 1;
         no->rightKey = 0;
         no->leftKey = 0;
         no->left = 0;
         no->right = 0; 
         bst->vet[0] = no;
      } 
     
      return bst;
   } 
   
   int searchBST(BST* bst, int elemento, int indice, int nos)
   {
      Node *no = bst->vet[indice];
      int key = (no->key != 0) + no->leftKey + nos; 
     
      if(elemento == key && no->key && no->key <= bst->numberOfNodes)
	  {
         int oldValue = no->key;
         no->key = 0;
         return oldValue - 1;
      } 
      
      else if(elemento <= key)
	  {
         no->leftKey--;
         return searchBST(bst, elemento, 2*indice + 1, nos);
      } 
      
      else
	  {
         no->rightKey--;
         return searchBST(bst, elemento, 2*indice + 2, key);
      }
   } 
   
   void destroiBST(BST **bst)
   {
      int i; 
      for(i = 0; i < (*bst)->size; i++)
	  {
         free((*bst)->vet[i]);
      } 
      
      free(*bst);
   } 
   
   int main()
   {
      int numeros, trocas; 
      
      while(scanf( "%d%d", &numeros, &trocas ))
	  {
         if(!numeros){
            return 0;
      } 
      
      BST *bst = criaBST(numeros);
      int i = 0, j = 0, numero, v[numeros];
      memset( v, '\0', numeros * sizeof( int ) );
         
      for(;i < trocas; i++)
      {
          scanf( "%d", &numero );
          int pos = searchBST(bst, numero + 1, 0, 0 );
          v[pos] = i + 1;
      } 
         
      for(; j < numeros; j++)
	  {
          if(!v[j])
		  {
             v[j] = ++i;
          } 
          
          printf( "%d ", v[j] );
      } 
         
         printf( "\n" ); 
         destroiBST( &bst );
      } 
      
      return 0;
   }
