#include <stdio.h>
#include <stdlib.h>

// ����ṹ���ʾ���������ظ�����
typedef struct {
    int value;
    int count;
} IntegerWithCount;

// �ȽϺ����������������������ظ������Ľṹ��
int compare(const void *a, const void *b) {
    IntegerWithCount *ia = (IntegerWithCount *)a;
    IntegerWithCount *ib = (IntegerWithCount *)b;
    return ia->value - ib->value;
}

int main() {
    // ��ȡ��һ��������
    int n1,i;
    scanf("%d", &n1);
    int *set1 = (int *)malloc(n1 * sizeof(int));
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // ��ȡ�ڶ���������
    int n2;
    scanf("%d", &n2);
    int *set2 = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // ��������������Ƿ���ͬ
    if (n1 != n2) {
        printf("0\n");
        return 0;
    }

    // �Ե�һ������������
    qsort(set1, n1, sizeof(int), compare);

    // �Եڶ�������������
    qsort(set2, n2, sizeof(int), compare);

    // ��������������������Ƿ���ͬ
    for (i = 0; i < n1; i++) {
        if (set1[i] != set2[i]) {
            printf("0\n");
            return 0;
        }
    }

    // ���1��ʾ������������ͬ
    printf("1\n");

    // �����һ���������е����ݼ��ظ�����
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

    // �ͷ��ڴ�
    free(set1);
    free(set2);

    return 0;
}



