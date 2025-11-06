function load()
    print("Called from Lua!")
    print(zuno.window.should_close())

    print("Handle: ", self.handle)
    print("Name: ", self.name)

    enemy = zuno.create("Test", "../sample/entity_script.lua");
    print(enemy.name)
end

function zuno.fixed_update()
end

function zuno.update(dt)
end

function zuno.draw()
end

function zuno.key_pressed(key)
    print("Key pressed: ", key)
    if key == 256 then
        zuno.quit()
    end
end

function zuno.mouse_pressed(mb)
    print(mb)
end

function zuno.resize(w, h)
    print(w, h)
end

function zuno.on_quit()
    print("Quit!")
end
