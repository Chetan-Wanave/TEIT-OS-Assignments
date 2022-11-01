/*Implement the C program in which main program accepts an array. Main program uses the FORK
system call to create a new process called a child process. Parent process sorts an array and passes the
sorted array to child process through the command line arguments of EXECVE system call. The child
process uses EXECVE system callto load new program which display array in reverse order.*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// 5 4 3 2 6 7 8 2 1

int partition(int a[],int low,int high)
{
	int i=low,j=high;
	int pivotElement  = a[low];
	
	while(i<j){
		while(pivotElement >= a[i] ){
			i++;
		}

		while(pivotElement < a[j]){
			j--;
		}

		if(i<j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int tmp = a[low];
	a[low]  = a[j];
	a[j] = tmp;
	return j;
}

void quickSort(int a[],int low,int high){
	if(low<high){
		int loc = partition(a,low,high);
		quickSort(a,low,loc-1);
		quickSort(a,loc+1,high);
	}
}

void reverse(int a[]){
	int j;
	for(j=6;j>=0;j--){
		printf("%5d",a[j]);
	}
}

int main(int argc,char *argv[])
{
	int i,n;
	printf("\nEnter size of an array: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements into array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nArray before sorting : ");
	for(i=0;i<n;i++){
		printf("%5d",a[i]);
	}
	quickSort(a,0,n-1);
	printf("\nArray after sorting  : ");
	for(i=0;i<n;i++){
		printf("%5d",a[i]);
	}
	char arr[n];
	for(i=0;i<n;i++){
		arr[i] = a[i]; 
	}
	
	char *newargv[] = { NULL,arr, NULL };
    char *newenviron[] = { NULL };
	
	if (argc != 2) {
                   fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
                   exit(EXIT_FAILURE);
    }

   newargv[0] = argv[1];
	
	int PID = fork();
	
	if(PID == 0){
		execve(argv[1], newargv, newenviron);
   		perror("execve");   /* execve() returns only on error */
   		exit(EXIT_FAILURE);
	}
	else{
		printf("\nSorted by Parent Process");
	}
	
	return 0;
}