// 引入标准库头文件
#include <stdio.h>

// 全局变量定义（在这里实际定义，其他文件使用extern声明）
int number = 100;

// --- 函数声明 ---
// 声明用户需要实现的函数
int variable_shadowing_demo();
// 声明标准答案函数，用于获取"预期"结果
int variable_shadowing_demo_answer();

// 定义一个辅助函数，用于运行单个测试用例
void run_test(int test_num, int expected_result) {
    printf("=== 测试用例 %d ===\n", test_num);
    printf("全局变量 number 的初始值: %d\n", number);
    printf("\n调用函数，观察变量遮蔽现象：\n");
    
    // 调用你编写的函数来获取实际的计算结果
    int actual_result = variable_shadowing_demo();
    
    printf("\n函数返回值: %d\n", actual_result);
    printf("全局变量 number 的最终值: %d (应该没有改变)\n", number);
    
    // 比较实际结果和预期结果
    if (actual_result == expected_result) {
        // 如果结果相同，打印通过信息
        printf("✅ 测试用例 %d 通过\n", test_num);
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
    printf("--- 开始测试：练习4 (全局变量和局部变量) ---\n");
    printf("测试目标：验证变量遮蔽（Variable Shadowing）现象\n\n");
    
    // 运行测试用例
    run_test(1, 50);  // 期望返回函数内局部变量的值50
    
    // 对比显示标准答案的行为
    printf("=== 对比：标准答案的输出 ===\n");
    printf("全局变量 number 的值: %d\n", number);
    printf("\n调用标准答案函数：\n");
    int answer_result = variable_shadowing_demo_answer();
    printf("\n标准答案返回值: %d\n", answer_result);
    printf("全局变量 number 的值: %d (仍然没有改变)\n\n", number);
    
    // 详细说明变量遮蔽的概念
    printf("--- 变量遮蔽（Variable Shadowing）说明 ---\n");
    printf("变量遮蔽是指内层作用域中的变量会隐藏外层作用域中的同名变量。\n\n");
    
    printf("作用域层次（从外到内）：\n");
    printf("1. 全局作用域：     int number = 100;  (整个程序可见)\n");
    printf("2. 函数作用域：     int number = 50;   (函数内可见，遮蔽全局变量)\n");
    printf("3. 代码块作用域：   int number = 25;   (代码块内可见，遮蔽函数变量)\n\n");
    
    printf("遮蔽规则：\n");
    printf("• 内层变量遮蔽外层同名变量\n");
    printf("• 内层作用域无法直接访问被遮蔽的外层变量\n");
    printf("• 内层作用域结束后，外层变量重新可见\n");
    printf("• 全局变量在整个过程中都存在，只是被暂时遮蔽\n\n");
    
    printf("实际应用：\n");
    printf("• 避免意外修改全局变量\n");
    printf("• 在小范围内使用更合适的变量名\n");
    printf("• 提高代码的局部性和可读性\n\n");
    
    // 打印测试结束信息和如何运行的指令
    printf("--- 测试完成 ---\n");
    printf("编译和运行: gcc variables_problem4_solution.c variables_problem4_answer.c variables_problem4_test.c -o test4 && ./test4\n");

    // 程序正常退出
    return 0;
}
