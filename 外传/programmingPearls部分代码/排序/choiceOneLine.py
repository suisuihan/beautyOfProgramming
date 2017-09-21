#!/usr/bin/env python
#coding: utf-8
import random

def random_get_line(file_name):
    index = 1
    choice = ''
    choice_index = 0
    with open(file_name, 'r') as rf:
        for line in rf:
            if  random.randint(1, index) % (index + 1) == 1:
                choice = line
                choice_index = index
            index += 1
    print("index is %d" % choice_index)
    print("line is [%s]" % choice)

if __name__ == "__main__":
    random_get_line("choiceOneLine.py")
