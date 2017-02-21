#!/usr/bin/env python3

def _pass(x, place):
    # Create 10 buckets for each digit
    bucket = [[] for e in range(10)]

    for v in x:
        idx = int(v / pow(10, place - 1) % 10)
        bucket[idx].append(v)

    i = 0
    for b in bucket:
        for v in b:
            x[i] = v
            i += 1

def radix_sort(x):
    N = len(str(max(x)))
    place = 1

    while place < N:
        _pass(x, place)
        place = place + 1

    return x

