ElectroPortis
=============
ElectroPortis is a Windows version of ElectroPaint, the only screensaver.  This
is the real deal.  It is not a clone, nor a reimplementation, nor a product of
manual reverse engineering.  It was made by running the original binary through
a [custom MIPS to C decompiler][epanos].

[epanos]: https://github.com/drvink/epanos

### Downloads

I wish I'd made this clearer, since GitHub does not: there is a pre-built
binary!  Just click the "[releases][rel]" link at the top and download the zip.

[rel]: https://github.com/drvink/electroportis/releases

### How to use

Some new features have been added.  Press "n" to create a cloned ElectroPaint
window.  Press "f" to toggle between the following modes:

* Single full-screen: ElectroPaint will run full-screened on the monitor where
  the master window resided.  Other windows will be closed.
* Spanned full-screen: ElectroPaint will run across all connected monitors.
* Cloned full-screen: ElectroPaint will run a synchronized copy across all
  connected monitors.

If you want a unique copy of ElectroPaint on multiple monitors, simply launch
another instance and single full-screen each one.

To use ElectroPortis as a Windows screensaver, build it, rename
ElectroPortis.exe to ElectroPortis.scr, right click it, and select "Install".

### History of ElectroPaint

There is a a [mini-history][ephistory] of ElectroPaint on the Web.

[ephistory]: http://darkside.cometway.com/content.agent?page_name=Article&name=001

[Many clones and versions inspired by the original][clones] have been made.

[clones]: http://darkside.cometway.com/content.agent?page_name=Article&name=004

Your author also stumbled across a [new development][epjs] in the ElectroPaint
saga.  (The decompiled version presented by ElectroPortis is in fact the OpenGL
version referred to in the README of this repository.)

[epjs]: https://github.com/iamralpht/elektropaintjs

A very old version of the IRIS GL-era ElectroPaint, containing the interactive
features but lacking the script that made ElectroPaint so famous (and possibly
using a different version of the animation code), is available as part of the
[IGL][] distribution.

[IGL]: http://freeweb.siol.net/matevzb2/igl.html

### Notes for nerds

          __    __
         /..\ /| |'-.
        .\_O/ || |   |   OH WOW
     _ /  `._ \|_|_.-'  FREE SOFTWARE
    | /  \__.`=._) (_
    |/ ._/  |"""""""""|  LET ME IN
    |'.  `\ |         |   ON THIS
    ;"""/ / |         |
     ) /_/| |.-------.|
    '  `-`' "         "

### Building

You will need Visual C++ 2013.  gcc is untested, but will probably
work if you roll your own build system.  clang should also work once
it can fully parse the Windows API headers.

### Changes made to the decompiled source

* "static" was added to symbols that didn't need external linkage.
* Relevant initialization routines from ep's "main" were placed in "init_ep".
* The "reshape" routine was rewritten by hand from MIPS disassembly to C.  (This
  was done while attempting an alternative method of adding the cloned mode; the
  decompiled routine worked fine.)
* Memory returned by malloc is zeroed.  Crashes occur otherwise--perhaps IRIX's
  malloc zeroes its memory.
* GL draw calls are wrapped in order to support the cloned mode.

### (Lack of) ports

#### Windows

ElectroPortis should run without issue on Windows XP and newer.

#### Android

Thanks to Peter Kliem, there is an [Android][] version!  It's available on
[Google Play][gplay].

[Android]: http://www.kliemax.de/electroportis.html
[gplay]: https://play.google.com/store/apps/details?id=de.kliemax.electroportis

#### Linux

Most Linux users are probably on 64-bit systems at this point, and the original
ElectroPaint binary is 32-bit (even on 64-bit IRIX systems, much of the IRIX
base system was built as N32).  Since the decompiler has no way of determining
that a given piece of data is a pointer, the emitted source has a restriction:
if the target ABI doesn't have 32-bit pointers (as N32 does), the code will
compile, but immediately crash upon the first pointer dereference.  This makes a
port of any sort infeasible unless you wish to rewrite ep.c or set up a multilib
environment.

#### OS X

Even though OS X still runs x86 binaries as of 10.9, who knows when support for
them will disappear.  Furthermore, the overengineered OS X screensaver framework
loads Mach-O bundles; it does not simply run a binary.  The screensaver
framework is, like the rest of the system, 64-bit, so screensaver mode is
impossible on OS X (unless you rewrite ep.c or come up with some out-of-process
solution).

#### Excuses

I just don't have the time to maintain ports, honestly.  Sorry.  I do have
working code for OS X (sans screensaver capability)--if you'd like it, please
mail me.

### About the code

Part of the reason for adding multiple window/display support was a desire to
provide an example of an OpenGL app that made use of multiple threads and GL
contexts.  There isn't much information available about the "right" way to do
this; it took a while to find the issues preventing it from working smoothly.
Be warned: multiple contexts within one process is a corner case that tends to
expose GL driver bugs.  Using a single thread and GL context to do all rendering
may be the easier option in many cases, or if your needs are more demanding than
recording GL draw calls and playing them back in parallel, try something like
[Equalizer][].

[Equalizer]: http://www.equalizergraphics.com/

The "SHRW2" rwlock used in ElectroPortis is quite nice; it generally has better
performance characteristics than SRWLOCKs and also works on Windows XP.
