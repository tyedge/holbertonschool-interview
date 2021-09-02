#!/usr/bin/python3
"""This module contains a script that reads stdin line by line and computes
metrics"""

import sys

total = 0
code_dic = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
            "405": 0, "500": 0}


def sort_n_print(size, dic):
    """This function sorts the dictionary and prints total size and codes"""
    print("File size: {}".format(size))
    ascend = sorted(dic.items())
    for key, value in ascend:
        if value > 0:
            print("{}: {}".format(key, value))


try:
    for num, line in enumerate(sys.stdin, start=1):
        parsed = line.split()
        if len(parsed) == 9:
            total += eval(parsed[8])
            if parsed[7] in code_dic:
                code_dic[parsed[7]] += 1
            if num % 10 == 0:
                sort_n_print(total, code_dic)
    sort_n_print(total, code_dic)
    
except KeyboardInterrupt:
    sort_n_print(total, code_dic)
    raise
