#include"sort.h"
#include<time.h>
#include <cstring> 
#include<assert.h>
#include<stack>
#include <iostream>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
using namespace std;

void getRandArray(int array[], int size)  //利用伪随机数填充数组array，伪随机数的范围在RANDMIN~RANDMAX-1之间  
{  
    assert(array != NULL && size > 0);  
    srand((unsigned) time(NULL));  
    int i = 0;  
    for (i = 0; i < size; ++i) 
	{  
        array[i] = rand() % (RANDMAX - RANDMIN) + RANDMIN ;  
    }  
	return ;
}  
//****************************************************************
//判断数组array是否已经是有序的  
void isSorted(int array[], int size)  
{  
    assert(array != NULL && size > 0);  
  
    int unsorted = 0;  
    int i = 0;  
    for (i = 1; i < size; ++i) 
	{  
        if (array[i] < array[i - 1]) 
		{  
            unsorted = 1;  
            break;  
        }  
    }   
    if (unsorted) {  
        printf("the array is unsorted!\n");  
    } else {  
        printf("the array is sorted!\n");  
    }  
}  
//****************************************************************
void Time_InsertSort(double time[6][4],int *size)
{
  int size1=10,size2=50,size3=200,size4=100;
  int *array = NULL;
   array = (int *)calloc(size1, sizeof(int));
  getRandArray(array, size1); 
  clock_t begin;  
  clock_t end;  
  begin = clock();  
  InsertSort(array, size1);  
  end = clock(); 
  time[0][0]=((end - begin) / 1000.0);
  free (array);
  array = (int *)calloc(size2, sizeof(int));
  getRandArray(array, size2); 
  begin = clock();  
  InsertSort(array, size2);  
  end = clock(); 
  time[0][1]=((end - begin) / 1000.0);
  free(array);
  array = (int *)calloc(size3, sizeof(int));
 getRandArray(array, size3); 
  begin = clock();  
  InsertSort(array, size3);  
  end = clock(); 
  time[0][2]=((end - begin) / 1000.0);
  free (array);
  array = (int *)calloc(size4, sizeof(int));
  getRandArray(array, size4); 
  begin = clock();  
  for(int i=1;i<=100000;i++)
  {
	InsertSort(array, size4);
	getRandArray(array, size4); 
  }
  InsertSort(array, size3);  
  end = clock(); 
  time[0][3]=((end - begin) / 1000.0); 
  printf("%lf  %lf  %lf  %lf", time[0][0], time[0][1], time[0][2], time[0][3]);
}
//****************************************************************
void InsertSort(int data[], int n) //插入排序
{
    int low,high,mid;
    int temp,i,j;
    for(i=1;i<n;i++)
	{
        low = 0;
        //把data[i]元素插入到它的前面data[0-(i-1)]中
        temp =data[i];
        high = i-1;
        //该while是折半，缩小data[i]的范围(优化手段)
        while(low <= high) {
            mid = (low+high)/2;
            if(data[mid] > temp) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
         j = i;
        //让data与已经排序好的数组的各个元素比较，小的放前面
        while((j > low) && data[j-1] > temp) 
		{
            data[j] = data[j-1];
            --j;
		}
        data[low] = temp;
    }
}
//************************************************************************
void MergeSort(int data[], int first, int last) //归并排序
{
    int mid = 0;
    //将数组不停的二分分组再组合，直到每组只剩一个元素
    if(first < last)
	{
        mid = (first+last)/2;
        MergeSort(data, first, mid);
        MergeSort(data, mid+1, last);
        merge(data, first, mid, last);
    }
    
}
void merge(int data[], int low, int mid, int high)
{
    int i, k;
    //定义一个临时数组存放传进来的无序数组排好序之后的数组
    int *temp = (int *)malloc((high-low+1)*sizeof(int));
    //将无序数组分成两个序列
    int left_low = low;
    int left_high = mid;
    int right_low = mid+1;
    int right_high = high;
    //将两个序列比较排序，小的排前
    for(k=0;left_low<=left_high && right_low<=right_high;k++)
	{
        if(data[left_low]<=data[right_low])
		{
            temp[k] = data[left_low++];
        }
        else
		{
            temp[k] = data[right_low++];
        }
    }
    //左序列如果有剩下元素未排序，加到临时数组的末尾
    if(left_low <= left_high)
	{
        for(i=left_low;i<=left_high;i++)
		{
            temp[k++] = data[i];
        }
    }
    //右序列如果有剩下元素未排序，加到临时数组的末尾
    if(right_low <= right_high)
	{
        for(i=right_low;i<=right_high;i++)
		{
            temp[k++] = data[i];
        }
    }
    //将排好序的小分组转移到原数组中
    for(i=0;i<high-low+1;i++) {
        data[low+i] = temp[i];
    }
    free(temp);
    
}
//*******************************************************************
//快排递归版
void  QSort_Recursion(int *a, int left, int right)
{
	if (left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
	{
		return;
	}
	int i = left;
	int j = right;
	int key = a[left];

	while (i < j)                               /*控制在当组内寻找一遍*/
	{
		while (i < j && key <= a[j])
			/*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
			序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
		{
			j--;/*向前寻找*/
		}

		a[i] = a[j];
		/*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
		a[left]，那么就是给key）*/

		while (i < j && key >= a[i])
			/*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
			因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
		{
			i++;
		}

		a[j] = a[i];
	}

	a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
	QSort_Recursion(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
	QSort_Recursion(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
						  /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}
//*******************************************************************
//快排非递归版
int partition(int a[],int first,int last)  //第一次排序划分
{  
    int key=a[first];  
    while(first<last)  
    {  
        while(first<last&&a[last]>=key)  
            --last;  
        a[first] = a[last];  
   
        while(first < last && a[first] <= key)  
            ++first;  
        a[last] = a[first];      
    }  
    a[first] = key;  
    return first;  
}  

void QSort(int a[],int low,int high)  
{  
    Bor b;  
    int p;  
    stack<Bor>s;  
    b.low=low;  b.high=high;  
    s.push(b);  
    while(!s.empty())  
    {  
        Bor tep;  
        tep=s.top(); s.pop();  
        p=partition(a,tep.low,tep.high);  
        if(p-1>tep.low)  
        {  
            Bor dd;  
            dd.low=tep.low;  
            dd.high=p-1;  
            s.push(dd);  
        }  
        if(p+1<tep.high)  
        {  
            Bor dd;  
            dd.low=p+1;  
            dd.high=tep.high;  
            s.push(dd);  
        }  
    }  
}  
//***************************************************************
//计数排序
void CountSort(int array[], int size)  
{  
    assert(array != NULL && size > 0);  
  
    //计数数组，用于统计数组array中各个不同数出现的次数  
    //由于数组array中的数属于0...RANDMAX-1之间，所以countArray的大小要够容纳RANDMAX个int型的值  
    int *countArray = (int *) calloc(RANDMAX, sizeof(int));  
    //用于存放已经有序的数列  
    int *sortedArray = (int *) calloc(size, sizeof(int));  
  
    //统计数组array中各个不同数出现的次数，循环结束后countArray[i]表示数值i在array中出现的次数  
    int index = 0;  
    for (index = 0; index < size; ++index) {  
        countArray[array[index]]++;  
    }  
  
    //统计数值比index小的数的个数，循环结束之后countArray[i]表示array中小于等于数值i的元素个数  
    for (index = 1; index < RANDMAX; ++index) {  
        countArray[index] += countArray[index - 1];  
    }  
  
    for (index = size - 1; index >= 0; --index) {  
        //因为数组的起始下标为0，所以要减一  
        sortedArray[countArray[array[index]] - 1] = array[index];  
        //这里减一是为了保证当有多个值为array[index]的元素时，后出现的值为array[index]的元素  
        //放在后面，也就是为了保证排序的稳定性  
        --countArray[array[index]];  
    }  
    memcpy(array, sortedArray, size * sizeof(int));  
    free(sortedArray);  
    free(countArray);  
}  
//*****************************************************************
 //基数计数排序
void RadixCountSort(int data[], int n) 
{                                                             
    int i,j,k,pos,num,index;
    //这几句话是创建一个从0-9(行)× (n+1)(列)的网格，第一列从上往下是0-9,
    //第二列是该行包含的元素个数，默认为0个
    int *radixArrays[10];
    for(i=0;i<10;i++)
	{
        radixArrays[i] = (int *)malloc(sizeof(int) * (n+1));
        radixArrays[i][0] = 0;
    }
    //pos最大为31为数，计算机能承受的最大范围了
    for(pos=1;pos<=31;pos++)
	{
        //该for循环是将数组的元素按照位数(pos)的值放进网格内
        for(i=0;i<n;i++)
		{
            num = getNumPos(data[i], pos);
            index = ++radixArrays[num][0];
            radixArrays[num][index] = data[i];
        }
        //该for循环是将上面的for循环已经按照某个位数(pos)排列好的元素存入数组
        for(i=0,j=0;i<10;i++)
		{
            for(k=1;k<=radixArrays[i][0];k++)
			{
                data[j++] = radixArrays[i][k];
            }
            //清空网格，以便给下个位数排列
            radixArrays[i][0] = 0;
        }
    }
}

int getNumPos(int num, int pos) //该函数的作用是找出num的pos位数的数字(比如：23的个位数数字是3)
{
    int i;
    int temp = 1;
    for(i=0;i<pos-1;i++)
	{
        temp *= 10;
    }
    return (num / temp) % 10;
}
//*********************************************************************