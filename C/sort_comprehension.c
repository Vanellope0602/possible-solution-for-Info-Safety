#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bubble(int array[], int n);
void select_sort(int array[], int n);
void heapSort(int k[ ],int n);
void adjust(int k[ ],int i,int n);
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend);
void mergeSort(int k[ ],int n);
void mSort(int k[], int tmp[], int left, int right);
void quickSort(int k[ ],int left,int right);
void swap(int *a,int *b) ;
int times = 0;
int array[100];
int main()
{
    int number, method,i;
    scanf("%d %d",&number, &method);
    for(i = 0; i<number; i++)
    {
        scanf("%d", &array[i]);
    }
    if(method == 1)
    {
        select_sort(array, number);
        for(i = 0; i<number; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n%d", times);
      
    }
    else if(method == 2)
    {
    	bubble(array, number);
    	for(i = 0; i<number; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n%d", times);
	}
    
    else if(method == 3)
    {
    	heapSort(array, number);
        for(i = 0; i<number; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n%d", times);
    }
    else if(method == 4)
    {
    	
		mergeSort(array,number);
    	
    	for(i = 0; i<number; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n%d", times);

    }
    else if(method ==5)
    {
    	int left, right ;
    	left = 0;
    	right = number -1;
    	quickSort(array, left, right);
        for(i = 0; i<number; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n%d", times);
    }

    return 0;

}

void bubble(int array[], int n)
{
    int i, j, tmp, flag = 1;
    for (i = 0; i < n && flag == 1; i++) 
    {   
    	flag = 0;
        for (j = 0; j < n - i -1 ; j++) 
		{
			times++; 
			if (array[j] > array[j+1])   
           	{   
                tmp = array[j];   
                array[j] = array[j+1];   
                array[j+1] = tmp;
                flag = 1;
				  
            }   
		}   
            
      }   
}

void select_sort(int array[], int n)
{
    int i = 0, j = 0, min = 0;
    int tmp = 0;
    for(i = 0; i<n-1; i++)
    {
        min = i;
        for(j = i+1; j<n; j++)
        {
        	times++;
            if(array[min] > array[j])
            {
                min = j;
                
            }
        }
        if(min != i)
        {
            tmp = array[min];
            array[min] = array[i];
            array[i] = tmp;
        }
    }
}

void heapSort(int k[ ],int n)
{
       int i;
       int temp;
       for(i=n/2-1;i>=0; i--)
              adjust(k,i,n);
       for( i=n-1; i>=1; i--){
              temp=k[i];
              k[i]=k[0];
              k[0]=temp;
              adjust(k,0,i);
       }
 }
void adjust(int k[ ],int i,int n)
{

    int j,temp;
    temp=k[i];

    j=2*i+1;

    while(j<n)
	{
        if(j<n-1 && k[j]<k[j+1])
            j++;
		times++;
        if(temp>=k[j]) 
            break;
		
        k[(j-1)/2]=k[j];
        j=2*j+1;

    }

    k[(j-1)/2]=temp;

}
void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend)
{     
    int i=left, j=leftend+1, q=left;
    while(i<=leftend && j<=rightend)
    {
		times++;
        if(x[i]<=x[j]) 
        {
        	tmp[q++]=x[i++];	
		}
        else
            tmp[q++]=x[j++];
    }

    while(i<=leftend)
        tmp[q++]=x[i++];
    while(j<=rightend)
        tmp[q++]=x[j++];
    for(i=left; i<=rightend; i++)
        x[i]=tmp[i];

}
void mergeSort(int k[ ],int n)
{
    int *tmp;
    tmp = (int *)malloc(sizeof(int) *n);
    if(tmp != NULL) {
        mSort(k, tmp, 0, n-1);
        free(tmp);
    } 
    else
        printf("N0\n");
}
void mSort(int k[], int tmp[], int left, int right)
{
    int center;
    if(left < right){
        center = (left+right)/2;
        mSort(k, tmp, left, center);
        mSort(k, tmp, center+1, right);
        merge(k, tmp, left,center, right);
    }
}

void quickSort(int k[ ],int left,int right)
{     

    int i, last;
	int tmp;
    if(left<right)
	{
        last=left; 
        for(i=left+1;i<=right;i++)
        {
        	if(k[i]<k[left])
        	{
        		swap(&k[++last],&k[i]); 
			}
            times++;
		}
        swap(&k[left],&k[last]);

        quickSort(k,left,last-1); 
        quickSort(k,last+1,right);   

    }
}
void swap(int *a,int *b)  
{  
    int temp;  
    temp=*a;  
    *a=*b;  
    *b=temp;  
}
