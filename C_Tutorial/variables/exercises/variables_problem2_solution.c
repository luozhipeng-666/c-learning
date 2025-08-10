// 引入标准库头文件
#include <stdio.h>

// 练习2：不同数据类型的变量使用
// 需求：创建一个函数，声明并使用各种数据类型的变量
// 要求：定义char、int、float、double类型的变量，并计算它们的"总和"
// 注意：char会被当作ASCII值参与计算

// 特别注意：请先移除下面代码注释，才能进行：
// 默认情况下注释掉相关函数

double calculate_mixed_sum() {
    // TODO: 定义一个字符变量 char_var，初始化为字符 'A' (ASCII值为65)
    // TODO: 定义一个整数变量 int_var，初始化为20
    // TODO: 定义一个单精度浮点数变量 float_var，初始化为5.5f
    // TODO: 定义一个双精度浮点数变量 double_var，初始化为2.75
    // TODO: 将所有变量相加，返回double类型的结果
    // 提示：char类型会自动转换为对应的ASCII整数值参与运算

    char char_var = 'A';
    int int_var = 20;
    float float_var = 5.5f;
    double double_var = 2.75;
    double sum = char_var + int_var + float_var + double_var;
    return sum;
}
