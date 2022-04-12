.data
	numarNoduri: .space 4 
	numarMuchii: .space 4
	matriceAdiacenta: .space 10000
	formatD: .asciz "%d"
	formatS: .asciz "%s"
	formatC: .asciz "%c"
	formatEndl: .asciz "\n"
	indexFor: .long 0
	nodStanga: .space 4
	nodDreapta: .space 4
	literaMuchie: .space 1

.text

dfs:


.global main

main:
	pushl $numarNoduri #citesc numarul de noduri
	pushl $formatD
	call scanf
	popl %ebx
	popl %ebx

	pushl $numarMuchii #citesc numarul de muchii
	pushl $formatD
	call scanf
	popl %ebx
	popl %ebx
	
	movl $0, indexFor 

for_citire_muchii:
	
	movl indexFor, %ecx
	cmp %ecx, numarMuchii
	je exit_for_citire_muchii

	pushl $nodStanga #citesc nodul de unde pleaca muchia
	pushl $formatD
	call scanf
	popl %ebx
	popl %ebx

	pushl $nodDreapta #citesc nodul unde se duce muchia
	pushl $formatD
	call scanf
	popl %ebx
	popl %ebx	

	pushl $literaMuchie #citesc litera de pe muchie
	pushl $formatC
	call scanf
	popl %ebx
	popl %ebx

	incl indexFor
	jmp for_citire_muchii
	
exit_for_citire_muchii:
	
	pushl $formatEndl
	call printf
	popl %ebx
	
	mov $1, %eax
	mov $0, %ebx
	int $0x80
