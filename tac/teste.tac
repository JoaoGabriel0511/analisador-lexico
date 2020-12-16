.table
int a_main_VARIABLE
.code
jump main
main:
mov a_main_VARIABLE, 1
brz L0, a_main_VARIABLE
brz L1, 1
print 't'
print 'r'
print 'u'
print 'e'
jump L2
L1:
print 'f'
print 'a'
print 'l'
print 's'
print 'e'
L2:
println
L0:
println
