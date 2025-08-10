// 引入标准库头文件
#include <stdio.h>
#include <math.h>  // 用于fabs函数进行浮点数比较

// --- 函数声明 ---
// 声明用户需要实现的函数
double calculate_circle_area_and_perimeter(double radius, double* perimeter);
// 声明标准答案函数，用于获取"预期"结果
double calculate_circle_area_and_perimeter_answer(double radius, double* perimeter);

// 定义一个辅助函数，用于比较两个双精度浮点数是否相等
int double_equals(double a, double b) {
    return fabs(a - b) < 0.0001;
}

// 定义一个辅助函数，用于运行单个测试用例
void run_test(int test_num, double test_radius) {
    printf("=== 测试用例 %d ===\n", test_num);
    printf("测试半径: %.2f\n\n", test_radius);
    
    // 准备变量存储结果
    double user_perimeter = 0.0;
    double expected_perimeter = 0.0;
    
    // 调用用户函数和标准答案函数
    printf("--- 用户函数执行 ---\n");
    double user_area = calculate_circle_area_and_perimeter(test_radius, &user_perimeter);
    
    printf("\n--- 标准答案函数执行 ---\n");
    double expected_area = calculate_circle_area_and_perimeter_answer(test_radius, &expected_perimeter);
    
    // 比较结果
    printf("\n--- 结果比较 ---\n");
    printf("面积比较：\n");
    printf("  用户结果: %.5f\n", user_area);
    printf("  标准答案: %.5f\n", expected_area);
    
    printf("周长比较：\n");
    printf("  用户结果: %.5f\n", user_perimeter);
    printf("  标准答案: %.5f\n", expected_perimeter);
    
    // 验证结果
    int area_correct = double_equals(user_area, expected_area);
    int perimeter_correct = double_equals(user_perimeter, expected_perimeter);
    
    if (area_correct && perimeter_correct) {
        printf("✅ 测试用例 %d 通过\n", test_num);
    } else {
        printf("❌ 测试用例 %d 失败\n", test_num);
        if (!area_correct) {
            printf("   面积计算错误\n");
        }
        if (!perimeter_correct) {
            printf("   周长计算错误\n");
        }
    }
    printf("\n");
}

// 测试主程序
int main() {
    // 打印测试标题
    printf("--- 开始测试：练习5 (变量的综合应用) ---\n");
    printf("测试目标：验证圆的面积和周长计算\n");
    printf("涉及概念：常量、指针参数、数学运算、类型精度\n\n");
    
    // 运行多个测试用例
    run_test(1, 5.0);    // 半径为5的圆
    run_test(2, 10.0);   // 半径为10的圆
    run_test(3, 1.0);    // 半径为1的圆（单位圆）
    run_test(4, 0.0);    // 边界情况：半径为0
    
    // 详细说明涉及的概念
    printf("--- 涉及的重要概念 ---\n\n");
    
    printf("1. 常量的定义和使用：\n");
    printf("   const double PI = 3.14159;\n");
    printf("   • const关键字确保值不被意外修改\n");
    printf("   • 常量名通常使用大写字母\n");
    printf("   • 提高代码可读性和维护性\n\n");
    
    printf("2. 指针参数的使用：\n");
    printf("   double* perimeter\n");
    printf("   • 通过指针返回多个值\n");
    printf("   • 使用*perimeter给指针指向的变量赋值\n");
    printf("   • 需要检查指针是否为NULL\n\n");
    
    printf("3. 数学运算的精度：\n");
    printf("   • double类型提供高精度计算\n");
    printf("   • 浮点数比较需要使用误差范围\n");
    printf("   • 避免直接使用==比较浮点数\n\n");
    
    printf("4. 函数设计原则：\n");
    printf("   • 参数验证（检查负半径）\n");
    printf("   • 错误处理（返回合理的默认值）\n");
    printf("   • 单一职责（计算面积，通过参数返回周长）\n\n");
    
    // 实际应用示例
    printf("--- 实际应用示例 ---\n");
    printf("这种设计模式在实际编程中很常见：\n");
    printf("• 函数返回主要结果（面积）\n");
    printf("• 通过指针参数返回次要结果（周长）\n");
    printf("• 使用常量提高代码可维护性\n");
    printf("• 进行输入验证确保程序健壮性\n\n");
    
    // 打印测试结束信息和如何运行的指令
    printf("--- 测试完成 ---\n");
    printf("编译和运行: gcc variables_problem5_solution.c variables_problem5_answer.c variables_problem5_test.c -o test5 && ./test5\n");

    // 程序正常退出
    return 0;
}
