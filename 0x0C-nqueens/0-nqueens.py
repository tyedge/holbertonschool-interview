#!/usr/bin/python3
"""This program prints every possible solution to the N queens problem for
a given value of N"""

import sys


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

        if type(int(sys.argv[1])) is not int:
            print("N must be a number")
            exit(1)
        if (int(sys.argv[1])) < 4:
            print("N must be at least 4")
            exit(0)

    N = int(sys.argv[1])
    onboard = []

    def nsolver(n):
        """This function finds and prints solutions to the N queens problem"""
        for i in range(N):
            if onboard == []:
                onboard.append([n, i])
                nsolver(n + 1)
                onboard.pop()
            else:
                chk = [i == j[1] or abs(n - j[0]) == abs(i - j[1]) for j in onboard]
                if not any(chk):
                    onboard.append([n, i])
                    if n == N - 1:
                        print(onboard)
                    else:
                        nsolver(n + 1)
                    onboard.pop()

nsolver(0)
