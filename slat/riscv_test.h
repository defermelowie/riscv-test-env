#ifndef _ENV_GSTAGE_VIRTUAL_SINGLE_CORE_H
#define _ENV_GSTAGE_VIRTUAL_SINGLE_CORE_H

#include "vmem_common.h"
#include "../p/riscv_test.h"

//-----------------------------------------------------------------------
// Data Section Macro
//-----------------------------------------------------------------------

#undef RVTEST_DATA_END
#define RVTEST_DATA_END                                         \
  /* "Stack" of size PGSIZE */                                  \
  .skip RISCV_PGSIZE; stack:;                                   \
  /* Page table data (empty) */                                 \
  .section ".data.pt";                                          \
  .align RISCV_L1_SPGSHIFT; /* Align pt section on superpage */ \
  spt: .zero (RISCV_PGSIZE * 9);                                \
  .align (RISCV_PGSHIFT + 2);                                   \
  /* FIXME: overlap between root page and the others */         \
  gpt: .zero (RISCV_PGSIZE * 3);


#endif
