.text
.globl main
main:
#$s0=x, $s1=y, $s2=k
ori $t0, $zero, 0x1001 # mem[0]=0000 1001
sll $t0, $t0, 16 # mem[0]=1001 0000

lw $s0, 0($t0) # x=mem[0]
lw $s1, 4($t0) # y=mem[1]

addi $t1, $zero, 0 # i=0

do:
add $s2, $s2, $s0 # k=k+x
addi $t1, $t1, 1 #i=i+1
bne $t1, $s1, do # while (i!= y)
sw $s2, 8($t0) # y=mem[2]

.data 
x: .word 2
y: .word 5
k: .word -1

