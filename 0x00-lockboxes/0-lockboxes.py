#!/usr/bin/python3
"""This function determines if boxes can be opened"""


def canUnlockAll(boxes):
    """This function determines if all locked boxes can be opened"""

    original = [box for box in range(len(boxes))]
    opened = [0]

    if len(boxes) == 1:
        return True

    for enum, unpoened in enumerate(boxes):
        for key in boxes[enum]:
            if key < len(boxes):
                if key not in opened and key != enum:
                    opened.append(key)
            else:
                break

    if len(opened) != len(set(original)):
        return False

    return True
