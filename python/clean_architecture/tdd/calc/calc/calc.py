# -*- coding: utf-8 -*-
from functools import reduce


class Calc:

    def add(self, *args):
        return sum(args)

    def sub(self, a, b):
        return a - b

    def mul(self, *args):
        if not all(args):
            raise ValueError
        return reduce(lambda x, y: x*y, args)

    def div(self, a, b):
        try:
            return a / b
        except ZeroDivisionError:
            return 'inf'

    def avg(self, it, lt=None, ut=None):
        _it = it[:]
        if lt is not None:
            _it = [x for x in _it if x >= lt]
        if ut is not None:
            _it = [x for x in _it if x <= ut]
        if not _it:
            return 0
        return sum(_it) / len(_it)
