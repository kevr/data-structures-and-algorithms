#!/usr/bin/env python3

def _pass(x, position):
    # Create 10 buckets for each digit
    bucket = [[] for e in range(10)]

    # Divisor
    div = int(pow(10, position - 1))

    for v in x:
        idx = int(int(v / div) % 10)
        bucket[idx].append(v)

    i = 0
    for b in bucket:
        for v in b:
            x[i] = v
            i += 1

def radix_sort(x):
    N = len(str(max(x)))
    place = 1

    while place <= N:
        _pass(x, place)
        place = place + 1

    return x

L = [66, 33, 99, 666, 333, 431, 2346, 999]
print(radix_sort(L))

