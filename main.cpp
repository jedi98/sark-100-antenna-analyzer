/*
(C) Copyright 2015 Jeremy Burton

This file is part of Sark-100-antenna-analyzer.

Sark-100-antenna-analyzer is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

Sark-100-antenna-analyzerr is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mainwindow.h"
#include <QApplication>

#include <locale.h>

int main(int argc, char *argv[])
{
    //setlocale(LC_NUMERIC, "C");
    //setlocale(LC_ALL, "fr_FR.UTF-8");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
