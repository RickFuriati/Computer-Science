
.text
.globl main
main:
#ass $s0=x, $s1=y, $s2=z
ori $s0, $zero, 0x186a # x =186a
sll $s0, $s0, 8 # x = 0018 6a00
ori $s1, $zero, 0x1388 # y=1388
sll $s1, $s1, 4 # y = 0001 3880

ori $s2, $zero, 0x61a8 # y=61a8
sll $s2, $s2, 4 #y=0006 1a80
mult $s0, $s1 # x * y
mflo $t0 # t0 = cd65 0000
srl $t0, $t0, 16 # t0 = 0000 cd65

mfhi $t1 # t1 = 0000 001d
sll $t1, $t1, 16 # t1 = 001d 0000
add $t3, $t0, $t1 # t3 = t0 + t1 -> 001d cd65
sll $t3, $t3, 8 # t3 / 256

div $t3, $s2 # (x*y) / z
mflo $s3 # z = 0000 04e2
sll $s3, $s3, 8 # s3 * 256

