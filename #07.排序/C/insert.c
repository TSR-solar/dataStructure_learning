void insert(int a[], int n)
{
	int tmp, i, j;

	//遍历数组
	for ( i = 1; i < n; i++ )
	{
		tmp = a[ i ];//记录要插入的元素
		for ( j = i - 1; j >= 0; j-- )
		{
			//元素如果大于它则右移，否则留出空位让其插入
			if ( a[ j ] > tmp )
			{
				a[ j + 1 ] = a[ j ];
			}
			else break;
		}
		a[ j + 1 ] = tmp;//将元素插入空位
	}
	return;
}