#ifndef ENCLAVE2_T_H__
#define ENCLAVE2_T_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include "sgx_edger8r.h" /* for sgx_ocall etc. */


#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

int ecall_Main_sample(void);

sgx_status_t SGX_CDECL ocall_Main_sample(const char* str);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
