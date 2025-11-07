function load()
    print("Called from Lua!")
    print(zuno.window.should_close())

    print("Handle: ", self.handle)
    print("Name: ", self.name)

    enemy = zuno.create("Test", "../sample/entity_script.lua");
    print(enemy.name)
end

function fixed_update()
end

function update(dt)
end

function draw()
end

function key_pressed(key)
    print("Key pressed: ", key)
    if key == 256 then
        zuno.quit()
    end
end

function mouse_pressed(mb)
    print(mb)
end

function resize(w, h)
    print(w, h)
end

function on_quit()
    print("Quit!")
end
