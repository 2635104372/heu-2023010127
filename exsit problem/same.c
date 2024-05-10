#include <stdio.h>
#include <stdlib.h>

// 定义结构体表示整数及其重复个数
typedef struct {
    int value;
    int count;
} IntegerWithCount;

// 比较函数，用于排序整数及其重复个数的结构体
int compare(const void *a, const void *b) {
    IntegerWithCount *ia = (IntegerWithCount *)a;
    IntegerWithCount *ib = (IntegerWithCount *)b;
    return ia->value - ib->value;
}

int main() {
    // 读取第一个整数集
    int n1,i;
    scanf("%d", &n1);
    int *set1 = (int *)malloc(n1 * sizeof(int));
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // 读取第二个整数集
    int n2;
    scanf("%d", &n2);
    int *set2 = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // 检查两个整数集是否相同
    if (n1 != n2) {
        printf("0\n");
        return 0;
    }

    // 对第一个整数集排序
    qsort(set1, n1, sizeof(int), compare);

    // 对第二个整数集排序
    qsort(set2, n2, sizeof(int), compare);

    // 检查排序后的两个整数集是否相同
    for (i = 0; i < n1; i++) {
        if (set1[i] != set2[i]) {
            printf("0\n");
            return 0;
        }
    }

    // 输出1表示两个整数集相同
    printf("1\n");

    // 输出第一个整数集中的数据及重复个数
    int current = set1[0];
    int count = 1;
    for (i = 1; i < n1; i++) {
        if (set1[i] == current) {
            count++;
        } else {
            printf("%d %d\n", current, count);
            current = set1[i];
            count = 1;
        }
    }
    printf("%d %d\n", current, count);

    // 释放内存
    free(set1);
    free(set2);

    return 0;
}



