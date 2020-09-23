all: clean
	gcc -o pkg pkg.c utils.c actions.c

clean:
	rm -rf pkg
