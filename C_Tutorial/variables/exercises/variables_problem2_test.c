// 引入标准库头文件
#include <stdio.h>
#include <math.h>  // 用于fabs函数进行浮点数比较

// --- 函数声明 ---
// 声明用户需要实现的函数
double calculate_mixed_sum();
// 声明标准答案函数，用于获取"预期"结果
double calculate_mixed_sum_answer();

// 定义一个辅助函数，用于比较两个双精度浮点数是否相等
// 由于浮点数精度问题，不能直接用==比较，需要使用误差范围
int double_equals(double a, double b) {
    // 如果两个双精度浮点数的差的绝对值小于一个很小的值，则认为相等
    return fabs(a - b) < 0.0001;
}

// 定义一个辅助函数，用于运行单个测试用例
void run_test(int test_num, double expected_result) {
    // 调用你编写的函数来获取实际的计算结果
    double actual_result = calculate_mixed_sum();
    
    // 比较实际结果和预期结果
    if (double_equals(actual_result, expected_result)) {
        // 如果结果相同，打印通过信息
        printf("✅ 测试用例 %d 通过\n", test_num);
        printf("   预期结果: %.2f, 实际结果: %.2f\n", expected_result, actual_result);
    } else {
        // 如果结果不同，打印失败信息，并显示相关数据
        printf("❌ 测试用例 %d 失败\n", test_num);
        printf("   预期结果: %.2f, 实际结果: %.2f\n", expected_result, actual_result);
    }
}

// 测试主程序
int main() {
    // 打印测试标题
    printf("--- 开始测试：练习2 (不同数据类型的变量使用) ---\n");
    printf("测试目标：验证混合数据类型的运算\n");
    printf("计算：'A'(65) + 20 + 5.5f + 2.75 = 93.25\n\n");
    
    // 获取标准答案的结果
    double expected = calculate_mixed_sum_answer();
    
    // 运行测试用例
    run_test(1, expected);
    
    // 额外的验证信息
    printf("\n--- 详细验证 ---\n");
    printf("期望的计算过程：\n");
    printf("1. 字符变量：char char_var = 'A';     // ASCII值：65\n");
    printf("2. 整数变量：int int_var = 20;\n");
    printf("3. 单精度浮点：float float_var = 5.5f;\n");
    printf("4. 双精度浮点：double double_var = 2.75;\n");
    printf("5. 计算总和：65 + 20 + 5.5 + 2.75 = %.2f\n", expected);
    
    // 类型转换说明
    printf("\n--- 类型转换说明 ---\n");
    printf("在混合类型运算中，类型提升顺序：\n");
    printf("char -> int -> float -> double\n");
    printf("最终结果类型为最高精度的类型：double\n");
    
    // 打印测试结束信息和如何运行的指令
    printf("\n--- 测试完成 ---\n");
    printf("编译和运行: gcc variables_problem2_solution.c variables_problem2_answer.c variables_problem2_test.c -o test2 && ./test2\n");

    // 程序正常退出
    return 0;
}
