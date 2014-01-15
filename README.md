YunNeo aka Learnometer aka #LoM
======

Adafruit Neopixels using the Arduino Yun

Supports Chelmsford Makerspace's BETT project for the Heppell Stand.

The idea is to light up two strips of Adafruit LED pixels with a percentage depending on a value sent from a webpage on an Internet device.

Uses 2 x Adafruit 50 pixel strips and one Arduino Yun.  Most of the code would probably work on any other Arduino, we just want network connectivity.

Front End/Web

Key dev - Richard/Makerspace

One Web page for each strip pair, accessible on a single IP address, multi-user.

Index page with links to each of the 4 strip pairs.  (Strip 1, Strip 2, Strip 3, Strip 4)

Data capture on form for each strip:

Field:Subject - maybe capture in a small DB somewhere?
Field:School - maybe capture in a small DB somewhere?
Title: Environment Data
Slider1: Temperature -> values: 10 degrees to 30 degrees. Outputs: 18 degrees +/- 2 degrees good, getting worse either way (out of 10)
Slider2: Noise level -> values 40dB - 85dB Output: Lower values better (gives highest score out of 10)
Slider3: Light level -> values: 10 - 1500 lumens (luX) Outputs: less than 400 bad, more than 400 good (scored out of 10)
Slider4: Was learning playful? Output 1(no) - 10 (very much so)
Slider5: Did I want to stop or keep going? Output: 1 (yes) - 10 (No I could go all day!)
Slider6: Was I stretched or coasting? Output: 1 (coasting) - 10 (stretched)
Slider7: How well am I doing in this subject do I think? Output 1(Grade E) - Output 10 (Grade A)

Need to do some aggregation of the above to finally output 3 values:

Objective values % out of 100 - 100 being the best (these are sliders 1 through 3)
Subjective values % out of 100 - 100 being the best (sliders 4 through 6)
Grade values % out of 100 E = 20% D = 40% C = 60% B = 80% A = 100%

Arduino strip development

Key Dev Tom

Each Arduino Yun runs 2 strips, we have 4 Yuns.

Strips all fill with white LEDS

Strip A - shows the averaged score of the Objective values x 10 as Red LEDS
Strip B - shows the averaged score of the Subjective values as Blue LEDS

Both strips flash LEDS that represent grade values so if you have an E none flash and if you have A they all flash (if that's not annoying!!)


