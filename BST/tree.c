#include"tree.h"
int main(){

    Node* root = NULL;

    root->data = 12;
    root->left = createNode();
    root->right = createNode();
    root->right->data = 80;
    root->right->right = createNode();
    root->right->right = NULL;
    root->left->data = 10;
    root->left->left = createNode();
    root->left->left = NULL;
    root->left->right = createNode();
    root->left->right = NULL;
    root->right->left->data = 70;
    root->right->left->left = createNode();
    root->right->left->left = NULL;
    root->right->left->right = createNode();
    root->right->left->right = NULL;


   printf("number of leaf Nodes: %d",countNoOfLeaf(root));

    // int key,choice;
    // printf("\n\n*****Menu*****\n\n");
    // printf("Enter 1 to insert Node:\n");
    // printf("Enter 2 to delete Node:\n");
    // printf("Enter 3 to print inorder sequence:\n");
    // printf("Enter 4 to print preorder sequence:\n");
    // printf("Enter 5 to print postorder sequence:\n");
    // printf("Enter 6 to view Height of tree:\n");
    // printf("Enter 7 to Exit:\n");

    // while(1){
    // printf("\nEnter your Choice:");
    // scanf("%d",&choice);
    // switch(choice)
    // {
    // case 1:
    //   printf("\nEnter value of Key you want to insert: ");
    //   scanf("%d",&key);
    //   insert(&root,key);
    //   break;

    // case 2:
    //   printf("\nEnter value of Key you want to delete: ");
    //   scanf("%d",&key);
    //   delete(root,key);
    //   break;  

    // case 3:
    //   printf("\nInorder:\n");
    //   inorder(root);
    //   break;  

    // case 4:
    //   printf("\nPreorder:\n");
    //   preorder(root);
    //   break;   
    
    // case 5:
    //   printf("\nPostorder:\n");
    //   postorder(root);
    //   break; 

    // case 6:
    // printf("\nHeight of tree is: %d\n",height(root));
    // break;  
    // case 7:
    // exit(0);
    // break;

    // case 8:
    // printf("number of leaf Nodes: %d",countNoOfLeaf(root));
    // break;

    // default:
    // printf("\nEnter a valid choice!!!\n");
    //   break;
    // }
    // }


  return 0;
}