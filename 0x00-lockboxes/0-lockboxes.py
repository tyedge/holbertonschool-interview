#!/usr/bin/python3
"""This function determines if all boxes can be opened"""


def canUnlockAll(boxes):
    """This function determines if all locked boxes can be opened"""

    org = [box for box in range(len(boxes))]
    lckd = [0]

    if len(boxes) == 1:
        return True

    for enum, unlckd in enumerate(boxes):
        for key in boxes[enum]:
            if key < len(boxes):
                if key not in lckd and key != enum:
                    lckd.append(key)
            else:
                break

    if len(lckd) != len(set(org)):
        return False

    return True
