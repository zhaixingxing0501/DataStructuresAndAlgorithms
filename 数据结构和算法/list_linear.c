//
//  list_linear.c
//  数据结构和算法
//
//  Created by nucarf on 2020/10/28.
//

#include "list_linear.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define MAXSIZE 100
#define SUCCESS 1
#define ERROR   0
#define TRUE    1
#define FALSE   0

/* ElemType类型根据实际情况而定，这里假设为int */
typedef int   ElemType;
/* Status是函数的类型,其值是函数结果状态代码，如SUCCESS等 */
typedef int   Status;

/*线性结构使用顺序表的方式存储*/

//顺序表结构设计
typedef struct {
    ElemType *data;
    int length;
}Sqlist;

//MARK: - 顺序表初始化
Status initList(Sqlist *L)
{
    // 为顺序表分配空间
    L->data = malloc(sizeof(ElemType) * MAXSIZE);

    if (!L->data) {
        //分配失败,退出
        exit(ERROR);
    }
    L->length = 0;
    return SUCCESS;
}

//MARK: -顺序表的插入
//初始条件：顺序线性表L已存在,1≤i≤ListLength(L);
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status listInsert(Sqlist *L, int i, ElemType e)
{
    // 判断插入位置是否合法
    if (i < 0 || i > L->length + 1) return ERROR;

    // 表已经插满
    if (L->length == MAXSIZE) return ERROR;

    // 插入位置不在表尾,插入节点之后的数据平移
    if (i <= L->length) {
        for (int j = L->length - 1; j >= i - 1; j--) {
            //插入位置以及之后的位置后移动1位
            L->data[j + 1] = L->data[j];
        }
    }
    //将新元素e 放入第i个位置上
    L->data[i - 1] = e;
    //长度+1;
    ++L->length;

    return SUCCESS;
}

Status getELEment(Sqlist L, int i, ElemType *e)
{
    // 判断取值位置是否合法
    if (i < 1 || i > L.length) return ERROR;

    *e = L.data[i - 1];
    return SUCCESS;
}

//MARK: - 顺序表删除
Status listDelete(Sqlist *L, int i)
{
    if (L->length == 0) return ERROR;

    // 判断取值位置是否合法
    if (i < 1 || i > L->length) return ERROR;

    for (int j = i; j < L->length; j++) {
        //被删除元素之后的元素向前移动
        L->data[j - 1] = L->data[j];
    }
    //表长度-1;
    L->length--;

    return SUCCESS;
}

//MARK: - 属性表清空
Status listClear(Sqlist *L)
{
    L->length = 0;
    return SUCCESS;
}

//MARK: - 判断顺序表是否为空
Status listEmpty(Sqlist L)
{
    if (L.length != 0) return FALSE;
    return TRUE;
}

//MARK: - 顺序表遍历输出
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status listTraverse(Sqlist L)
{
    int i;
    for (i = 0; i < L.length; i++) {
        printf("%d\n", L.data[i]);
    }
    printf("\n");
    return SUCCESS;
}

//MARK: - 根据表元素返回元素在表中的位置
int LocateElem(Sqlist L, ElemType e)
{
    int i;
    if (L.length == 0) return 0;

    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) break;
    }

    if (i >= L.length) return 0;
    return i + 1;
}

//MARK: - 初始化
void initList_linear(void)
{
    Sqlist L;
    int status;
    ElemType e;

    // 初始化顺讯表
    status = initList(&L);
    printf("初始化成功:%d, 长度:%d\n", status, L.length);

    // 顺序表数据插入
    for (int j = 1; j <= 5; j++) {
        status = listInsert(&L, 1, j);
    }
    printf("插入数据L长度: %d\n", L.length);

    // 顺序表取值
    getELEment(L, 3, &e);
    printf("顺序表L第3个元素的值为:%d\n", e);

    // 顺序表删除第2个元素
    listDelete(&L, 2);
    printf("顺序表删除第%d元素,长度为%d\n", 2, L.length);

    // 遍历顺序表
    listTraverse(L);

    // 查找元素位置
    int locate = LocateElem(L, 1);
    printf("元素5在L中的位置:%d\n", locate);

    // 清空属性表
    listClear(&L);
    printf("数据L长度: %d\n", L.length);

    // 是否为空
    status = listEmpty(L);
    printf("L是否空:%d (1:是 0:否)\n", status);

    printf("\n");
}
