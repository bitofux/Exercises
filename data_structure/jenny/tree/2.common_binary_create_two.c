/*
 * PROJECT : EXERCISES
 * FILE    : 2.common_binary_create_two.c
 * AUTHOR  : bitofux
 * DATE    : 2026-08-17
 * BRIEF   : 非线形递归创建一棵二叉树
 */
#include <stdio.h>
#include <stdlib.h>

// 节点类型
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// 创建二叉树
struct node* create(void) {
    // 1. 在堆上创建一个struct node类型大小的内存空间
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL) {
        fprintf(stderr, "creating new_node failure\n");
        return NULL;
    }

    new_node->left = NULL;
    new_node->right = NULL;

    // 2. 要求用户输入新结点的值
    scanf("%d", &new_node->data);

    // 3. 判断输入的数据是否为-1
    if (new_node->data == -1) {
        free(new_node);
        return NULL;
    }

    // 4. 为该节点创建它的左右子节点
    new_node->left = create();
    if (new_node->left == NULL) {
        fprintf(stderr, "left node of %d is NULL\n", new_node->data);
    } else {
        fprintf(stdout, "left node of %d is %d\n", new_node->data, new_node->left->data);
    }

    new_node->right = create();
    if (new_node->right == NULL) {
        fprintf(stderr, "right node of %d is NULL\n", new_node->data);
    } else {
        fprintf(stdout, "right node of %d is %d\n", new_node->data, new_node->right->data);
    }

    // 5. 返回当前节点的地址
    return new_node;
}

// 前序遍历
void preOrder(struct node* root) {
    // 1. 若 root 为 NULL，则返回
    if (root == NULL) {
        return;
    }

    // 2. 处理根节点，输出它的值
    printf("%d ", root->data);

    // 3. 处理左子节点
    preOrder(root->left);

    // 4. 处理右子节点
    preOrder(root->right);
}

// 中序遍历
void inOrder(struct node* root) {
    // 1. 若 root 为 NULL，则返回
    if (root == NULL) {
        return;
    }

    // 2. 处理左子节点
    inOrder(root->left);

    // 3. 处理根节点的值
    printf("%d ", root->data);

    // 4. 处理右子节点
    inOrder(root->right);
}

// 后序遍历
void postOrder(struct node* root) {
    // 1. 若 root 为 NULL，则返回
    if (root == NULL) {
        return;
    }

    // 2. 处理左子节点
    postOrder(root->left);

    // 3. 处理右子节点
    postOrder(root->right);

    // 4. 处理根节点
    printf("%d ", root->data);
}
int main(void) {
    // 创建二叉树
    struct node* root = create();

    // 前序遍历
    // preOrder(root);

    // 中序遍历
    // inOrder(root);

    // 后序遍历
    postOrder(root);

    return 0;
}
