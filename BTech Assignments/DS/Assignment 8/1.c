// Inorder, Preorder, Postorder traversal
// For a Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

// Structure for binary tree
struct Leaf 
{
   int data;
   struct Leaf *left;
   struct Leaf *right;
};

// User-defined functions header file
#include "Functions1.h"

// MAIN
int main()
{
   struct Leaf *root = NULL;

   // Inserting some random values
   Insert(&root, 6);
   Insert(&root, 2);
   Insert(&root, 4);
   Insert(&root, 5);
   Insert(&root, 0);
   Insert(&root, 1);
   Insert(&root, 3);
   Insert(&root, 8);
   Insert(&root, 7);
   Insert(&root, 9);

   // INorder display
   printf("Inorder : \n");
   inPrint(root);
   printf("\n\n");

   // PREorder display
   printf("Preorder : \n");
   prePrint(root);
   printf("\n\n");

   // POSTorder display
   printf("Postorder : \n");
   postPrint(root);
   printf("\n\n");

   return 0;
}