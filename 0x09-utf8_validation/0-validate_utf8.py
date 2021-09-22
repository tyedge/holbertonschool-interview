#!/usr/bin/python3
"""This module contains a function that determines if a given data set
represents a valid UTF-8 encoding"""


def validUTF8(data):
    """ This function determines if a given data set represents a valid UTF-8
encoding"""

    i = 0
    bites = 0

    while (i < len(data)):
        idx = data[i]

        if (bites == 0):
            if ((idx & 0xF0) == 0xF0 and (idx & 0xF8) == 0xF0):
                bites = 3
            elif ((idx & 0xE0) == 0xE0 and (idx & 0xF0) == 0xE0):
                bites = 2
            elif ((idx & 0xC0) == 0xC0 and (idx & 0xE0) == 0xC0):
                bites = 1
            elif ((idx | 0x7F) == 0x7F):
                bites = 0
            else:
                return False
        else:
            if((idx & 0x80) == 0x80 and (idx & 0xC0) == 0x80):
                bites -= 1
            else:
                return False
        i += 1

    return bites == 0
