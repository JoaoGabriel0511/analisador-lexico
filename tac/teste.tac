.table
int i_main_VARIABLE[] = {0, 0}
int j_main_VARIABLE[] = {0, 0}
.code
jump main
main:
mov $2, &i_main_VARIABLE
mov $2[0], 12
mov $2[1], 24
mov $2, &j_main_VARIABLE
mov $3, &i_main_VARIABLE
mov $2[0], $3[0]
mov $2[1], $3[1]
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
mov $2, &j_main_VARIABLE
mov $2, $2[0]
print '<'
print $2
print ','
mov $2, &j_main_VARIABLE
mov $2, $2[1]
print $2
print '>'
println
