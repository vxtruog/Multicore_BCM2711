MEMORY
{
    RAM : ORIGIN = 0x80000, LENGTH = 256M
}

SECTIONS
{
    .text (READONLY):
    {
        KEEP(*(.text.boot))
        *(.text)
        *(.text.*)
        *(.gnu.linkonce.t*)
    } > RAM :text

    PROVIDE(_data = .);

    .data :
    {
        . = ALIGN(8);
        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d*)
    } > RAM :data

    .bss :
    {
        . = ALIGN(8);
        __bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        __bss_end = .;
    } > RAM :bss

}

PHDRS
{
    text PT_LOAD FLAGS(5);
    data PT_LOAD FLAGS(6);
    bss PT_LOAD FLAGS(6);
}

__bss_size = (__bss_end - __bss_start) >> 3;