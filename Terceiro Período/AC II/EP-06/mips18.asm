
.text
.globl main
main:
#$s0=x, $s1=y, $s2=k, $t0=mem[0]
ori $t0, $zero, 0x1001 # mem[0] = 0000 1001
sll $t0, $t0, 16 # mem[0] = 1001 0000

lw $s0, 0($t0) # x = mem[0]
lw $s1, 4($t0) # y = mem[1]

addi $t1, $zero, 0 # i=0
addi $s2, $zero, 1 # k=1

do:

mult $s2, $s0 # k*x
mflo $s2 # k=mflo
addi $t1, $t1, 1 # i=i+1
bne $t1, $s1, do # while (i!=y)

sw $s2, 8($t0) # k = mem[2]
.data 
x: .word 3
y: .word 4
k: .word -1

