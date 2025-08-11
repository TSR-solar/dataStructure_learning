void choose(int a[], int n)
{
	int i, j, tmp;

	//遍历n遍数组
	for ( i = 0; i < n; i++ )
	{
		for ( j = i + 1; j < n; j++ )
		{
			//如果元素比最左边的数小，就把它与最左边的元素交换
			if ( a[ i ] > a[ j ] )
			{
				tmp = a[ i ];
				a[ i ] = a[ j ];
				a[ j ] = tmp;
			}
		}
		//每次遍历都能保证最小的元素在最左边
	}
	return;
}  