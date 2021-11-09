def split():
    lines = []
    while True:
        line = input()
        if line:
            lines.append(line)
        else:
            break
    e = '\n'.join(lines)
    e_edit = e.replace('/n',' ')
    list_e = e_edit.split()
    sc = ord(list_e[0])
    ec = ord(list_e[1])
    ci = []
    cp = []
    for i in range(3,len(list_e),2):
        ci = ci + [ord(list_e[i])-65]
    for i in range(4,len(list_e),2):
        cp = cp + [list_e[i]]
    
#    print('e: ',end='')
#    print/(list_e)
#    print('sc: ',end='')
#    print(sc)
#    print('ec: ',end='')
#    print(ec)
#    print('ci: ',end='')
#    print(ci)
#    print('cp: ',end='')
#    print(cp)
    return(ec,sc,ci,cp)
