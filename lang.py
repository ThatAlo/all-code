program = '$foot=5;print(foot);$egg=2;print(egg);'
splitprogram = program.split(';')
tokens=['$','print("','print(#','print(']

vars={}

for i in splitprogram:
    for j in tokens:
        if j in i:
            if(j=='$'):
                vars[(i.strip('$').split('='))[0]]=(i.strip('$').split('='))[1]
            if(j=='print("'):
                print(i.strip(j).strip('")'))
            if(j=='print(#'):
                print(i.strip(j).strip(')'))
            if(j=='print('):
                print(vars[i.strip(j).strip(')')])

