#ifndef ENCLAVE1_U_H__
#define ENCLAVE1_U_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <string.h>
#include "sgx_edger8r.h" /* for sgx_status_t etc. */


#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OCALL_MAIN_SAMPLE_DEFINED__
#define OCALL_MAIN_SAMPLE_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, ocall_Main_sample, (const char* str));
#endif

sgx_status_t Enclave1_ecall_Main_sample(sgx_enclave_id_t eid, int* retval);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
