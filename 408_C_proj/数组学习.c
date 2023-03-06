// 新建变量
#include <stdio.h>

int main()
{
	// 三种方式定义数组
	int a[5] = {1,2,3,4,5};
	int b[5] = {1,2,3};

	// 对数组进行访问，删除，增加
	// 访问
	printf("\n数组的第一个是 %d", a[0]);
	// 删除
	printf("\n删除数组的第一个是 %d", a[0]);
	// 增加
	printf("\n增加数组的第一个是 %d", a[0]);

	return 0;
}
