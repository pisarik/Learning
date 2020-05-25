import numpy as np
from manimlib.imports import *
from manimlib.mobject import geometry as mg
from manimlib.constants import COLOR_MAP as mc


class AddingText(Scene):

    def construct(self):
        my_first_text = TextMobject('Writing with Main is fun')
        second_line = TextMobject('and easy to do!')
        second_line.next_to(my_first_text, DOWN)
        third_line = TextMobject('for me and you!')
        third_line.next_to(my_first_text, DOWN)

        self.add(my_first_text, second_line)
        self.wait(2)
        self.play(Transform(second_line, third_line))
        self.wait(2)
        second_line.shift(3*DOWN)
        self.play(ApplyMethod(my_first_text.shift, 3*UP))
