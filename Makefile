all: pkg

pkg:
	cc -o pkg pkg.c actions.c utils.c

clean:
	rm -rf pkg

install: all
	mkdir -p /usr/local/bin
	cp -f pkg /usr/local/bin
	chmod 755 /usr/local/bin
	mkdir -p /usr/local/share/man/man1
	cp -f pkg.1 /usr/local/share/man/man1
	chmod 644 /usr/local/share/man/man1/pkg.1

uninstall:
	rm -rf /usr/local/bin/pkg
	rm -f /usr/local/share/man/man1/pkg.1
