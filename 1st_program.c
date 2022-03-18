
//header file
#include<stdio.h>
#include<time.h>
#include<conio.h>

//function prototype
void quick_sort(int[],int,int);
int partition(int[],int,int);

//clock_t is datatype to store cpu cycle
clock_t start,end;

//declare a variable to store the time taken by program to execute
double cpu;

//main function 
void main()
{   
    //declare all the variable which will be used in program
    int a[50],n,i;
    //clear the previous output in console(output screen)
    clrscr();

    //start the clock 
    start=clock();

    //size of array 
    printf("how many elements?");
    scanf("%d",&n);

    //enter the element in array
    printf("\n enter array elements:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    //function call 
    //        (array, 0, index of last element)
    quick_sort(a,0,n-1);
    //output
    printf("\n array after sorting:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);

    //end the clock
    end=clock();

    //calculate the time taken by subtracting end from start
    cpu=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n time taken is:%f",cpu);
    getch();
}

//function defination
//an recursive function (learn about recursive algorith from google or youtube)
void quick_sort(int a[],int low,int u)
{
    int j;
    //to check the array should carry more than 1 element in array
    if(low<u)
    {
        j=partition(a,low,u);
        //first part of the array
        quick_sort(a,low,j-1);
        //second part of the array
        quick_sort(a,j+1,u);
    }
}

//main logic where the sorting is going to take place
int partition(int a[],int low,int u)
{
    int v,i,j,temp;
    v=a[low];
    j=u+1;
    do
    {
        do
        i++;
        while(a[i]<v&&i<=u);
        do
        j--;
        while(v<a[j]);

        //swap the element palce if the condition is true (refer to algorith from 'puntabekar book')
        if(i<j)
        {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        }
    }
    while(i<j);

    //if while loop break or done then excute this part of code (yet to explain)
    a[low]=a[j];
    a[j]=v;
    return(j);
}