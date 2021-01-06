#!/usr/bin/python3
"""Calculates the fewest number of operations needed to result in exactly n
H characters in the file.
"""


def minOperations(n):
    """
    Function that calculates the fewest number of operations

    Params:
        n (int): number to reach with min operations
    Returns:
        int
    """
    if n < 2 or not isinstance(n, int):
        return 0
    char = 1
    copy_paste = 2
    paste = 1
    operations = 0
    while char < n:
        if n % char == 0:
            paste = char
            char += paste
            operations += copy_paste
        else:
            char += paste
            paste = 1
            operations += paste
    return operations
