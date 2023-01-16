.text
.globl main
main:
#ass: &t1=mem[0],$s0=mem[1],$s1=mem[2],$s2=$s0+$s1
ori $t1,$zero,0x1001 
sll $t1,$t1,16
lw $s0,0($t1) #$s0=mem[1]
lw $s1,4($t1)#$s1=mem[2]
add $s2,$s1,$s0 #$s2=$s0+$s1
lw $s0,8($t1)#$s0=mem[3]
add $s2,$s2,$s0 #$s2=$s2+$s0
lw $s1,12($t1)#$s1=mem[4]
add $s2,$s2,$s1#$s2=$s2+$s1
sw  $s2,16($t1) #$soma=$s2
.data
x1: .word 15
x2: .word 25
x3: .word 13
x4: .word 17
soma: .word -1
