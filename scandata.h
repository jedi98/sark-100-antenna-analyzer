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

#ifndef SCANDATA_H
#define SCANDATA_H

#include <vector>

#include <dom.h>
#include "eventreceiver.h"

#define max3(v1,v2,v3) ((v1)>(v2)?((v1)>(v3)?(v1):(v3)):((v2)>(v3)?(v2):(v3)))

class Sample
{
public:
    Sample();
    void fromRaw(double vf,double vr,double vz,double va);

    double freq, swr, R, Z, X;
};

class ScanData
{
public:
    ScanData();
    void SetPointCount(int n);
    int GetPointCount();
    void UpdateStats();
    void dummy_data(EventReceiver *);
    void toDom(QDomDocument &doc,QDomElement &parent);
    bool fromDom(QDomElement &e0);

    std::vector<Sample> points;
    //int point_count;

    //timestamp??
    double freq_start,freq_end;
    int swr_min_idx, swr_max_idx, Z_min_idx, Z_max_idx, X_min_idx, X_max_idx, R_min_idx, R_max_idx;
    int swr_bw_lo_idx,swr_bw_hi_idx;
};

#endif // SCANDATA_H
