#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/**
 * 最大堆 (Max Heap)
 * 
 * 堆的性质:
 * - 完全二叉树
 * - 堆序性: 每个节点的值都大于等于其子节点的值
 * 
 * 与最小堆相反，用于优先队列的实现
 * 数组表示与最小堆相同
 */

typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

/**
 * 初始化最大堆
 */
MaxHeap* init_heap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0;
    return heap;
}

/**
 * 获取父节点索引
 */
int get_parent(int i) {
    return (i - 1) / 2;
}

/**
 * 获取左子节点索引
 */
int get_left_child(int i) {
    return 2 * i + 1;
}

/**
 * 获取右子节点索引
 */
int get_right_child(int i) {
    return 2 * i + 2;
}

/**
 * 交换两个元素
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 向上调整 (最大堆版本)
 */
void sift_up(MaxHeap* heap, int i) {
    while (i > 0 && heap->data[get_parent(i)] < heap->data[i]) {
        swap(&heap->data[i], &heap->data[get_parent(i)]);
        i = get_parent(i);
    }
}

/**
 * 向下调整 (最大堆版本)
 */
void sift_down(MaxHeap* heap, int i) {
    int largest = i;
    int left = get_left_child(i);
    int right = get_right_child(i);
    
    // 找到三个节点中最大的
    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }
    
    // 如果最大的不是当前节点，交换并继续调整
    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        sift_down(heap, largest);
    }
}

/**
 * 插入元素
 */
int insert(MaxHeap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("错误: 堆已满!\n");
        return 0;
    }
    
    heap->data[heap->size] = value;
    heap->size++;
    
    sift_up(heap, heap->size - 1);
    
    printf("插入: %d\n", value);
    return 1;
}

/**
 * 删除最大元素
 */
int delete_max(MaxHeap* heap, int* value) {
    if (heap->size == 0) {
        printf("错误: 堆为空!\n");
        return 0;
    }
    
    *value = heap->data[0];
    
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        sift_down(heap, 0);
    }
    
    printf("删除最大值: %d\n", *value);
    return 1;
}

/**
 * 获取最大值
 */
int get_max(MaxHeap* heap, int* value) {
    if (heap->size == 0) {
        printf("错误: 堆为空!\n");
        return 0;
    }
    
    *value = heap->data[0];
    printf("最大值: %d\n", *value);
    return 1;
}

/**
 * 获取堆的大小
 */
int get_size(MaxHeap* heap) {
    return heap->size;
}

/**
 * 判断堆是否为空
 */
int is_empty(MaxHeap* heap) {
    return heap->size == 0;
}

/**
 * 遍历堆
 */
void display(MaxHeap* heap) {
    if (is_empty(heap)) {
        printf("堆为空\n");
        return;
    }
    
    printf("堆的内容: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

/**
 * 清空堆
 */
void clear(MaxHeap* heap) {
    heap->size = 0;
    printf("堆已清空\n");
}

/**
 * 释放堆
 */
void free_heap(MaxHeap* heap) {
    free(heap);
    printf("堆内存已释放\n");
}

/**
 * 主函数 - 测试示例
 */
int main() {
    printf("========== 最大堆 演示 ==========\n\n");
    
    MaxHeap* heap = init_heap();
    int value;
    
    // 插入元素
    printf("--- 插入操作 ---\n");
    insert(heap, 50);
    insert(heap, 30);
    insert(heap, 70);
    insert(heap, 20);
    insert(heap, 40);
    insert(heap, 60);
    insert(heap, 80);
    insert(heap, 10);
    
    printf("堆大小: %d\n\n", get_size(heap));
    display(heap);
    printf("\n");
    
    // 获取最大值
    printf("--- 获取最大值 ---\n");
    get_max(heap, &value);
    printf("\n");
    
    // 删除最大值
    printf("--- 删除最大值 ---\n");
    delete_max(heap, &value);
    printf("删除后: ");
    display(heap);
    printf("\n");
    
    delete_max(heap, &value);
    printf("删除后: ");
    display(heap);
    printf("\n");
    
    // 获取新的最大值
    printf("--- 现在的最大值 ---\n");
    get_max(heap, &value);
    printf("\n");
    
    // 继续删除
    printf("--- 继续删除所有元素 ---\n");
    while (!is_empty(heap)) {
        delete_max(heap, &value);
    }
    display(heap);
    printf("\n");
    
    // 重新插入
    printf("--- 重新插入新数据 ---\n");
    int test_values[] = {15, 25, 5, 35, 45};
    for (int i = 0; i < 5; i++) {
        insert(heap, test_values[i]);
    }
    display(heap);
    printf("\n");
    
    clear(heap);
    display(heap);
    printf("\n");
    
    free_heap(heap);
    
    return 0;
}
