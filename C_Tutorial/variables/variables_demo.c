// 引入标准输入输出库，这样我们才能使用 printf 函数
#include <stdio.h>

// 全局变量示例：在所有函数外部定义，整个程序都可以访问
// 全局变量会自动初始化为0
int global_counter = 100;         // 全局整型变量，初始化为100
static int file_scope_var = 200;  // 文件作用域的静态变量，只在当前文件可见

// 函数声明：演示不同作用域中变量的使用
void demonstrate_scope();
void demonstrate_static();

// main 函数是每个 C 程序的入口点
int main() {
    // 打印程序开始的标题
    printf("=== C语言变量完整演示程序 ===\n\n");

    // 1. 基本变量类型演示
    printf("--- 1. 基本数据类型变量 ---\n");
    
    // 整型变量：用于存储整数
    int age = 25;                    // 声明并初始化一个整型变量
    printf("整型变量 age = %d\n", age);
    
    // 浮点型变量：用于存储小数
    float height = 175.5f;           // 声明并初始化一个单精度浮点型变量（注意f后缀）
    printf("单精度浮点型 height = %.1f\n", height);
    
    // 双精度浮点型变量：精度更高的小数
    double weight = 68.75;           // 声明并初始化一个双精度浮点型变量
    printf("双精度浮点型 weight = %.2f\n", weight);
    
    // 字符型变量：用于存储单个字符
    char grade = 'A';                // 声明并初始化一个字符型变量
    printf("字符型变量 grade = %c\n", grade);
    
    // 字符串（字符数组）：用于存储文本
    char name[] = "张三";            // 声明并初始化一个字符数组（字符串）
    printf("字符串 name = %s\n", name);

    printf("\n");

    // 2. 变量的声明和赋值分离演示
    printf("--- 2. 变量声明和赋值 ---\n");
    
    // 先声明变量，不初始化（包含垃圾值，不安全）
    int uninitialized_var;
    printf("未初始化变量的值（垃圾值）: %d\n", uninitialized_var);
    
    // 后续为变量赋值
    uninitialized_var = 42;
    printf("赋值后的变量值: %d\n", uninitialized_var);

    printf("\n");

    // 3. 不同存储类别的变量演示
    printf("--- 3. 存储类别演示 ---\n");
    
    // auto变量（默认的局部变量）
    auto int auto_var = 10;          // auto关键字通常省略，因为这是默认的
    printf("auto变量: %d\n", auto_var);
    
    // register变量（建议编译器存储在寄存器中，提高访问速度）
    register int fast_counter = 0;   // 用于频繁访问的变量
    for(fast_counter = 0; fast_counter < 3; fast_counter++) {
        printf("register变量循环第 %d 次\n", fast_counter + 1);
    }

    printf("\n");

    // 4. 变量的修改演示
    printf("--- 4. 变量值的修改 ---\n");
    
    int number = 10;
    printf("初始值: number = %d\n", number);
    
    // 直接赋值
    number = 20;
    printf("直接赋值后: number = %d\n", number);
    
    // 自增运算
    number++;                        // 等价于 number = number + 1
    printf("自增后: number = %d\n", number);
    
    // 复合赋值
    number += 5;                     // 等价于 number = number + 5
    printf("复合赋值后: number = %d\n", number);

    printf("\n");

    // 5. 全局变量的使用
    printf("--- 5. 全局变量演示 ---\n");
    printf("全局变量 global_counter = %d\n", global_counter);
    
    // 修改全局变量
    global_counter += 50;
    printf("修改后的全局变量 global_counter = %d\n", global_counter);

    printf("\n");

    // 6. 变量作用域演示
    printf("--- 6. 变量作用域演示 ---\n");
    demonstrate_scope();

    printf("\n");

    // 7. 静态变量演示
    printf("--- 7. 静态变量演示 ---\n");
    printf("调用静态变量函数3次：\n");
    demonstrate_static();  // 第1次调用
    demonstrate_static();  // 第2次调用
    demonstrate_static();  // 第3次调用

    printf("\n");

    // 8. 常量变量演示
    printf("--- 8. 常量变量演示 ---\n");
    
    // const关键字定义常量变量：一旦初始化就不能修改
    const int MAX_STUDENTS = 30;
    printf("常量 MAX_STUDENTS = %d\n", MAX_STUDENTS);
    
    // 尝试修改常量会导致编译错误，所以下面这行被注释掉了
    // MAX_STUDENTS = 40;  // 编译错误！不能修改常量

    printf("\n");

    // 9. 变量类型转换演示
    printf("--- 9. 类型转换演示 ---\n");
    
    int int_val = 10;
    float float_val = 3.14f;
    
    // 隐式类型转换：编译器自动进行
    float result = int_val + float_val;  // int自动转换为float
    printf("整数 %d + 浮点数 %.2f = %.2f\n", int_val, float_val, result);
    
    // 显式类型转换：强制转换
    int truncated = (int)float_val;      // 强制将float转换为int，小数部分被截断
    printf("浮点数 %.2f 强制转换为整数 = %d\n", float_val, truncated);

    printf("\n");

    // 10. 多个变量同时声明
    printf("--- 10. 多变量声明演示 ---\n");
    
    // 同时声明多个同类型变量
    int x = 1, y = 2, z = 3;
    printf("同时声明的三个变量: x=%d, y=%d, z=%d\n", x, y, z);
    
    // 变量之间的运算
    int sum = x + y + z;
    printf("三个变量的和: %d + %d + %d = %d\n", x, y, z, sum);

    printf("\n");
    printf("=== 变量演示程序结束 ===\n");

    // main 函数返回 0，表示程序成功执行并正常退出
    return 0;
}

// 演示变量作用域的函数
void demonstrate_scope() {
    // 这是函数的局部变量，只在这个函数内可见
    int local_var = 999;
    printf("函数内局部变量 local_var = %d\n", local_var);
    
    // 可以访问全局变量
    printf("在函数内访问全局变量 global_counter = %d\n", global_counter);
    
    // 代码块作用域演示
    {
        // 这个变量只在这个代码块内可见
        int block_var = 555;
        printf("代码块内变量 block_var = %d\n", block_var);
        
        // 在代码块内重新定义同名变量（遮蔽外层变量）
        int local_var = 777;  // 这会遮蔽外层的local_var
        printf("代码块内的local_var（遮蔽外层）= %d\n", local_var);
    }
    // 代码块结束后，block_var不再可见，local_var恢复为外层的值
    
    printf("代码块外的local_var = %d\n", local_var);  // 值恢复为999
}

// 演示静态变量的函数
void demonstrate_static() {
    // 静态局部变量：只初始化一次，在函数调用之间保持值
    static int call_count = 0;       // 只在第一次调用时初始化
    
    // 普通局部变量：每次函数调用都重新初始化
    int regular_var = 0;
    
    // 两个变量都增加1
    call_count++;
    regular_var++;
    
    printf("函数调用次数(静态变量): %d, 普通变量: %d\n", call_count, regular_var);
}
