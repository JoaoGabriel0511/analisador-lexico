.table
int a_main_VARIABLE
.code
jump main
main:
mov a_main_VARIABLE, 1
or $0, 0, a_main_VARIABLE
brz L0, $0
brz L2, 1
print 't'
print 'r'
print 'u'
print 'e'
jump L3
L2:
print 'f'
print 'a'
print 'l'
print 's'
print 'e'
L3:
println
jump L1
L0:
brz L4, 0
print 't'
print 'r'
print 'u'
print 'e'
jump L5
L4:
print 'f'
print 'a'
print 'l'
print 's'
print 'e'
L5:
println
L1:
println
