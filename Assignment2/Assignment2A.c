/*Implement the C program in which main program accepts the integers to be sorted. Main program
usesthe FORK system call to create a new process called a child process. Parent process sortsthe integers
using sorting algorithm and waits for child process using WAIT system call to sort the integers using any
sorting algorithm. Also demonstrate zombie and orphan states*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j] < a[min]){
                min = j;
            }
            if(min != i){
                swap(&a[i],&a[min]);
            }
        }
    }
}

void bubbleSort(int a[], int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }

}

void display(int a[],int n)
{
    int i;
    for(int i=0;i<n;i++){
        printf("%5d",a[i]);
    }
}

int main()
{
    int n;
    printf("\nEnter size of an array: ");
    scanf("%d",&n);

    int a[n],b[n];
    printf("\nEnter %d element in array: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }

    printf("\nBefore sorting: ");
    display(a,n);
    printf("\nAfter sorting: ");
    bubbleSort(a,n);
    display(a,n);

    printf("\nArray is sorted by parent process using Bubble Sort.\n\n");

    pid_t pid;
    int f = fork();

    if(f==0){
        printf("\nChild process created successfully.");
        printf("\nBefore sorting: ");
        display(b,n);
        selectionSort(b,n);
        printf("\nAfter sorting: ");
        display(b,n);
        printf("\nArray is sorted by child process using Selection Sort.\n");
    }
    else{
        printf("\nChild process not created.\n");
        printf("\nParent process waiting now...\n\n");
        pid = wait(NULL);
    }

    return 0;
}