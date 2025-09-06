# What is Kruger?

Kruger is a *game engine* written in C++17 that uses the **ECS (Entity-Component-System)** architecture. This choice was made in order to make game creation and management dynamic, modular and easily scalable.<br>The project uses [Raylib]("https://github.com/raysan5/raylib") as a library for the graphical interface, rendering, audio and multiplatform support.

> Although the engine is intended to be multiplatform, it has not been tested on MacOS

## Project Philosophy

- **Open Source**: Kruger is free and open to anyone who wants to use, modify or contribute to it.
- **AI-Free**: the engine's development does not use AI-generated code. Everything is hand-written by developers to ensure full understanding and control of the project (and why not? Also to learn something new :P)

> It is possible that there are some "trivial" errors in the project. I still have a lot to learn, so if you have any criticism or information on how to improve the project, please write to me!

## Features

- **ECS System**: The game is structured into entities, components that define data and properties, and systems that operate on these components. This model allows for a modular and easily maintainable design.
- **Scene Management**: Kruger implements a scene system, which can be defined as game states (e.g. menus, levels) for smoother navigation and better game flow management.

## Dependencies
– Raylib [[License]("https://github.com/raysan5/raylib/blob/master/LICENSE")]: graphical interface, rendering, audio and multiplatform support

## Credits

- [raysan5]("https://github.com/raysan5"): obviously Ray, the creator of  [Raylib]("https://github.com/raysan5/raylib"), without this library the project would not exist.
- [FamineSource]("https://github.com/FamineSource"): Hey! That's me! I built the rest of the architecture that the engine uses.