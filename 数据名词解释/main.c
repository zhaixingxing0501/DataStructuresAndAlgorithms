//
//  main.c
//  数据名词解释
//
//  Created by nucarf on 2020/10/28.
//

#include <stdio.h>

/**

 数据: 程序的操作对象,用于描述客观事物.
 数据的特点: 1️⃣ 可以输入到计算机 2️⃣ 可以被计算机处理

 数据项: 一个数据元素由若干数据项组成
 数据元素: 组成数据的对象的基本单位
 数据对象: 性质相同的数据元素的集合(类似于数组)

 结构: 数据元素之间不是独立的,存在特定的关系.这些关系即是结构;
 数据结构:指的数据对象中的数据元素之间的关系

 */

//声明一个结构体类型
struct Teacher {     //一种数据结构
    char *name;     //数据项--名字
    char *title;    //数据项--职称
    int age;        //数据项--年龄
};

void initDataIntroduce(void)
{
    printf("数据结构名词介绍\n");

    struct Teacher t1;     //数据元素;
    struct Teacher tArray[10]; //数据对象;

    t1.age = 18;       //数据项
    t1.name = "star";    //数据项
    t1.title = "讲师";  //数据项
}

int main(int argc, const char *argv[])
{
    // insert code here...

    struct Teacher t1;     //数据元素;
    struct Teacher tArray[10]; //数据对象;

    t1.age = 18;       //数据项
    t1.name = "star";    //数据项
    t1.title = "测试";  //数据项

    printf("Hello, World!\n");

    return 0;
}
