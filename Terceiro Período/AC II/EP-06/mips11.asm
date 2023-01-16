.text	
.globl main
main:
#ass: &t1=mem[0],$s1=mem[1],$s=mem[2]
# x=$s2, z=$s3
ori $t1,$zero,0x1001 
sll $t1,$t1,16
lw $s0,0($t1) #x=mem[1]
lw $s1,4($t1) #z=mem[2]
add $s2,$s0,$s1 #$s2=x+z
sub $s3,$s0,$s1 #$s3=x-y
add $s3,$s3,$s2 #$s3=x-y+(x+z)
sw  $s3,8($t1) #y=$s3
.data
x: .word 100000
z: .word 200000
y: .word 0