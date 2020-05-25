import numpy as np
from manimlib.imports import *
from manimlib.mobject import geometry as mg
from manimlib.constants import COLOR_MAP as mc

class RotateAndHighlight(Scene):

    def construct(self):
        square = Square(side_length=5, fill_color=mc['YELLOW_C'],
                        fill_opacity=1)
        label = TextMobject('Text at an angle')
        label.bg = BackgroundRectangle(label, fill_opacity=1)
        label_group = VGroup(label.bg, label)  # Order matters
        label_group.rotate(TAU / 8)
        label2 = TextMobject('Boxed text', color=mc['BLACK'])
        label2.bg = SurroundingRectangle(label2, color=mc['BLUE_C'],
                                         fill_color=mc['RED_C'],
                                         fill_opacity=0.5)
        label2_group = VGroup(label2, label2.bg)
        label2_group.next_to(label_group, DOWN)
        label3 = TextMobject('Rainbow')
        label3.scale(2)
        label3.set_color_by_gradient(
            mc['RED_C'], mc['ORANGE'], mc['YELLOW_C'], mc['GREEN_C'],
            mc['BLUE_C'], mc['PURPLE_C']
        )
        label3.to_edge(DOWN)

        self.add(square)
        self.play(FadeIn(label_group))
        self.play(FadeIn(label2_group))
        self.play(FadeIn(label3))
