#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node; 

Node* createNode(){
    Node* r = (Node*)malloc(sizeof(Node));
    if(r!=NULL)
        return r;
    else
        return NULL;     
}

void treeNode(Node** root,int key){
    *root = createNode();
    (*root)->data = key;
    (*root)->left = createNode();
    (*root)->left = NULL;
    (*root)->right = createNode();
    (*root)->right = NULL;

}

int countNoOfLeaf(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    } 
    int ls = countNoOfLeaf(root->left);
    int rs = countNoOfLeaf(root->right);
    
    return (ls+rs);
}

Node* insert(Node** root,int key){
    Node* newNode = createNode();
    newNode->data = key;
    newNode->left = createNode();
    newNode->left = NULL;
    newNode->right = createNode();
    newNode->right = NULL;
    if(*root==NULL){
        *root = newNode;
    }else if((*root)->data>key){
        insert(&((*root)->left),key);
    }else{
        insert(&((*root)->right),key);
    }

    return *root;
}

Node* inorderSuccessor(Node* root){
    while((root)->left!=NULL){
        root = (root)->left;
    }

    return root;
}

Node* delete(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if((root)->data>key){
        root->left = delete((root)->left,key);
    }else if((root)->data<key){
        root->right = delete((root)->right,key);
    }else{
        //0 child
        if((root)->left==NULL && (root)->right==NULL){
            free(root);
            return NULL;
        }

        //1 child
        if((root)->left==NULL){
            Node* fr = (root)->right;
            free(root);
            return fr;
        }else if((root)->right==NULL){
            Node* fr =  (root)->left;
            free(root);
            return fr;
        }

        //2 child
        Node* is = inorderSuccessor((root)->right);
        (root)->data = is->data;
        root = delete(root,is->data);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh>rh){
        return lh+1;
    }else if(lh==rh){
        return lh+1;
    }else{
        return rh+1;
    }
}

