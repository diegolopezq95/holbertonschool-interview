#!/usr/bin/python3
"""0x00. Lockboxes
"""


def canUnlockAll(boxes):
    """
    Function that determines if all boxes can be opened

    Params:
        boxes (list): is a list of lists
    Retorna:
        True if all boxes can be opened, else return False
    """
    if boxes == [] or boxes == [[]]:
        return True
    box_list = [x for x in range(len(boxes))]
    jump = [0]
    for idx in jump:
        for key in boxes[idx]:
            if key > len(boxes) or key not in box_list:
                return False
            if key not in jump:
                jump.append(key)
    return True if len(jump) == len(boxes) else False
