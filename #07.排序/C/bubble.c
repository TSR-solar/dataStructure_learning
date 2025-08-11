void bubble(int a[], int n)
{
	int i, j, tmp;

	//遍历n遍数组
	for (i = 0; i < n; i++)
	{
		//比较相邻元素大小，然后小的在左大的在右
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		//每次遍历都能保证最大的元素在最右边
	}
}