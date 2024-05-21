## 
AC=arm-none-eabi-gcc 

LN = -T stm32f401cc_linkerscript.ld -nostdlib 

## first rule to generate main.o 
## to use dependencey use $^
## to use rule name  $@
	 

main.o:main.c
	 $(AC) -c $^ -o $@

mrcc.o:MRCC_Program.c
	$(AC) -c $^ -o $@
	
mgpio.o:MGPIO_Program.c 
	$(AC) -c $^ -o $@
	
stm32f401.o:stm401f_startupcode.c
	$(AC) -c $^ -o $@
	
file.elf:
	${AC} *.o ${LN} -o file.elf
file.map:
	${AC} *.o ${LN}   -Wl,-Map=file.map
symbol_table:
	arm-none-eabi-nm file.elf >Symbol.txt





	
	
all:main.o mrcc.o  mgpio.o  stm32f401.o file.elf file.map

clean:
	rm -rf  *.o file.elf file.map
