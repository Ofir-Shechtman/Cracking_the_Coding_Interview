#Cracking the Coding Interview
#Arrays & Strings

#1.1
is_Unique = lambda string: len(set(string)) == len(string)

def is_Unique(string):
    hist= [False]*128
    for c in string:
        if hist[ord(c)]:
            return False
        hist[ord(c)]=True
    return True
