#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int
main(int argc, char *argv[])
{
   int j,a[7];
  for (j = 0; j < argc; j++){
                   printf("argv[%d]: %s\n", j, argv[j]);      
   } 
   int size = sizeof(argv[1])/sizeof((argv[1])[0]);
   for(int i=size+1;i>=0;i--){
       printf("%5d",(argv[1])[i]);
   }
   exit(EXIT_SUCCESS);
}
