.table
int a_main_VARIABLE
.code
jump main
main:
and $0, 0, 1
mov a_main_VARIABLE, $0
brz L0, a_main_VARIABLE
print 't'
print 'r'
print 'u'
print 'e'
jump L1
L0:
print 'f'
print 'a'
print 'l'
print 's'
print 'e'
L1:
println
