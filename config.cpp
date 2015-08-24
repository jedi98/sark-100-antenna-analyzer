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

#include <QString>
#include <QSettings>

#include "config.h"

namespace Config
{
  const char
    *Org = "Jedi98",
    *App = "Antenna Analyzer",
    *DOM_ENCODING = "UTF-8",
    *SERIAL_DEV_FILTER = "ttyUSB*;tty.usbserial*;rfcomm*";

  QString dir_data;
  double swr_max, swr_bw_max, Z_Target;

  void read()
  {
    QSettings settings(Org, App);

    dir_data = settings.value("dir_data",".").toString();
    swr_max = settings.value("swr_max","10").toDouble();
    swr_bw_max = settings.value("swr_bw_max","1.5").toDouble();
    Z_Target = settings.value("Z_Target","50").toDouble();
  }

  void write()
  {
    QSettings settings(Org, App);

    settings.setValue("dir_data", dir_data);
    settings.setValue("swr_max", swr_max);
    settings.setValue("swr_bw_max", swr_bw_max);
    settings.setValue("Z_Target", Z_Target);
  }
}
