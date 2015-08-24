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

#ifndef DUMMYDEV_H
#define DUMMYDEV_H

#ifdef ENABLE_DUMMY_DEV

#include <QString>

class DummyDev
{
public:
    DummyDev();
    //~DummyDev();

    int RxLine();
    int RxFlush();

    bool IsUp();

    QString devname;

protected:
    int devfd;

    char rxbuff[128];
    int rxbufflen;

    const char *dummy_data;
    int dummy_pos;
};

#endif

#endif // DUMMYDEV_H
