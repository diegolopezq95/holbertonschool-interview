#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics
"""

import shlex
import sys

code_list = ["200", "301", "400", "401", "403", "404", "405", "500"]
value_list = [0, 0, 0, 0, 0, 0, 0, 0]
sum_size = 0
count = 0

try:
    for input_line in sys.stdin:
        line_parts = shlex.split(input_line)
        if len(line_parts) > 2:
            status = line_parts[-2]
            size = line_parts[-1]
            sum_size += int(size)
            for i in range(len(code_list)):
                if code_list[i] == status:
                    value_list[i] += 1
            count += 1
            if count >= 10:
                print("File size: {}".format(sum_size))
                for i in range(len(code_list)):
                    if value_list[i] > 0:
                        print("{}: {}".format(code_list[i], value_list[i]))
                count = 0
except:
    pass
finally:
    print("File size: {}".format(sum_size))
    for i in range(len(code_list)):
        if value_list[i] > 0:
            print("{}: {}".format(code_list[i], value_list[i]))
    count = 0
