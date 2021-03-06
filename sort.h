#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED


#define RANDMAX 100
#define RANDMIN 1  

typedef struct
{  
    int high;  
    int low;  
}Bor;   //建立结构体存储两个下标   
  
void Time_InsertSort(double time[6][4], int array[]);
void getRandArray(int array[], int size);// 利用伪随机数填充数组array，伪随机数的范围在RANDMIN~RANDMAX-1之间  
void isSorted(int array[], int size);  //判断是否已经排序
void InsertSort(int data[], int n); //插入排序
void MergeSort(int data[], int first, int last); //归并排序
void merge(int data[], int low, int mid, int high);
void QSort_Recursion(int array[], int low, int hight);//快排递归版
void QSort(int a[], int low, int high);    //快排非递归版           
int partition(int a[], int first, int last); //第一次排序划分
void CountSort(int array[], int size);//计数排序
void RadixCountSort(int data[], int n); //基数基数排序
int getNumPos(int num, int pos);//该函数的作用是找出num的pos位数的数字(比如：23的个位数数字是3)





#endif // QUEUE_H_INCLUDED
