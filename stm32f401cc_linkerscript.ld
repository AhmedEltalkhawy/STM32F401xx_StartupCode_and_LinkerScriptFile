
/* ENTRY point  of Application to be run */
ENTRY(Reset_Handler)
MEMORY
{
	/* make flash only read */
	FLASH(rx) : ORIGIN = 0x08000000 ,LENGTH = 256k 
	SRAM(rwx) : ORIGIN = 0x20000000 ,LENGTH = 20k
}
SECTIONS
{
	/*.isr_section :
	{
	 *(.isr_vector)
	}>SRAM AT >FLASH*/
	.text :
	{
	 s_text = . ;
	 *(.isr_vector) 
	 *(.text)
	 *(.rodata)
	 e_text = . ;
	}>FLASH AT >FLASH
	.data :
	{
	 s_data = . ;
	
	 *(.data)
	 . = ALIGN(4) ;
	 e_data = . ;
	}>SRAM AT >FLASH
	.bss :
	{
	 s_bss = . ;
	 *(.bss)
	 e_bss = . ;
	}>SRAM AT >SRAM
}