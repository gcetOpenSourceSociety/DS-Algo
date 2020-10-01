#include<stdio.h>
main()
{
	int a[100],i,j,n,temp,min;
	printf("Enter the number of elements \n");
	scanf("%d",&n);
	printf("Enter the elements of the array \n");
	for(i=0;i<n;i++)
	{
	
	scanf("%d",&a[i]);
}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
			if (min!=i)
			{
				temp=a[i];
				a[i]=a[min];
				a[min]=temp;
			}
		
	}
	printf("Sorted array is \n");
	for (i=0;i<n;i++)
	printf("%d \t",a[i]);
	
}
