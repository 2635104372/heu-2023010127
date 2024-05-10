#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i;
    scanf("%d", &n);

    // 为了方便起见，假设输入的整数范围在 [-10000, 10000] 之间
    int count[20001] = {0}; // 使用数组记录每个整数出现的次数
    int max_count = 0; // 记录出现次数最多的整数的出现次数
    int max_number; // 记录出现次数最多的整数

    for (i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        // 将整数映射到数组的索引范围内
        num += 10000;
        count[num]++;
        if (count[num] > max_count) {
            max_count = count[num];
            max_number = num - 10000; // 将索引映射回原来的整数
        }
    }

    // 输出出现次数最多的整数及其出现次数
    printf("%d %d\n", max_number, max_count);

    // 输出其他出现次数与最多次数相同的整数
    for (i = 0; i <= 20000; ++i) {
        if (count[i] == max_count && i - 10000 != max_number) {
            printf("%d %d\n", i - 10000, max_count);
        }
    }

    return 0;
}


