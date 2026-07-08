#include "register.h"

void memory_info_dump(void)
{
    unsigned long long value;

    uart_puts("\r\n");
    uart_puts("========================================\r\n");
    uart_puts("         RingNova Memory Info\r\n");
    uart_puts("========================================\r\n");

    value = read_currentel();
    uart_printf("CurrentEL            : 0x%016llX\r\n", value);

    value = read_midr_el1();
    uart_printf("MIDR_EL1             : 0x%016llX\r\n", value);

    value = read_mpidr_el1();
    uart_printf("MPIDR_EL1            : 0x%016llX\r\n", value);

    value = read_id_aa64mmfr0_el1();
    uart_printf("ID_AA64MMFR0_EL1     : 0x%016llX\r\n", value);

    value = read_sctlr_el1();
    uart_printf("SCTLR_EL1            : 0x%016llX\r\n", value);

    value = read_tcr_el1();
    uart_printf("TCR_EL1              : 0x%016llX\r\n", value);

    value = read_ttbr0_el1();
    uart_printf("TTBR0_EL1            : 0x%016llX\r\n", value);

    value = read_ttbr1_el1();
    uart_printf("TTBR1_EL1            : 0x%016llX\r\n", value);

    value = read_mair_el1();
    uart_printf("MAIR_EL1             : 0x%016llX\r\n", value);

    value = read_vbar_el1();
    uart_printf("VBAR_EL1             : 0x%016llX\r\n", value);
}
