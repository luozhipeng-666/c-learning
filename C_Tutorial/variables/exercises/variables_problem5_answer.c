// 引入标准库头文件
#include <stdio.h>

// 练习5：变量的综合应用
// 需求：创建一个综合练习，涉及常量、类型转换、变量运算等概念
// 要求：实现一个函数，计算圆的面积和周长，演示常量使用和类型转换

// 标准答案函数，用于测试时提供预期结果
double calculate_circle_area_and_perimeter_answer(double radius, double* perimeter) {
    // 定义一个常量PI
    // const关键字表示这个变量的值不能被修改
    // 常量通常用大写字母命名，提高代码可读性
    const double PI = 3.14159;
    
    // 验证输入参数的有效性
    if (radius < 0) {
        // 半径不能为负数，设置周长为0并返回0面积
        if (perimeter != NULL) {
            *perimeter = 0.0;
        }
        return 0.0;
    }
    
    // 计算圆的面积
    // 公式：面积 = π × r²
    // 这里演示了double类型的精确计算
    double area = PI * radius * radius;
    
    // 计算圆的周长并通过指针参数返回
    // 公式：周长 = 2 × π × r
    // 检查指针是否为NULL，避免程序崩溃
    if (perimeter != NULL) {
        *perimeter = 2 * PI * radius;
    }
    
    // 打印计算过程（用于调试和理解）
    printf("答案函数 - 计算过程：\n");
    printf("  常量 PI = %.5f\n", PI);
    printf("  半径 radius = %.2f\n", radius);
    printf("  面积计算：PI * radius * radius = %.5f * %.2f * %.2f = %.5f\n", 
           PI, radius, radius, area);
    if (perimeter != NULL) {
        printf("  周长计算：2 * PI * radius = 2 * %.5f * %.2f = %.5f\n", 
               PI, radius, *perimeter);
    }
    
    // 返回面积值
    return area;
}

// 将这个函数定义为"弱"函数，用于回退机制
// 当用户solution文件中没有实现calculate_circle_area_and_perimeter时，使用这个函数
double __attribute__((weak)) calculate_circle_area_and_perimeter(double radius, double* perimeter) {
    return calculate_circle_area_and_perimeter_answer(radius, perimeter);
}
