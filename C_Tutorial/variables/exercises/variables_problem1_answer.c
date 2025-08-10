// 引入标准库头文件
#include <stdio.h>

// 练习1：变量的基本定义和初始化
// 需求：创建一个函数，定义并初始化不同类型的变量，然后计算并返回它们的和
// 要求：定义一个整数变量(值为10)、一个浮点数变量(值为3.5)，返回它们的和

// 标准答案函数，用于测试时提供预期结果
float calculate_sum_answer() {
    // 定义一个整数变量并初始化为10
    // int类型用于存储整数，这里存储的是10
    int int_num = 10;
    
    // 定义一个浮点数变量并初始化为3.5
    // float类型用于存储小数，注意f后缀表示这是float类型常量
    float float_num = 3.5f;
    
    // 计算两个变量的和
    // 当int和float进行运算时，int会自动转换为float类型
    // 这种转换称为隐式类型转换
    float sum = int_num + float_num;
    
    // 返回计算结果
    return sum;
}

// 将这个函数定义为"弱"函数，用于回退机制
// 当用户solution文件中没有实现calculate_sum时，使用这个函数
float __attribute__((weak)) calculate_sum() {
    return calculate_sum_answer();
}
