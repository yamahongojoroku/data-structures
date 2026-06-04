# 数据结构 - C语言完整实现

这是一个完整的**大一下学期数据结构**课程的C语言实现库，包含所有核心数据结构及其应用。

## 📚 内容目录

### 1. 线性表 (Linear List)
- [数组实现](./1_linear_list/array_list.c)
- [链表实现](./1_linear_list/linked_list.c)

### 2. 栈 (Stack)
- [数组栈](./2_stack/stack_array.c)
- [链表栈](./2_stack/stack_linked.c)
- [应用：括号匹配](./2_stack/bracket_matching.c)
- [应用：表达式求值](./2_stack/expression_evaluation.c)

### 3. 队列 (Queue)
- [数组队列](./3_queue/queue_array.c)
- [链表队列](./3_queue/queue_linked.c)
- [循环队列](./3_queue/circular_queue.c)

### 4. 树 (Tree)
- [二叉树基础](./4_tree/binary_tree.c)
- [树的遍历 (前序/中序/后序/层序)](./4_tree/tree_traversal.c)
- [二叉搜索树](./4_tree/binary_search_tree.c)
- [AVL平衡树](./4_tree/avl_tree.c)

### 5. 图 (Graph)
- [邻接表表示](./5_graph/graph_adjacency_list.c)
- [邻接矩阵表示](./5_graph/graph_adjacency_matrix.c)
- [BFS遍历](./5_graph/bfs.c)
- [DFS遍历](./5_graph/dfs.c)
- [应用：拓扑排序](./5_graph/topological_sort.c)

### 6. 哈希表 (Hash Table)
- [链地址法](./6_hash_table/hash_table_chain.c)
- [开放地址法](./6_hash_table/hash_table_open_addressing.c)

### 7. 堆 (Heap)
- [最小堆](./7_heap/min_heap.c)
- [最大堆](./7_heap/max_heap.c)
- [应用：堆排序](./7_heap/heap_sort.c)
- [应用：优先队列](./7_heap/priority_queue.c)

## 🚀 快速开始

### 编译单个文件
```bash
gcc -o output_name source_file.c
./output_name
```

### 编译整个项目
```bash
make  # 需要Makefile
```

## 📖 学习建议

1. **循序渐进**: 按目录顺序学习，从线性表开始
2. **理解原理**: 阅读注释，理解每个操作的实现
3. **动手实践**: 尝试修改代码，添加新功能
4. **对比学习**: 比较数组与链表的实现差异

## 💡 核心概念

- **线性表**: 元素按线性顺序排列的集合
- **栈**: LIFO (Last In First Out) 后进先出
- **队列**: FIFO (First In First Out) 先进先出
- **树**: 分层结构，具有唯一的根节点
- **图**: 由顶点和边组成的非线性数据结构
- **哈希表**: 通过哈希函数实现快速查找
- **堆**: 满足堆性质的完全二叉树

## 📝 代码规范

- 所有代码包含详细中文注释
- 函数设计符合模块化原则
- 包含完整的错误处理
- 提供使用示例

## 🔗 相关资源

- 标准C库文档: https://en.cppreference.com/w/c
- 数据结构教学: 推荐《数据结构与算法分析》

---

**作者**: Data Structures Learning  
**最后更新**: 2026年6月  
**许可证**: MIT
