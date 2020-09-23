all: clean
	cc -o pkg pkg.c utils.c actions.c

clean:
	rm -rf pkg
