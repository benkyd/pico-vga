.ONESHELL:

all: compile mount flash

compile:
	cd build && cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=on && make

mount: compile
	sudo mount -L RPI-RP2 /mnt

flash: mount
	sudo cp build/pico_vga.uf2 /mnt
	echo "Copied pico_vga.uf2 to pico"

clean:
	rm -rf build
	mkdir build

