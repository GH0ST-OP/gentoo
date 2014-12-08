#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/string.h>

//This systemcall takes a string and reverses it
asmlinkage long sys_reverse(char *input) {
  int i, j;
  char temp;

  printk("Reversing string: %s\n", input);

  i= 0;
  j = strlen(input) - 1;

  while (i < j) {
    temp = input[i];
    input[i] = input[j];
    input[j] = temp;
    i++;
    j--;
  }
  printk("Reversed String: %s\n", input);
  return 0;
}
