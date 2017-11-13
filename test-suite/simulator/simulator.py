#! /usr/bin/python

import sys

description = sys.argv[1]
test = sys.argv[2]


def BuildGraph(description):
    input = open('description', 'r')

    lines = [x.strip() for x in input.readlines()]

    temp = lines[0]
    numStates = temp[temp.find(':'):]

    temp = lines[1]
    accept = temp[temp.find(':'):]

    temp = lines[3]
    alphabet = temp[temp.find(':'):]

    accept = [int(i) for i in accept.split()]
    alphabet = [int(i) for i in alphabet.split()]

    
