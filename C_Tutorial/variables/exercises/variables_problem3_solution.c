// 引入标准库头文件
#include <stdio.h>

// 练习3：变量的作用域和生命周期
// 需求：演示局部变量、全局变量和静态变量的作用域差异
// 要求：实现一个计数器函数，每次调用都返回当前的调用次数

// 全局变量：在函数外定义，整个程序都能访问
// 使用extern声明，实际定义在test文件中
extern int global_count;

// 特别注意：请先移除下面代码注释，才能进行：
// 默认情况下注释掉相关函数

// int scope_counter() {
//     // TODO: 定义一个静态局部变量 static_count，初始化为0
//     // TODO: 定义一个普通局部变量 local_count，初始化为0
//     
//     // TODO: 将三个变量都加1：global_count++, static_count++, local_count++
//     
//     // TODO: 返回静态变量的值 (这个值在函数调用之间会保持)
//     // 注意：每次函数调用，local_count都会重新初始化为0
//     //       static_count会保持之前的值
//     //       global_count在整个程序中都保持
// }
