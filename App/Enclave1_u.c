#include "Enclave1_u.h"
#include <errno.h>

typedef struct ms_ecall_Main_sample_t {
	int ms_retval;
} ms_ecall_Main_sample_t;

typedef struct ms_ocall_Main_sample_t {
	const char* ms_str;
} ms_ocall_Main_sample_t;

static sgx_status_t SGX_CDECL Enclave1_ocall_Main_sample(void* pms)
{
	ms_ocall_Main_sample_t* ms = SGX_CAST(ms_ocall_Main_sample_t*, pms);
	ocall_Main_sample(ms->ms_str);

	return SGX_SUCCESS;
}

static const struct {
	size_t nr_ocall;
	void * table[1];
} ocall_table_Enclave1 = {
	1,
	{
		(void*)Enclave1_ocall_Main_sample,
	}
};
sgx_status_t Enclave1_ecall_Main_sample(sgx_enclave_id_t eid, int* retval)
{
	sgx_status_t status;
	ms_ecall_Main_sample_t ms;
	status = sgx_ecall(eid, 0, &ocall_table_Enclave1, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

