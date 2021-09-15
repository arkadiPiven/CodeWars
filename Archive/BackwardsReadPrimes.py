def isPrime(a, numbers, stop ):
	if a <= stop:
		if numbers[a] == -1:
			return False
		return True
	for x in range(2,a):
		if a % x == 0:
			return False
	return True

def sieve(numbers, stop):
	p = 2
	i = 2
	while True:
		flag = False	
		while p*i <= stop:
			numbers[p*i] = -1
			i = i + 1
		for x in range(p + 1, stop + 1):
			if numbers[x] != -1:
				p = x
				i = 2
				flag = True
				break
		if flag:
			continue
		break


def backwards_prime(start, stop):
	numbers = [0]*(stop + 1)
	sieve(numbers, stop)
	ret = []
	for x in range(start, stop + 1):
		if numbers[x] == -1:
			continue
		i = str(x)
		a = i[::-1]
		if int(a) == x:
			continue
		if isPrime(int(a), numbers, stop):
			ret.append(x)
	return ret



print(backwards_prime(2, 100))
