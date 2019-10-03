#Cracking the Coding Interview
#Arrays & Strings

#1.1
is_unique = lambda string: len(set(string)) == len(string)

#1.2
from collections import Counter
check_permutation = lambda s1, s2: Counter(s1)==Counter(s2)

#1.3
URLify = lambda s: '%20'.join(s.split(' '))
URLify = lambda s: s.rstrip().replace(' ', '%20')

#1.4
mod2 = lambda x: x%2
def palindrome_permutation(string):
    strip=string.lower().replace(' ', '')
    letter_sum= Counter(strip)
    total_list= map(mod2,letter_sum.values())
    return sum(total_list) <=1
