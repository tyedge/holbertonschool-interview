#!/usr/bin/python3
"""This module contains a function that calculates the fewest number of
operations needed to result in exactly n H characters in the file."""


def minOperations(x):
    """This function finds minimum number of operations to print a letter a
specified number of times"""

    if x <= 1:
        return 0
    minops = 0
    i = 2
    while i < x + 1:
        while (x % i == 0):
            minops += i
            x /= i
        i += 1
    return minops
