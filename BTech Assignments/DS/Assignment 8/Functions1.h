// Header file to contain user-defined functions
// For 1.c

// Create a Leaf
struct Leaf *getNewLeaf(int DATA)
{
   struct Leaf *new_leaf = (struct Leaf*)malloc(sizeof(struct Leaf));
   new_leaf->data = DATA;
   new_leaf->left = NULL;
   new_leaf->right = NULL;

   return new_leaf;
}

// Insert a Leaf
void Insert(struct Leaf **rootRef, int DATA)
{
   struct Leaf *new_leaf = getNewLeaf(DATA);

   if (*rootRef == NULL) // Empty Tree
   {
      *rootRef = new_leaf;
      return;
   }

   struct Leaf *temp = *rootRef;
   while (temp != NULL)
   {
      if (DATA < temp->data)
      {
         if (temp->left == NULL)
         {
            temp->left = new_leaf;
            return;
         }
         temp = temp->left;
      }
      if (DATA >= temp->data)
      {
         if (temp->right == NULL)
         {
            temp->right = new_leaf;
            return;
         }
         temp = temp->right;
      }
   }
}

// PREorder Print
void prePrint(struct Leaf *ROOT)
{
   if (ROOT == NULL) // Empty Tree
   {
      printf("Oops!! No leaf in the tree.");
      return;
   }

   struct Leaf *temp = ROOT;

   printf("%d  |  ", temp->data);

   if (temp->left != NULL)
   {
      prePrint(temp->left);
   }

   if (temp->right != NULL)
   {
      prePrint(temp->right);
   }
}

// INorder Print
void inPrint(struct Leaf *ROOT)
{
   if (ROOT == NULL) // Empty Tree
   {
      printf("Oops!! No leaf in the tree.");
      return;
   }

   struct Leaf *temp = ROOT;

   if (temp->left != NULL)
   {
      inPrint(temp->left);
   }

   printf("%d  |  ", temp->data);

   if (temp->right != NULL)
   {
      inPrint(temp->right);
   }
}

// POSTorder Print
void postPrint(struct Leaf *ROOT)
{
   if (ROOT == NULL) // Empty Tree
   {
      printf("Oops!! No leaf in the tree.");
      return;
   }

   struct Leaf *temp = ROOT;

   if (temp->left != NULL)
   {
      postPrint(temp->left);
   }

   if (temp->right != NULL)
   {
      postPrint(temp->right);
   }

   printf("%d  |  ", temp->data);
}
