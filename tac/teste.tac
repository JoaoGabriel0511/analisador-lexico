.table
int i_main_VARIABLE[] = {0, 0}
.code
jump main
main:
mov $2, &i_main_VARIABLE
mov $2[0], $0
mov $2[1], $1
mov $2, &i_main_VARIABLE
mov $2, $2[0]
print '<'
print $2
print ','
mov $2, &i_main_VARIABLE
mov $2, $2[1]
print $2
print '>'
println
