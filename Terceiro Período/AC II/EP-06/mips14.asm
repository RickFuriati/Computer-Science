.text	
.globl main
#ass: $t1=mem[0],$s0=x
main:
ori $t1,$zero,0x1001 
sll $t1,$t1,16
lw $s0,0($t1) #x=mem[0]
addi $s1,$zero,2 #$s1=2
div $t0,$s0,$s1 #$t0=$s0/$s1
mfhi $t0#$t0=$s0%$s1
sw  $t0,4($t1) #mem[1]=$t0
.data
x: .word 3
