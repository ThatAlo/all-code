def is_prime(n):
    if n <= 3:
        return n > 1
    if n % 2 == 0 or n % 3 == 0:
        return(False)
    i = 5
    counter = 0
    while i ** 2 <= n:
        if counter >= 10*int(round(1000*((n**(1/1000))-1))):
            break
        if n % i == 0 or n % (i + 2) == 0:
            return(False)
        i += 6
        counter +=1
    return True
while True:
    try:
        print(is_prime(int(input(':'))))
    except:
        print('Invalid entry')