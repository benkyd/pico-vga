.ONESHELL:

all: compile flash

compile:
	cd build && cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=on && make

flash: compile
	sudo mount -L RPI-RP2 /mnt
	sudo cp build/pico_vga.uf2 /mnt
	echo "Copied pico_vga.uf2 to pico"

clean:
	rm -rf build
	mkdir build

