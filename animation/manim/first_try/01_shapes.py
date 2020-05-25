import numpy as np
from manimlib.imports import *
from manimlib.mobject import geometry as mg


class Shapes(Scene):
    def construct(self):
        circle = Circle()
        square = Square()
        line = Line(np.array([3, 0, 0]), np.array([5, 0, 0]))
        triangle = Polygon(np.array([0, 0, 0]),
                           np.array([1, 1, 0]),
                           np.array([1, -1, 0]))
        self.play(ShowCreation(circle))
        self.play(FadeOut(circle))
        self.add(line)
        self.play(GrowFromCenter(square))
        self.play(Transform(square, triangle))
