#!/usr/bin/python3
"""This module contains a script that reads stdin line by line and computes
metrics"""

import sys

total = 0
code_dic = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
            "405": 0, "500": 0}

try:
    for num, line in enumerate(sys.stdin, start=1):
        parsed = line.split()
        if len(parsed) == 9:
            total += eval(parsed[8])
            if parsed[7] in code_dic:
                code_dic[parsed[7]] += 1
            if num % 10 == 0:
                print('File size: {}'.format(total))
                scd = sorted(code_dic.items())
                for k, v in scd:
                    if v > 0:
                        print('{}: {}'.format(k, v))
except KeyboardInterrupt:
    print('File size: {}'.format(total))
    scd = sorted(code_dic.items())
    for k, v in scd:
        if v > 0:
            print('{}: {}'.format(k, v))
    raise
