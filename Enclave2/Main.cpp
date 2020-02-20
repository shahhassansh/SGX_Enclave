#include "../Enclave2/Main.h"

#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include "Enclave2_t.h"  /* print_string */

/* 
 * printf: 
 *   Invokes OCALL to display the enclave buffer to the terminal.
 */
void printf(const char *fmt, ...)
{
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_Main_sample(buf);
}

int ecall_Main_sample()
{
  printf("IN MAIN ENCLAVE2\n");
  return 0;
}

