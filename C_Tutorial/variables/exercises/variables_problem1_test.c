// 引入标准库头文件
#include <stdio.h>
#include <math.h>  // 用于fabs函数进行浮点数比较

// --- 函数声明 ---
// 声明用户需要实现的函数
float calculate_sum();
// 声明标准答案函数，用于获取"预期"结果
float calculate_sum_answer();

// 定义一个辅助函数，用于比较两个浮点数是否相等
// 由于浮点数精度问题，不能直接用==比较，需要使用误差范围
int float_equals(float a, float b) {
    // 如果两个浮点数的差的绝对值小于一个很小的值(0.0001)，则认为相等
    return fabs(a - b) < 0.0001f;
}

// 定义一个辅助函数，用于运行单个测试用例
void run_test(int test_num, float expected_result) {
    // 调用你编写的函数来获取实际的计算结果
    float actual_result = calculate_sum();
    
    // 比较实际结果和预期结果
    if (float_equals(actual_result, expected_result)) {
        // 如果结果相同，打印通过信息
        printf("✅ 测试用例 %d 通过\n", test_num);
        printf("   预期结果: %.1f, 实际结果: %.1f\n", expected_result, actual_result);
    } else {
        // 如果结果不同，打印失败信息，并显示相关数据
        printf("❌ 测试用例 %d 失败\n", test_num);
        printf("   预期结果: %.1f, 实际结果: %.1f\n", expected_result, actual_result);
    }
}

// 测试主程序
int main() {
    // 打印测试标题
    printf("--- 开始测试：练习1 (变量的基本定义和初始化) ---\n");
    printf("测试目标：验证整数(10) + 浮点数(3.5) = 13.5\n\n");
    
    // 获取标准答案的结果
    float expected = calculate_sum_answer();
    
    // 运行测试用例
    run_test(1, expected);
    
    // 额外的验证信息
    printf("\n--- 详细验证 ---\n");
    printf("期望的计算过程：\n");
    printf("1. 定义整数变量：int int_num = 10;\n");
    printf("2. 定义浮点数变量：float float_num = 3.5f;\n");
    printf("3. 计算和：float sum = int_num + float_num;\n");
    printf("4. 返回结果：%.1f\n", expected);
    
    // 打印测试结束信息和如何运行的指令
    printf("\n--- 测试完成 ---\n");
    printf("编译和运行: gcc variables_problem1_solution.c variables_problem1_answer.c variables_problem1_test.c -o test1 && ./test1\n");

    // 程序正常退出
    return 0;
}
