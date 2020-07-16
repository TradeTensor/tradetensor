
Debian
====================
This directory contains files used to package tradetensord/tradetensor-qt
for Debian-based Linux systems. If you compile tradetensord/tradetensor-qt yourself, there are some useful files here.

## tradetensor: URI support ##


tradetensor-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tradetensor-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tradetensor-qt binary to `/usr/bin`
and the `../../share/pixmaps/tradetensor128.png` to `/usr/share/pixmaps`

tradetensor-qt.protocol (KDE)

