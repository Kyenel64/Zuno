# Zuno
### A "Ground Up" game engine in Lua. (In development)
Ever have to disable a bunch of unneeded engine features that slowed down your game? <br/>
Zuno lets you start from the <strong>Ground Up</strong>. Start with a simple, code-only 2D engine and add modules to "build" your engine all the way up to a 3D, editor-integrated, node-based scripting engine. <br/>

[![Build and Test](https://github.com/Kyenel64/Zuno/actions/workflows/build-and-test.yml/badge.svg)](https://github.com/Kyenel64/Zuno/actions/workflows/build-and-test.yml)

What is Zuno?
---
### Zuno is a game engine.
Zuno isn't a framework, nor a library. It is a game engine that handles all the heavy lifting, so you as a game developer can focus on creating your game without worrying about scene management, file management, etc.

### Zuno is simple.
Zuno gives you a super simple, code-only, 2D engine to begin with. Its up to you to choose which modules to install that fits the needs of you and your game. <br/>
Lua is also a simple and effecient scripting language. If you are not confidend with coding, Zuno also provides a visual scripting module you can install to your engine.

### Zuno is familiar
Zuno is ECS-based, making the API similar to other engines with the same architecture. Developers transitioning from other ECS-based engines may find it easy to learn the API.

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
Zuno comes with a sample.lua in the root file. In your build folder, run `./Zuno ../sample.lua`

Example
---
Here is a sample Zuno lua file. It can also be found in the root directory of the project as `sample.lua`, so you can run it.
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
