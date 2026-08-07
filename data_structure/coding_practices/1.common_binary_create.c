/*
 * PROJECT : EXERCISES
 * FILE    : 1.common_binary_create.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-02
 * BRIEF   : janny data struct 5.3 递归创建一颗普通的二叉树
 */

/*
 * 二叉树形状
 *           28
 *        16    54
 *      33        89
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// 树(非线形递归)递归创建一颗普通二叉树
static void create(struct node** root) {
    if (root == NULL || *root != NULL) {
        return;
    }

    // 1. 创建一个新节点
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stdout, "mallco failed\n");
        return;
    }
    new_node->left = NULL;
    new_node->right = NULL;

    // 2. 要求用户输入节点数据域存储的数据
    fprintf(stdout, "please input data: ");
    scanf("%d", &new_node->data);

    // 3. 判断用户输入的数据是否是0，若输入的是0，则判断*root的值为NULL，也就是某个节点
    // 无左/右子节点
    // 这也是递归调用的终止条件
    if (new_node->data == 0) {
        free(new_node);
        *root = NULL;
        return;
    }

    // 4. 创建此节点的左子节点
    create(&new_node->left);
    if (new_node->left == NULL) {
        fprintf(stdout, "left node of current node(%d) is NULL\n", new_node->data);
    } else {
        fprintf(stdout, "left node(%d) of current node(%d) is created\n", new_node->left->data,
                new_node->data);
    }

    // 5. 创建此节点的右子节点
    create(&new_node->right);
    if (new_node->right == NULL) {
        fprintf(stdout, "right node of current node(%d) is NULL\n", new_node->data);
    } else {
        fprintf(stdout, "right node(%d) of current node(%d) is created\n", new_node->right->data,
                new_node->data);
    }
    *root = new_node;
}

// 左中右遍历
void middle(struct node* node) {
    if (node == NULL) {
        return;
    }

    middle(node->left);

    printf("%d\n", node->data);

    middle(node->right);
}

// 左右中遍历
void right(struct node* node) {
    if (node == NULL) {
        return;
    }

    middle(node->left);
    middle(node->right);
    printf("%d\n", node->data);
}

// left
void left(struct node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d\n", node->data);
    middle(node->left);
    middle(node->right);
}

int main() {
    struct node* root = NULL;

    create(&root);

    // middle(root);

    right(root);

    // left(root);


    return 0;
}
