// 引入标准库头文件
#include <stdio.h>

// 练习2：不同数据类型的变量使用
// 需求：创建一个函数，声明并使用各种数据类型的变量
// 要求：定义char、int、float、double类型的变量，并计算它们的"总和"
// 注意：char会被当作ASCII值参与计算

// 标准答案函数，用于测试时提供预期结果
double calculate_mixed_sum_answer() {
    // 定义一个字符变量并初始化为字符'A'
    // 'A'的ASCII值为65，在数值运算中会被当作65使用
    char char_var = 'A';
    
    // 定义一个整数变量并初始化为20
    // int类型用于存储整数
    int int_var = 20;
    
    // 定义一个单精度浮点数变量并初始化为5.5
    // float类型用于存储单精度小数，注意f后缀
    float float_var = 5.5f;
    
    // 定义一个双精度浮点数变量并初始化为2.75
    // double类型用于存储双精度小数，精度比float更高
    double double_var = 2.75;
    
    // 计算所有变量的和
    // 在混合类型运算中，低精度类型会自动提升为高精度类型
    // 运算顺序：char(65) -> int -> float -> double
    // 最终结果类型为double，因为这是最高精度的类型
    double sum = char_var + int_var + float_var + double_var;
    
    // 计算过程详解：
    // char_var('A') = 65 (ASCII值)
    // 65 + 20 + 5.5 + 2.75 = 93.25
    
    // 返回计算结果
    return sum;
}

// 将这个函数定义为"弱"函数，用于回退机制
// 当用户solution文件中没有实现calculate_mixed_sum时，使用这个函数
double __attribute__((weak)) calculate_mixed_sum() {
    return calculate_mixed_sum_answer();
}
