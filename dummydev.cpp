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

#include "config.h"

#ifdef ENABLE_DUMMY_DEV

#include "dummydev.h"

DummyDev::DummyDev()
{
    dummy_data = "";
    dummy_pos = 0;
}

bool DummyDev::IsUp()
{
    return true;
}

int DummyDev::RxLine()
{
    for (rxbufflen=0; dummy_data[dummy_pos]; dummy_pos++)
    {
        switch (dummy_data[dummy_pos])
        {
        case '\n':
            rxbuff[rxbufflen]='\0';
            dummy_pos++;
            return 0;
        case '\0':
            rxbuff[rxbufflen]='\0';
            return 3;
        default:
            rxbuff[rxbufflen++]=dummy_data[dummy_pos];
        }
    }
    return 3;
}

int DummyDev::RxFlush()
{
    return 1;
}

#endif
