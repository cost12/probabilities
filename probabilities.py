import math
import sys

def binomial_prob(p:float, n:int, k:int=1) -> float:
    """
    p: probability of event happening
    n: number of times event has a chance to occur
    k: number of times event occurs

    return: probability of event with probability p happening k times in n tries 
    """
    if (p > 1 or p < 0 or n < 0 or k < 0): return -1
    if (k > n):  return 0
    if (k == 0): return 1

    return math.comb(n, k) * math.pow(p, k)*math.pow(1-p, n-k)

def cumulative_prob(p:float, n:int, k:int=1) -> float:
    """
    p: probability of event happening
    n: number of times event has a chance to occur
    k: number of times event occurs

    return: probability of event with probability p happening at least k times in n tries 
    """
    if (p > 1 or p < 0 or n < 0 or k < 0): return -1
    if (k > n):  return 0
    if (k == 0): return 1

    return sum(binomial_prob(p,n,kstar) for kstar in range(k,n+1))

def validate_args(args:list[str]) -> tuple[list[str]|str,bool,bool]:
    cumulative = False
    if ('--atleast' in args):
        cumulative = True
        args.remove('--atleast')
    valid = True
    if len(args) >= 2:
        try:
            args[0] = float(args[0])
            args[1] = int(args[1])
        except ValueError:
            valid = False
    else:
        valid = False
    if len(args) == 3:
        try:
            args[2] = int(args[2])
        except ValueError:
            valid = False
    if len(args) > 3:
        valid = False

    if not valid:
        args = "Error: expected p (float), n (int), k (optional,int) as arguments\nError: expected --atleast (optional) as an optional flag"
    return args, valid, cumulative

def main(args:list[str]):
    args, valid, cumulative = validate_args(args)
    if valid:
        if cumulative:
            print(f'{cumulative_prob(*args)*100:.3f}%')
        else:
            print(f'{binomial_prob(*args)*100:.3f}%')
    else:
        print(args)

if __name__=='__main__':
    main(sys.argv[1:])