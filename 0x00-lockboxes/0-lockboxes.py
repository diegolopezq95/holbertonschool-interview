#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    Function that determines if all boxes can be opened

    Params:
        boxes (list): is a list of lists 

    Retorna:
        True if all boxes can be opened, else return False
    """
    jump = [0]
    for idx in jump:
        for key in boxes[idx]:
            if key not in jump:
                jump.append(key)
    return True if len(jump) == len(boxes) else False

