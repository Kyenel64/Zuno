i = 0

function zuno.load()
    print("Called from Lua!")
    print(zuno.window.is_open())
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
