#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i;
    scanf("%d", &n);

    // Ϊ�˷�����������������������Χ�� [-10000, 10000] ֮��
    int count[20001] = {0}; // ʹ�������¼ÿ���������ֵĴ���
    int max_count = 0; // ��¼���ִ������������ĳ��ִ���
    int max_number; // ��¼���ִ�����������

    for (i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        // ������ӳ�䵽�����������Χ��
        num += 10000;
        count[num]++;
        if (count[num] > max_count) {
            max_count = count[num];
            max_number = num - 10000; // ������ӳ���ԭ��������
        }
    }

    // ������ִ�����������������ִ���
    printf("%d %d\n", max_number, max_count);

    // ����������ִ�������������ͬ������
    for (i = 0; i <= 20000; ++i) {
        if (count[i] == max_count && i - 10000 != max_number) {
            printf("%d %d\n", i - 10000, max_count);
        }
    }

    return 0;
}


