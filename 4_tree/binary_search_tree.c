#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/**
 * 二叉搜索树 (Binary Search Tree, BST)
 * 
 * 性质:
 * - 左子树的所有节点 < 根节点
 * - 右子树的所有节点 > 根节点
 * - 递归应用此性质到左右子树
 * - 中序遍历结果是升序排列
 * 
 * 时间复杂度:
 * - 查找: O(log n) 最好情况, O(n) 最坏情况 (退化成链表)
 * - 插入: O(log n) 最好情况, O(n) 最坏情况
 * - 删除: O(log n) 最好情况, O(n) 最坏情况
 */

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

/**
 * 创建新节点
 */
TreeNode* create_node(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * 插入元素 (递归实现)
 * 时间复杂度: O(log n) ~ O(n)
 */
TreeNode* insert(TreeNode* root, int value) {
    // 如果树为空，创建新节点作为根
    if (root == NULL) {
        return create_node(value);
    }
    
    // 如果值小于根节点，插入到左子树
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // 如果值大于根节点，插入到右子树
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // 如果值等于根节点，不插入重复值
    else {
        printf("警告: 元素 %d 已存在，不插入\n", value);
    }
    
    return root;
}

/**
 * 查找元素
 * 时间复杂度: O(log n) ~ O(n)
 */
TreeNode* search(TreeNode* root, int value) {
    // 如果树为空或找到了元素
    if (root == NULL) {
        return NULL;
    }
    
    if (value == root->data) {
        return root;
    }
    
    // 如果值小于根节点，在左子树查找
    if (value < root->data) {
        return search(root->left, value);
    }
    
    // 如果值大于根节点，在右子树查找
    return search(root->right, value);
}

/**
 * 找最小值 (最左下角的节点)
 */
TreeNode* find_min(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

/**
 * 找最大值 (最右下角的节点)
 */
TreeNode* find_max(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    while (root->right != NULL) {
        root = root->right;
    }
    
    return root;
}

/**
 * 删除元素
 * 三种情况:
 * 1. 删除的节点是叶子节点：直接删���
 * 2. 删除的节点只有一个子节点：用子节点替代
 * 3. 删除的节点有两个子节点：用右子树最小值替代
 */
TreeNode* delete(TreeNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    // 在左子树中查找
    if (value < root->data) {
        root->left = delete(root->left, value);
    }
    // 在右子树中查找
    else if (value > root->data) {
        root->right = delete(root->right, value);
    }
    // 找到了要删除的节点
    else {
        // 情况1: 节点是叶子节点
        if (root->left == NULL && root->right == NULL) {
            printf("删除叶子节点: %d\n", value);
            free(root);
            return NULL;
        }
        
        // 情况2: 节点只有右子节点
        if (root->left == NULL) {
            printf("删除只有右子节点的节点: %d\n", value);
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        
        // 情况2: 节点只有左子节点
        if (root->right == NULL) {
            printf("删除只有左子节点的节点: %d\n", value);
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // 情况3: 节点有两个子节点
        // 用右子树的最小值替代该节点
        TreeNode* min_node = find_min(root->right);
        printf("删除有两个子节点的节点: %d，用右子树最小值 %d 替代\n", value, min_node->data);
        root->data = min_node->data;
        root->right = delete(root->right, min_node->data);
    }
    
    return root;
}

/**
 * 中序遍历 (结果是升序)
 */
void inorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

/**
 * 前序遍历
 */
void preorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

/**
 * 获取树的高度
 */
int get_height(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    
    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * 释放树
 */
void free_tree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/**
 * 主函数 - 测试示例
 */
int main() {
    printf("========== 二叉搜索树 演示 ==========\n\n");
    
    TreeNode* root = NULL;
    
    // 插入元素
    printf("--- 插入元素 ---\n");
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 65};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        printf("插入 %d\n", values[i]);
        root = insert(root, values[i]);
    }
    printf("\n");
    
    // 中序遍历 (升序)
    printf("--- 中序遍历 (应该是升序) ---\n");
    printf("结果: ");
    inorder_traversal(root);
    printf("\n\n");
    
    // 前序遍历
    printf("--- 前序遍历 ---\n");
    printf("结果: ");
    preorder_traversal(root);
    printf("\n\n");
    
    // 查找元素
    printf("--- 查找元素 ---\n");
    TreeNode* found = search(root, 35);
    printf("查找 35: %s\n", found != NULL ? "找到" : "未找到");
    found = search(root, 100);
    printf("查找 100: %s\n\n", found != NULL ? "找到" : "未找到");
    
    // 找最小和最大值
    printf("--- 最小值和最大值 ---\n");
    printf("最小值: %d\n", find_min(root)->data);
    printf("最大值: %d\n", find_max(root)->data);
    printf("树的高度: %d\n\n", get_height(root));
    
    // 删除元素 - 情况1: 叶子节点
    printf("--- 删除叶子节点 ---\n");
    root = delete(root, 10);
    printf("中序遍历: ");
    inorder_traversal(root);
    printf("\n\n");
    
    // 删除元素 - 情况2: 只有一个子节点
    printf("--- 删除只有一个子节点的节点 ---\n");
    root = delete(root, 20);
    printf("中序遍历: ");
    inorder_traversal(root);
    printf("\n\n");
    
    // 删除元素 - 情况3: 有两个子节点
    printf("--- 删除有两个子节点的节点 ---\n");
    root = delete(root, 30);
    printf("中序遍历: ");
    inorder_traversal(root);
    printf("\n\n");
    
    // 删除根节点
    printf("--- 删除根节点 ---\n");
    root = delete(root, 50);
    printf("中序遍历: ");
    inorder_traversal(root);
    printf("\n\n");
    
    // 释放内存
    free_tree(root);
    printf("树已释放\n");
    
    return 0;
}
