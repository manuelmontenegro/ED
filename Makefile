.PHONY: build clean serve all open

all: build

clean:
	mdbook clean -d docs

build:
	mdbook build -d docs

open:
	xdg-open docs/index.html

serve:
	mdbook serve -o -d docs