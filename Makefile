all: clean
	gcc -o pkg pkg.c utils.c

clean:
	rm -rf pkg
