//
//  main.c
//  双向链表操作
//
//  Created by nucarf on 2020/10/28.
//

#include <stdio.h>
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#define ERROR   0
#define TRUE    1
#define FALSE   0
#define OK      1
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int   Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int   ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

//定义结点
typedef struct Node {
    ElemType data;
    struct Node *prior;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

//MARK: - 创建双向链表
Status createLinkList(LinkList *L)
{
    // *L 指向头结点
    *L = malloc(sizeof(Node));
    if (L == NULL) return ERROR;

    (*L)->next = NULL;
    (*L)->prior = NULL;
    (*L)->data = -1;

    //新增节点
    LinkList p = *L;
    for (int i = 0; i < 10; i++) {
        // 1. 创建临时节点
        LinkList tmp = (LinkList)malloc(sizeof(Node));
        tmp->prior = NULL;
        tmp->next = NULL;
        tmp->data = i;

        // 2. 为新增节点建立双向链接关系
        //2.1 temp 是p的后继
        p->next = tmp;
        //2.2 tmp 的前驱是 p
        tmp->prior = p;
        //2.3 p 要记录最后的结点的位置,方便下一次插入
        p = p->next;
    }

    return OK;
}

//MARK: - 打印链表
void displayList(LinkList L)
{
    LinkList tmp = L->next;
    if (tmp == NULL) {
        printf("打印链表为空");
        return;
    }

    while (tmp) {
        printf("%d  ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    
}

int main(int argc, const char *argv[])
{
    // insert code here...
    printf("Hello, World!\n");

    Status iStatus = 0;
    LinkList L;
    int temp, item, e;

    iStatus =  createLinkList(&L);
    printf("链表创建iStatus = %d\n", iStatus);
    displayList(L);

    return 0;
}
