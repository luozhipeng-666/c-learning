// 引入标准库头文件
#include <stdio.h>

// 练习4：全局变量和局部变量
// 需求：理解全局变量和局部变量的优先级，以及变量遮蔽的概念
// 要求：实现一个函数，演示同名变量在不同作用域中的行为

// 声明外部定义的全局变量
extern int number;

// 标准答案函数，用于测试时提供预期结果
int variable_shadowing_demo_answer() {
    // 定义一个局部变量，与全局变量同名
    // 这个局部变量会"遮蔽"（shadow）全局变量
    // 在当前函数作用域内，number指的是这个局部变量，而不是全局变量
    int number = 50;
    
    // 打印当前函数内number的值
    // 由于局部变量遮蔽了全局变量，这里输出的是局部变量的值50
    printf("答案函数 - 函数内局部变量 number = %d\n", number);
    
    // 创建一个新的代码块作用域
    {
        // 在代码块内再次定义同名变量
        // 这个变量会遮蔽外层函数作用域的局部变量
        int number = 25;
        
        // 打印代码块内number的值
        // 现在number指的是代码块内的变量，值为25
        printf("答案函数 - 代码块内局部变量 number = %d\n", number);
        
        // 在代码块内，我们无法直接访问外层的number变量
        // 更无法访问全局的number变量
    }
    // 代码块结束，代码块内的number变量被销毁
    
    // 代码块结束后，number又重新指向函数作用域的局部变量
    printf("答案函数 - 代码块结束后，函数内 number = %d\n", number);
    
    // 返回函数作用域内局部变量的值
    return number;
}

// 将这个函数定义为"弱"函数，用于回退机制
// 当用户solution文件中没有实现variable_shadowing_demo时，使用这个函数
int __attribute__((weak)) variable_shadowing_demo() {
    return variable_shadowing_demo_answer();
}
