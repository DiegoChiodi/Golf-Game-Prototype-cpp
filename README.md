SDL dependences (mixer, sound, primative) extensions

Compile command in Shifiting-Greens path:
g++ *.cpp -o game.exe \
$(sdl2-config --cflags --libs) \
-lSDL2_image -lSDL2_mixer -lSDL2_gfx \
-mwindows

execute command:
./game
