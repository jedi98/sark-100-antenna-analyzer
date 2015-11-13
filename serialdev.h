/*
(C) Copyright 2015 Jeremy Burton

This file is part of Sark-100-antenna-analyzer.

Sark-100-antenna-analyzer is free software: you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

Sark-100-antenna-analyzer is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SERIALDEV_H
#define SERIALDEV_H

#include <QString>

class SerialDev
{
public:
    SerialDev(const char *dev,int speed);
    ~SerialDev();

    int RxLine();
    int RxFlush();
    void TxData(const void *buf, size_t count);

    bool IsUp();

    QString devname;

protected:
    int devfd;

    char rxbuff[128];
    int rxbufflen;
};

#endif // SERIALDEV_H
