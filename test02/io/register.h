#ifndef REGISTER_H
#define REGISTER_H

unsigned long long read_currentel(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, CurrentEL" : "=r"(v));
    return v;
}

unsigned long long read_midr_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, MIDR_EL1" : "=r"(v));
    return v;
}

unsigned long long read_mpidr_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, MPIDR_EL1" : "=r"(v));
    return v;
}

unsigned long long read_id_aa64mmfr0_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, ID_AA64MMFR0_EL1" : "=r"(v));
    return v;
}

unsigned long long read_sctlr_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, SCTLR_EL1" : "=r"(v));
    return v;
}

unsigned long long read_tcr_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, TCR_EL1" : "=r"(v));
    return v;
}

unsigned long long read_ttbr0_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, TTBR0_EL1" : "=r"(v));
    return v;
}

unsigned long long read_ttbr1_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, TTBR1_EL1" : "=r"(v));
    return v;
}

unsigned long long read_mair_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, MAIR_EL1" : "=r"(v));
    return v;
}

unsigned long long read_vbar_el1(void)
{
    unsigned long long v;
    __asm__ volatile("mrs %0, VBAR_EL1" : "=r"(v));
    return v;
}

#endif
