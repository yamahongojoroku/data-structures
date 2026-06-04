#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/**
 * 堆排序 (Heap Sort)
 * 
 * 算法步骤:
 * 1. 将数组构建成最大堆
 * 2. 将堆顶(最大值)与末尾交换
 * 3. 堆大小减1，重新调整堆
 * 4. 重复步骤2-3直到堆大小为1
 * 
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(1) - 原地排序
 * 稳定性: 不稳定
 */

/**
 * 交换两个元素
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 向下调整 (维护堆性质)
 */
void sift_down(int* arr, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        sift_down(arr, largest, n);
    }
}

/**
 * 构建最大堆
 */
void build_max_heap(int* arr, int n) {
    // 从最后一个非叶子节点开始向下调整
    for (int i = (n - 1) / 2; i >= 0; i--) {
        sift_down(arr, i, n);
    }
}

/**
 * 堆排序
 */
void heap_sort(int* arr, int n) {
    printf("--- 堆排序过程 ---\n");
    printf("原始数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // 构建最大堆
    printf("构建最大堆...\n");
    build_max_heap(arr, n);
    printf("堆: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // 逐个取出最大值
    for (int i = n - 1; i > 0; i--) {
        // 将堆顶与末尾交换
        swap(&arr[0], &arr[i]);
        printf("第 %d 步: 交换堆顶 %d 和末尾, 当前数组: ", n - i, arr[i]);
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[j]);
        }
        printf("| %d (已排序)\n", arr[i]);
        
        // 重新调整堆
        sift_down(arr, 0, i);
    }
    
    printf("\n");
}

/**
 * 打印数组
 */
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 验证数组是否有序
 */
int is_sorted(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

/**
 * 主函数 - 测试示例
 */
int main() {
    printf("========== 堆排序 演示 ==========\n\n");
    
    // 测试1: 随机数组
    printf("--- 测试1: 随机数组 ---\n");
    int arr1[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    heap_sort(arr1, n1);
    
    printf("排序后: ");
    print_array(arr1, n1);
    printf("验证: %s\n\n", is_sorted(arr1, n1) ? "✓ 正确" : "✗ 错误");
    
    // 测试2: 已排序的数组
    printf("--- 测试2: 已排序的数组 ---\n");
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    heap_sort(arr2, n2);
    
    printf("排序后: ");
    print_array(arr2, n2);
    printf("验证: %s\n\n", is_sorted(arr2, n2) ? "✓ 正确" : "✗ 错误");
    
    // 测试3: 逆序数组
    printf("--- 测试3: 逆序数组 ---\n");
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    heap_sort(arr3, n3);
    
    printf("排序后: ");
    print_array(arr3, n3);
    printf("验证: %s\n\n", is_sorted(arr3, n3) ? "✓ 正确" : "✗ 错误");
    
    // 测试4: 小数组
    printf("--- 测试4: 小数组 ---\n");
    int arr4[] = {5, 2, 8, 1, 9};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    
    heap_sort(arr4, n4);
    
    printf("排序后: ");
    print_array(arr4, n4);
    printf("验证: %s\n\n", is_sorted(arr4, n4) ? "✓ 正确" : "✗ 错误");
    
    // 性能对比
    printf("--- 性能分析 ---\n");
    printf("时间复杂度: O(n log n)\n");
    printf("空间复杂度: O(1)\n");
    printf("稳定性: 不稳定\n");
    printf("适用场景: 数据量大且内存有限\n");
    
    return 0;
}
