// 引入标准库头文件
#include <stdio.h>

// 全局变量定义（在这里实际定义，其他文件使用extern声明）
int global_count = 0;

// --- 函数声明 ---
// 声明用户需要实现的函数
int scope_counter();
// 声明标准答案函数，用于获取"预期"结果
int scope_counter_answer();

// 定义一个辅助函数，用于运行单个测试用例
void run_test(int test_num, int call_number, int expected_result) {
    // 调用你编写的函数来获取实际的计算结果
    printf("第 %d 次调用函数：\n", call_number);
    int actual_result = scope_counter();
    
    // 比较实际结果和预期结果
    if (actual_result == expected_result) {
        // 如果结果相同，打印通过信息
        printf("✅ 测试用例 %d 通过\n", test_num);
        printf("   预期返回值: %d, 实际返回值: %d\n", expected_result, actual_result);
    } else {
        // 如果结果不同，打印失败信息，并显示相关数据
        printf("❌ 测试用例 %d 失败\n", test_num);
        printf("   预期返回值: %d, 实际返回值: %d\n", expected_result, actual_result);
    }
    printf("\n");
}

// 测试主程序
int main() {
    // 打印测试标题
    printf("--- 开始测试：练习3 (变量的作用域和生命周期) ---\n");
    printf("测试目标：验证静态变量在函数调用间保持值\n");
    printf("全局变量初始值: %d\n\n", global_count);
    
    // 分别调用函数多次，观察静态变量的行为
    printf("=== 测试用户实现的函数 ===\n");
    run_test(1, 1, 1);  // 第1次调用，期望返回1
    run_test(2, 2, 2);  // 第2次调用，期望返回2  
    run_test(3, 3, 3);  // 第3次调用，期望返回3
    
    // 显示全局变量的最终值
    printf("测试完成后全局变量的值: %d\n\n", global_count);
    
    // 重置全局变量，测试答案函数
    global_count = 0;
    printf("=== 对比：标准答案函数的行为 ===\n");
    printf("重置全局变量为: %d\n", global_count);
    
    for(int i = 1; i <= 3; i++) {
        printf("标准答案第 %d 次调用：\n", i);
        int result = scope_counter_answer();
        printf("返回值: %d\n\n", result);
    }
    
    // 详细说明
    printf("--- 变量类型说明 ---\n");
    printf("1. 全局变量 (global_count):\n");
    printf("   - 存储位置：数据段\n");
    printf("   - 作用域：整个程序\n");
    printf("   - 生命周期：程序运行期间\n");
    printf("   - 特点：所有函数都能访问和修改\n\n");
    
    printf("2. 静态局部变量 (static_count):\n");
    printf("   - 存储位置：数据段\n");
    printf("   - 作用域：定义它的函数内\n");
    printf("   - 生命周期：程序运行期间\n");
    printf("   - 特点：函数调用间保持值，只初始化一次\n\n");
    
    printf("3. 普通局部变量 (local_count):\n");
    printf("   - 存储位置：栈\n");
    printf("   - 作用域：定义它的函数内\n");
    printf("   - 生命周期：函数调用期间\n");
    printf("   - 特点：每次函数调用都重新初始化\n\n");
    
    // 打印测试结束信息和如何运行的指令
    printf("--- 测试完成 ---\n");
    printf("编译和运行: gcc variables_problem3_solution.c variables_problem3_answer.c variables_problem3_test.c -o test3 && ./test3\n");

    // 程序正常退出
    return 0;
}
