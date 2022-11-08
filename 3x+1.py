def col(x):return(((x%2==0)*(x/2))+(((x%2!=0)*((x*3)+1))))
def is_prime(n):
    if n <= 3:
        return n > 1
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    counter = 0
    while i ** 2 <= n:
        if counter >= 10*int(round(1000*((n**(1/1000))-1))):
          break
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
        counter +=1
    return True
while True:
    try:
        i = int(input(':'))
        c = 0
        maximum = 0
        maximumc = 0
        numprimes=0
        primes=[]
        uniqueprimes=[]
        print(i)
        while i!=4:
            if(is_prime(i)):
                primes.append(int(i))
                
            i = col(i)
            print(int(i))
            c+=1
            if(i>maximum):
                maximum = i
                maximumc = c
        for j in range(2):
            if(is_prime(i)):
                primes.append(int(i))
            i = col(i)
            print(int(i))
            c+=1
            if(i>maximum):
                maximum = i
                maximumc = c
        print('\nLength: {}\nThe largest number was {} on step {}\nThere were {} primes in the sequence: {}\n'.format(c,int(maximum),maximumc,len(primes),str(sorted(primes, reverse=True))))
    except:pass