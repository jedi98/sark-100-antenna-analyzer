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

#ifndef EVENTRECEIVER_H
#define EVENTRECEIVER_H

class EventReceiver
{
public:
    enum event_t {progress_event};
    //union eventarg_t {double d; int i;};

    //EventReceiver();
    virtual void RaiseEvent(event_t event,int arg) = 0;

private:
};

#endif // EVENTRECEIVER_H
