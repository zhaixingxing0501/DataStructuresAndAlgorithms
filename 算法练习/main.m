//
//  main.m
//  算法练习
//
//  Created by nucarf on 2020/11/4.
//

#import <Foundation/Foundation.h>

void printfArr1(int *number, int size)
{
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d, ", number[i]);
    }
    printf("]");
}

//MARK: - 数组重新排列
/**
 给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。

 请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。

 
 示例 1：

 输入：nums = [2,5,1,3,4,7], n = 3
 输出：[2,3,5,4,1,7]
 解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]
 示例 2：

 输入：nums = [1,2,3,4,4,3,2,1], n = 4
 输出：[1,4,2,3,3,2,4,1]
 示例 3：

 输入：nums = [1,1,2,2], n = 2
 输出：[1,2,1,2]
 */
int * sortArr(int *arr, int size)
{
    int *res = (int *)malloc((sizeof(int)) * size);
    int mid = size / 2;
    int index = 0;
    CFAbsoluteTime time = CFAbsoluteTimeGetCurrent();

    for (int i = 0; i < mid; i++) {
        res[index++] = arr[i];
        res[index++] = arr[mid + i];
    }

    printf("耗时:%f", CFAbsoluteTimeGetCurrent() - time);

    return res;
}

void sortArrdemo()
{
    printf("数组重新排列\n");

    int a[] = { 1,2,3,4,4,3,2,1};

    int *res = sortArr(a, 8);
    printfArr1(res, 8);
}

//MARK: - 一位数组动态求和
/**

 给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

 请返回 nums 的动态和。

  
 示例 1：

 输入：nums = [1,2,3,4]
 输出：[1,3,6,10]
 解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
 示例 2：

 输入：nums = [1,1,1,1,1]
 输出：[1,2,3,4,5]
 解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
 示例 3：

 输入：nums = [3,1,2,10,1]
 输出：[3,4,6,16,17]


 */

int * dynamicSum(int *sums, int sumsSize)
{
    int *res = (int *)malloc((sizeof(int) * (sumsSize - 1)));

    int a = sums[0];
    for (int i = 1; i < sumsSize; i++) {
        a += sums[i];
        res[i - 1] = a;
    }
    return res;
}

void dynamicDemo()
{
    printf("一维数组动态求和\n");
    int a[] = { 2, 2, 5, 7, 9 };

    int *res = dynamicSum(a, 5);

    printfArr1(res, 4);
}

//MARK: - 两数之和
/**

 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。


 示例:
 给定 nums = [2, 7, 11, 15], target = 9

 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]

 */

// 暴力法 遍历循环  时间复杂度：O(n²) 空间复杂度：O(1)
int * twoSum1(int *nums, int target, int numberSize)
{
    int *res = (int *)malloc((sizeof(int)) * 2);

    for (int i = 0; i < numberSize - 1; i++) {
        for (int j = i + 1; j < numberSize; j++) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }

    return res;
}

void twoNumber()
{
    printf("两数之和\n");

    int a[] = { 2, 5, 7, 9 };

    int *res = twoSum1(a, 16, 4);

    printf("数组:%d-%d\n", res[0], res[1]);
}

int main(int argc, const char *argv[])
{
    @autoreleasepool {
        // insert code here...

        sortArrdemo();
//        dynamicDemo();
//        twoNumber();
        printf("\n");
    }
    return 0;
}
