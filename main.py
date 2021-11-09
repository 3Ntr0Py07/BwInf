import split
import check
ec,sc,ci,cp = split.split()

print('sc: ',end='')
print(sc)
print('ec: ',end='')
print(ec)
print('ci: ',end='')
print(ci)	
print('cp: ',end='')
print(cp)

for index in range(sc,ec):
  m,mc,mp=check.check(ci,cp,index)
  print(m)
  print(chr(mc+65))
  print(mp) 