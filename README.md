**Thanks To** Adam Coddington (http://coddingtonbear.net) for sorting out the changes for OSX and driving the push onte github. Also for writing better instructions than my originals.

SARK 100 / MINI 60 Antenna Analyzer GUI
=======================================

![](http://jedi98.uk/images/Analyzer_Screenshot1.png)

Requirements
------------

* QT Framework


Installation Instructions
-------------------------

### Linux

From the project directory, run the following commands:

```
qmake
make
```

You can then run this software by running `./analyzer`.

### OSX

From the project directory, run the following commands:

```
qmake -spec macx-g++ -o Makefile analyzer.pro
make
```

You can then run the program by running `open analyzer.app`.


Running a Scan using a SARK100 / MINI60
---------------------------------------

1. Turn on your antenna analyzer and connect it to your antenna.
2. Press the "Config" button until you see the words "PC Link" on your screen, then press the down arrow.  Your screen should now show the message "Waiting Link".
3. Use a USB cable to connect your computer with your antenna analyzer.
4. Open the Antenna Analyzer app you compiled using the instructions above.
5. From the Antenna Analyzer app, use the "Link" menu to select your device.  You probably have only one option displayed, but if there are multiple options, you may need to perform some experiments to identify which of the listed devices is your Antenna Analyzer.
6. Use the displayed GUI to select which frequencies you'd like to scan, and press the "Scan" button.

