.text	
.globl main
#ass: $t1=mem[0],$s0=x
main:
ori $t1,$zero,0x1001 
sll $t1,$t1,16
lw $s0,0($t1) #x=mem[1]
slt $t0,$s0,$zero #x<0
bne $t0,$zero,true 
sw  $s0,0($t1) #x=$0
true:
abs $s0,$s0 #$s0=|x|
sw  $s0,0($t1) #x=$0
.data
x: .word -2