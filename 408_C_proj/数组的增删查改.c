#include <stdio.h>

#define MAX_SIZE 100

// 数组结构体
typedef struct {
    int data[MAX_SIZE];  // 存储元素的数组
    int length;          // 数组长度
} Array;

// 初始化数组
void init_array(Array* arr) {
    arr->length = 0;
}

// 在指定位置插入元素
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

// 删除指定位置的元素
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

// 获取指定位置的元素
int get_array(Array* arr, int pos, int* value) {
    if (pos < 1 || pos > arr->length) {
        return 0;
    }
    *value = arr->data[pos - 1];
    return 1;
}

// 修改指定位置的元素
int set_array(Array* arr, int pos, int value) {
    if (pos < 1 || pos > arr->length) {
        return 0;
    }
    arr->data[pos - 1] = value;
    return 1;
}

// 输出数组
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

    // 初始化数组
    init_array(&arr);

    // 插入元素
    insert_array(&arr, 1, 1);
    insert_array(&arr, 2, 2);
    insert_array(&arr, 3, 3);
    insert_array(&arr, 4, 4);

    // 输出数组
    print_array(&arr);

    // 删除元素
    delete_array(&arr, 3);

    // 输出数组
    print_array(&arr);

    // 获取元素
    get_array(&arr, 2, &value);
    printf("Array[%d] = %d\n", 2, value);

    // 修改元素
    set_array(&arr, 2, 5);

    // 输出数组
    print_array(&arr);

    return 0;
}
