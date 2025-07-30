# Golf Game Prototype (C++)

This repository contains a **top-down golf game prototype** developed entirely in **modern C++**, applying the **object-oriented programming (OOP)** paradigm. The project was built from scratch using **SDL2** and demonstrates several advanced programming concepts and techniques.

## 🎯 Purpose

This project serves as a study and experimentation environment for:
- Game engine development fundamentals
- Advanced C++ techniques
- Real-time systems programming
- Manual memory management
- Physics simulations

## 🧠 Key Concepts Applied

- Object-Oriented Programming:
  - Encapsulation
  - Inheritance
  - Polymorphism
- Custom rendering pipeline using SDL2
- Input handling
- Audio playback
- Manual memory control and optimization
- 2D physics and trajectory simulation
- Custom-built game loop and timing logic

## 🛠️ Technologies Used

- **Language:** C++17
- **Graphics & Audio:** SDL2
- **Build Environment:** MSYS2 (MinGW)
- **Editor:** Visual Studio Code
- **Platform:** Windows
## 🚀 How to Run

1. Clone the repository:
git clone https://github.com/DiegoChiodi/Golf-Game-Prototype-cpp.git
Make sure you have MSYS2 and SDL2 installed.

2. Install bibliotec

pacman -S mingw-w64-ucrt-x86_64-SDL2

pacman -S mingw-w64-ucrt-x86_64-SDL2_image
pacman -S mingw-w64-ucrt-x86_64-SDL2_mixer
pacman -S mingw-w64-ucrt-x86_64-SDL2_ttf
pacman -S mingw-w64-ucrt-x86_64-SDL mingw-w64-ucrt-x86_64-SDL_gfx

Compile the project using your C++17-compatible toolchain:

compilator command: g++ -std=c++17 -Iinclude -Llib src/**/*.cpp -lSDL2 -lSDL2_mixer -o golf_game
Run the executable:
./golf_game
💡 If needed, adjust include paths depending on your SDL2 installation.

🧾 Learning Outcomes
This prototype helped me develop solid skills in:

Building a simple 2D game engine from scratch

Deep understanding of object-oriented design

Complex math and physics for gameplay

Real-time rendering and performance tuning

Using SDL2 effectively for multimedia applications

📌 Status
This is a work-in-progress prototype. I'm continuously adding new features, refining the engine, and experimenting with new systems (e.g., shadows, bouncing physics, modular design).
