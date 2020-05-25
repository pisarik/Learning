import numpy as np
from manimlib.imports import *
from manimlib.mobject import geometry as mg
from manimlib.constants import COLOR_MAP as mc


class MoreShapes(Scene):
    def construct(self):
        circle = mg.Circle(color=mc['PURPLE_A'])
        square = mg.Square(fill_color=mc['GOLD_B'], fill_opacity=1,
                           color=mc['GOLD_A'])
        square.move_to(UP + LEFT)
        circle.surround(square)
        rectangle = mg.Rectangle(height=2, width=3)
        ellipse = mg.Ellipse(width=3, height=1, color=RED)
        ellipse.shift(2*DOWN + 2*RIGHT)
        pointer = mg.CurvedArrow(2*RIGHT, 5*RIGHT, color=mc['MAROON_C'])
        arrow = mg.Arrow(LEFT, UP)
        arrow.next_to(circle, DOWN+LEFT)
        rectangle.next_to(arrow, DOWN+LEFT)
        ring = mg.Annulus(inner_radius=.5, outer_radius=1, color=BLUE)
        ring.next_to(ellipse, RIGHT)

        self.add(pointer)
        self.play(FadeIn(square))
        self.play(Rotating(square), FadeIn(circle))
        self.play(GrowArrow(arrow))
        self.play(GrowFromCenter(rectangle),
                  GrowFromCenter(ellipse),
                  GrowFromCenter(ring))
