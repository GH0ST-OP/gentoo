#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(void) {
 char *string;
 char *input;
 int length;

 string = "This is a test";
 length = strlen(string);

 input = (char*)malloc(length * sizeof(char));
 strcpy(input, string); 

// if(syscall(316, string) == -1) {
//  fprintf(stderr, "Error Calling Syscall: %s\n", strerror(errno));
//  return 1;
// }

syscall(316, input);

FILE *fp = fopen("output", "w");
if (fp != NULL){
fputs(input, fp);
fclose(fp);
}

printf("\x1b[31m WOOOO");

return 0;
}
