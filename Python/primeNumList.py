#Sorting prime numbers in a list, mostly with the help of in-built functions.
#Time complecity is O(n*sqrt(n)), well at least faster than traditional method of finding primes.
import numpy as np
from math import sqrt

limit=int(input("Prime numbers upto: "))
y=[] #This list will contain prime numbers

#Generating a list of all numbers upto entered limits

x=np.arange(1,limit)

"""Lambda function takes x and returns 
True if the list containing multiples of passed x is 0.
Here, I have used list comprehension to do so."""

prime=lambda x: len([i for i in range(2,int(sqrt(x)+1)) if (x%i)==0])==0

#Filter out numbers from array x and print them as list

y=list(filter(prime,x))
print(y)