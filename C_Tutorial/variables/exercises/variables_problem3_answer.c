// 引入标准库头文件
#include <stdio.h>

// 练习3：变量的作用域和生命周期
// 需求：演示局部变量、全局变量和静态变量的作用域差异
// 要求：实现一个计数器函数，每次调用都返回当前的调用次数

// 全局变量：在函数外定义，整个程序都能访问
// 全局变量存储在数据段，程序开始时初始化，程序结束时销毁
extern int global_count;  // 声明使用外部定义的全局变量

// 标准答案函数，用于测试时提供预期结果
int scope_counter_answer() {
    // 静态局部变量：只在第一次调用时初始化，之后保持值不变
    // static变量存储在数据段，生命周期是整个程序运行期
    // 但作用域仅限于当前函数内部
    static int static_count = 0;
    
    // 普通局部变量：每次函数调用都重新初始化
    // 局部变量存储在栈上，函数结束时自动销毁
    // 作用域仅限于当前函数内部
    int local_count = 0;
    
    // 对三个不同类型的变量进行自增操作
    global_count++;    // 全局变量自增
    static_count++;    // 静态局部变量自增
    local_count++;     // 普通局部变量自增（每次都从0开始）
    
    // 打印三个变量的当前值，用于观察它们的行为差异
    printf("答案函数 - 全局变量: %d, 静态变量: %d, 局部变量: %d\n", 
           global_count, static_count, local_count);
    
    // 返回静态变量的值
    // 静态变量会在函数调用之间保持其值，因此可以用作计数器
    return static_count;
}

// 将这个函数定义为"弱"函数，用于回退机制
// 当用户solution文件中没有实现scope_counter时，使用这个函数
int __attribute__((weak)) scope_counter() {
    return scope_counter_answer();
}
