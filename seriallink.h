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

#ifndef SERIALLINK_H
#define SERIALLINK_H

#include <QString>

#ifdef ENABLE_DUMMY_DEV
#include "dummydev.h"
#else
#include "serialdev.h"
#endif

#define FMIN 1000000
#define FMAX 60000000

#ifdef ENABLE_DUMMY_DEV
class SerialLink : public DummyDev
#else
class SerialLink : public SerialDev
#endif
{
public:
    SerialLink(const char *dev,int speed);
    //~SerialLink();

    void TxCmd(const char *cmd);

    void Cmd_Scan(long fstart, long fend, long fstep, bool useraw, EventReceiver *erx);
    void Cmd_Off(EventReceiver *erx);

protected:
};

#endif // SERIALLINK_H
