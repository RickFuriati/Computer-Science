#Programa 02
#x = 3
#y = 4 
#z = ( 15*x + 67*y)*4


.text
.globl main
main:
#Associações 
# x-> $s0, y-> $s1, z-> $s2
addi $s0, $zero,3 #x=1
addi $s1, $zero,4 #y=1
add $t1, $zero, $s0 #t1=x

add $s0,$s0,$s0 #x=x+x (x=3+3 --> 6)
add $s0,$s0,$s0 #x=x+x (x=6+6 --> 12 )
add $s0,$s0,$s0 #x=x+x (x=12+12 --> 24)
add $s0,$s0,$s0 #x=x+x (x=24+24--> 48)
sub $s0,$s0,$t1 #x=x-t0  (x=48-3 -->45)

add $s1,$s1,$s1 #y=y+y (y=4+4 --> 8)
add $s1,$s1,$s1 #y=y+y (y=8+8 --> 16)
add $s1,$s1,$s1 #y=y+y (y=16+16 --> 32)
add $s1,$s1,$s1 #y=y+y (y=32+32 --> 64)
add $s1,$s1,$s1 #y=y+y (y=64+64 --> 128)
add $s1,$s1,$s1 #y=y+y (y=128+128 --> 256)


addi $s1,$s1,12 #y=y+12 (y=256+12 --> 268)

add $s2, $s0, $s1 #y =x+y (15*x + 67*y)

add $s2, $s2, $s2 #z=z+z (dobro de z)
add $s2, $s2, $s2 #z=z+z (quadruplo de z)




.data 