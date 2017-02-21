#!/usr/bin/env python3

def _merge(x, p, q, r):

    # Construct bucket arrays with lhs + rhs values
    lhs = x[p:q + 1]
    rhs = x[q + 1:r + 1]

    i, j = 0, 0
    k = p

    while i < len(lhs) and j < len(rhs):
        if lhs[i] <= rhs[j]:
            x[k], k = lhs[i], k + 1
            i = i + 1
        else:
            x[k], k = rhs[j], k + 1
            j = j + 1

    while i < len(lhs):
        x[k], k = lhs[i], k + 1
        i = i + 1

    while j < len(rhs):
        x[k], k = rhs[j], k + 1
        j = j + 1

def _divide(x, p, r):
    if p < r: # end >= beginning; all done

        q = int((p + r) / 2)
        
        _divide(x, p, q)
        _divide(x, q + 1, r)

        _merge(x, p, q, r)

def merge_sort(x):
    _divide(x, 0, len(x) - 1)
    return x


