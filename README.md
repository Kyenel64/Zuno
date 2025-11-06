# Zuno
### A 2D, Lua-based game engine. <br>
### Lightweight, code-only, live-reloading

(Zuno is still in development. You can't create a game with Zuno yet. Sorry!)

[![Build and Test](https://github.com/Kyenel64/Zuno/actions/workflows/build-and-test.yml/badge.svg)](https://github.com/Kyenel64/Zuno/actions/workflows/build-and-test.yml)

What is Zuno?
---
### Zuno is a game engine.
Zuno isn't a framework, nor a library. It is a game engine that handles all the heavy lifting, so you as a game developer can focus on creating your game.

### Zuno is simple.
Zuno is designed simplicity-first. With Lua scripting and straightforward project configs, creating your game with Zuno is super easy.

### Zuno is familiar
Zuno's API is designed similar to Unity's API so if you've worked previously with Unity, transitioning to Zuno is easy.

### Zuno is easy to edit
Zuno's live reloading feature allows you to easily edit your game code and see it update live on screen.

Documentation
---
Zuno's documentation is coming soon!

Getting Started
---
### Building Zuno
Install cmake if you haven't already. <br>
Clone the repository and run: <br>
```
$ cmake -B build -S .
$ cmake --build build
```
This will build the Zuno executable in `build/`

### Running Zuno
Go to your build folder. <br>
Run Zuno with `./Zuno /pathToMain.lua` <br>
Zuno requires an entrypoint lua file as the first argument. <br>
Zuno comes with a sample.lua in the sample folder. In your build folder, run `./Zuno ../sample/sample.lua`

Example
---
Here is a sample Zuno lua file. It can also be found in the sample directory of the project as `sample.lua`, so you can run it.
```lua
function zuno.load()
    print("Zuno game loaded!")
end

function zuno.update(dt)
end

function zuno.draw()
end

function zuno.key_pressed(key)
    print("Key pressed: ", key)
end

function zuno.on_quit()
    print("Zuno game quit!")
end

```
