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

#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

//#define ENABLE_DUMMY_DEV

namespace Config
{
    extern QString dir_data;
    extern double swr_max, swr_bw_max, Z_Target;
    extern const char
      *Org,*App,*DOM_ENCODING,
      *SERIAL_DEV_FILTER;

    void read();
    void write();
}

#endif // CONFIG_H
