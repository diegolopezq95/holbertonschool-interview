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
    if boxes == [[]] or boxes == []:
        return True
    box_list = [x for x in range(len(boxes))]
    jump = [0]
    for idx in jump:
        for key in boxes[idx]:
            if key not in jump and key in box_list:
                jump.append(key)
                print(jump)
    return True if len(jump) == len(boxes) else False
