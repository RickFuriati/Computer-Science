.text	
.globl main
main:
#ass: &t1=mem[0],$s1=mem[1],$s=mem[2]
# x=$s1, z=$s2,y=4
ori $t1,$zero,0x1001 
sll $t1,$t1,16
lw $s0,0($t1) #x=mem[1]
lw $s1,4($t1) #z=mem[2]

sll $s2,$s0,7 #x=128x
sub $s2,$s2,$s0 #x=128x-x
sll $s3,$s1,6 #z=64z
add $s3,$s3,$s1 #z=64z+z
sub $s4,$s2,$s3 #y=x-z
addi $s4,$s4,1 #y=y+1
sw  $s4,8($t1) #y=$s2
.data
x: .word 5
z: .word 7
y: .word 0 