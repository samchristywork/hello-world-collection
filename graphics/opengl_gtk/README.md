## Overview

This is the OpenGL + GTK version of "Hello, World!". It embeds a GTK GL area
widget in a GTK window and uses OpenGL (via libepoxy) to render a rotating 3D
cube. GLM is used for matrix math. A button toggles the rotation on and off and
prints "Hello, World!" to stdout.

Press Escape to exit.

It can be built with `make`.

## Dependencies

```
g++
libepoxy-dev
libglm-dev
libgtk-3-dev
make
pkg-config
```
