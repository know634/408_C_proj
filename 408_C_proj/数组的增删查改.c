#include <stdio.h>

#define MAX_SIZE 100

// ����ṹ��
typedef struct {
    int data[MAX_SIZE];  // �洢Ԫ�ص�����
    int length;          // ���鳤��
} Array;

// ��ʼ������
void init_array(Array* arr) {
    arr->length = 0;
}

// ��ָ��λ�ò���Ԫ��
int insert_array(Array* arr, int pos, int value) {
    int i;
    if (pos < 1 || pos > arr->length + 1) {
        return 0;
    }
    if (arr->length >= MAX_SIZE) {
        return 0;
    }
    for (i = arr->length - 1; i >= pos - 1; i--) {
        arr->data[i + 1] = arr->data[i];
    }
    arr->data[pos - 1] = value;
    arr->length++;
    return 1;
}

// ɾ��ָ��λ�õ�Ԫ��
int delete_array(Array* arr, int pos) {
    int i;
    if (pos < 1 || pos > arr->length) {
        return 0;
    }
    for (i = pos - 1; i < arr->length - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
    return 1;
}

// ��ȡָ��λ�õ�Ԫ��
int get_array(Array* arr, int pos, int* value) {
    if (pos < 1 || pos > arr->length) {
        return 0;
    }
    *value = arr->data[pos - 1];
    return 1;
}

// �޸�ָ��λ�õ�Ԫ��
int set_array(Array* arr, int pos, int value) {
    if (pos < 1 || pos > arr->length) {
        return 0;
    }
    arr->data[pos - 1] = value;
    return 1;
}

// �������
void print_array(Array* arr) {
    int i;
    printf("Array: [");
    for (i = 0; i < arr->length; i++) {
        printf("%d", arr->data[i]);
        if (i < arr->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    Array arr;
    int value;

    // ��ʼ������
    init_array(&arr);

    // ����Ԫ��
    insert_array(&arr, 1, 1);
    insert_array(&arr, 2, 2);
    insert_array(&arr, 3, 3);
    insert_array(&arr, 4, 4);

    // �������
    print_array(&arr);

    // ɾ��Ԫ��
    delete_array(&arr, 3);

    // �������
    print_array(&arr);

    // ��ȡԪ��
    get_array(&arr, 2, &value);
    printf("Array[%d] = %d\n", 2, value);

    // �޸�Ԫ��
    set_array(&arr, 2, 5);

    // �������
    print_array(&arr);

    return 0;
}
