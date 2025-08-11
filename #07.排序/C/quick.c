#include <stdio.h>

void quick(int a[], int l, int r)
{
	int i = l, j = r, flag = a[ ( l + r ) / 2 ], tmp;
	// 记录左右下标、以及哨兵元素（数组中间的元素）
	do
	{
		// 寻找左边大于哨兵的元素和右边小于哨兵的元素
		while ( a[ i ] < flag )i++;
		while ( a[ j ] > flag )j--;

		// 如果i和j没有相遇，就将这两个元素换位，并继续搜索
		if ( i <= j )
		{
			tmp = a[ i ];
			a[ i ] = a[ j ];
			a[ j ] = tmp;
			i++; j--;
		}
	// 当i和j相遇时，在哨兵的左侧都是小于其的值，右侧都是大于其的值
	} while ( i <= j );
	
	// 如果i和j还没有到边界，就调用递归函数对小份的数组再次进行快速排序
	if ( l < j )quick(a, l, j);
	if ( i < r )quick(a, i, r);
	return;
}

int arr[10] = {48, 62, 35, 77, 55, 14, 35, 98, 22, 40};

int main()
{
	quick(arr, 0, 9);
	for(int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}