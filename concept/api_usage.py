from spark import *

sweep = load_sound("rising_sweep")
logo = load_image("Logo")
logo.position = Position.centered
resize_proportional(logo, target_width=screen.width * .7)
tint(screen, color=Color.White)

@once(at=frame(0))
def start_music():
    start(sweep)

@sequence(starts_at=frame(0), lasts=seconds(3))
def fade_in(frame):
    logo.transparancy = max(1.0, frame.delta_t)


bang = load_sound("deep_bang")
logo_font = load_font("Arial")
title_text = logo_font.render("Some great game", size=72)

@once(at=second(3))
def display_title():
    start(bang)
    title_text.position = Position.south_of(logo, margin=title_text.height * .3)
    title_text.position.horizontal = Position.centered.horizontal
    tint(title_text, color=Color.Black)
    start(text_fade)

@sequence(lasts=seconds(2))
def text_fade(frame):
    text_title.transparency = min(0.0, 2.0 - frame.delta_t)
