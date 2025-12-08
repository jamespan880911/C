#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

void preorder(struct TreeNode *root){
    if (root == NULL){
        return;
    }

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode *root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void postorder(struct TreeNode *root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int maxDepth(struct TreeNode *root){
    if (root  == NULL){
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    //遞迴去找左右哪邊比較深
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int countNodes(struct TreeNode *root){
    if (root == NULL){
        return 0;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return 1 + leftCount + rightCount;
}

struct TreeNode* searchBST(struct TreeNode *root, int target){
    if (root == NULL){
        return NULL;
    }

    //要記得return 左右子樹的BST funtion，找的的答案才會傳到Stack的最上層來
    if (target == root->val){
        return root;
    }
    else if (target < root->val){
        return searchBST(root->left, target);
    }
    else{
        return searchBST(root->right, target);
    }

    return NULL;
}