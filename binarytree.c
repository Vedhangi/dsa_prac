//binary tree 
//finds infix,postfix,prefix 
//only take numeric input
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    
};
 struct Node *newnode (int d)
    {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = d;
        node->left = node->right = NULL; 
    }

void preorder(struct Node *node){
    if(node == NULL){
        return;
    }else {
        printf(" %d",node->data);
    
    }
    preorder(node->left);
    preorder(node->right);
}
void postorder(struct Node *node)
{
    if(node == NULL)
    {
        return;
    }else{

        postorder(node->left);
        postorder(node->right);
        printf(" %d",node->data);
    }

    }
    void inorder(struct Node *node)
    {
        if(node == NULL)
        {
            return;
        }
        inorder(node->left);
        printf(" %d", node->data);
        inorder(node->right);
    }

int main(){
    int n;
    int value;
     printf("\n Enter the value of root node: ");
    scanf("%d",&value);
    struct Node *root = newnode(value);
   

    int leftval;
     
   
    printf("\n enter the left child node of %d: ",value);
    scanf("%d", &leftval);
    int rightval;
    
    printf("\n enter the right child of node  %d : ", value );
    scanf("%d", &rightval);
    int leftleftval;
   

    printf("\n enter teh value left child of node %d: ",leftval);
    scanf("%d",&leftleftval);
    int leftrigttval;
   

    printf("\n enter teh value right child of node %d: ",leftval);
    scanf("%d",&leftrigttval);
    int rightrightval;
    printf("\n enter teh value left child of node %d: ",rightval);
    scanf("%d",&rightrightval);
    int rightleftval;
    printf("\n enter teh value right child of node %d:",rightval);
    scanf("%d",&rightleftval);


    
    root->left = newnode(leftval);
    root->left->right = newnode(leftrigttval);
    root->left->left = newnode(leftleftval);
    root->right = newnode(rightval);
    root->right->right = newnode(rightrightval);
    root->right->left= newnode(rightleftval);
     
   
    

    printf("\n the preoder traversal is :");
    preorder(root);
    printf("\n the postorder traversal is :");
    postorder(root);
    printf("\n the inoder traversal is:");
    inorder(root);
    return 0;

}
