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

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <poll.h>

#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "config.h"
#include "serialdev.h"

SerialDev::SerialDev(const char *dev,int speed)
{
    rxbufflen=0;

    devname = dev;
    devfd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
    if (devfd != -1)
    {
          struct termios termattr;
          tcgetattr(devfd, &termattr);
          cfmakeraw(&termattr);
  printf("\tc_cflag=%x\n",termattr.c_cflag);
          termattr.c_oflag &= ~(ONLCR);
  //#if defined(__APPLE__) && defined(__MACH__)
          termattr.c_cflag &= ~(CRTSCTS|PARENB|CSTOPB);
  //#else
  //        termattr.c_cflag &= ~(CRTSCTS|PARENB|CSTOPB|CBAUD);
  //#endif
          termattr.c_cflag |= CS8 | CLOCAL;
  printf("\tc_cflag=%x\n",termattr.c_cflag);
          switch (speed)
          {
            case 300: cfsetspeed(&termattr, B300); break;
            case 600: cfsetspeed(&termattr, B600); break;
            case 1200: cfsetspeed(&termattr, B1200); break;
            case 2400: cfsetspeed(&termattr, B2400); break;
            case 4800: cfsetspeed(&termattr, B4800); break;
            case 9600: cfsetspeed(&termattr, B9600); break;
            case 19200: cfsetspeed(&termattr, B19200); break;
            case 38400: cfsetspeed(&termattr, B38400); break;
            case 57600: cfsetspeed(&termattr, B57600); break;
            case 115200: cfsetspeed(&termattr, B115200); break;
          }
  printf("\tc_cflag=%x\n",termattr.c_cflag);
          tcsetattr(devfd, TCSANOW, &termattr);
      }
  printf("\tdevfd %d\n",devfd);
}

SerialDev::~SerialDev()
{
  if (devfd != -1)
    close(devfd);
}

int SerialDev::RxFlush()
{

    pollfd fds[] = {{devfd, POLLIN, 0 }};
    int timeout = 500;    //500msec, move somewhere
    int pstatus,rstatus;

    for (rxbufflen=0;;)
    {
        pstatus = poll(fds, 1, timeout);
        if (pstatus > 0)                                        //Success
        {
            if (fds[0].revents & (POLLERR|POLLHUP|POLLNVAL))
                return 3;   //Error, eof, hup etc quit
            else
                if (fds[0].revents & POLLIN)					// There's some data to read
                {
                    rstatus = read(devfd, rxbuff+rxbufflen, 1);
                    if (rstatus == -1)
                    {
                        if (errno == EAGAIN)					// Treat would block error as a timeout
                            return 1;   //Timeout
                        else
                            return 4;   //Error reading
                    }
                    else
                    {
printf("RxFlush: %c\n",rxbuff[rxbufflen]);
                    }
                }
        }
        else if (pstatus == 0)                                  //Timeout
            return 1;
        else if (pstatus == -1)                                 //Error polling
            return 2;
    }
}

int SerialDev::RxLine()
{

    pollfd fds[] = {{devfd, POLLIN, 0 }};
    int timeout = 4000;    //10sec, move somewhere
    int pstatus,rstatus;

    for (rxbufflen=0;;)
    {
        pstatus = poll(fds, 1, timeout);
        if (pstatus > 0)                                        //Success
        {
            if (fds[0].revents & (POLLERR|POLLHUP|POLLNVAL))
                return 3;   //Error, eof, hup etc quit
            else
                if (fds[0].revents & POLLIN)					// There's some data to read
                {
                    rstatus = read(devfd, rxbuff+rxbufflen, 1);
                    if (rstatus == -1)
                    {
                        if (errno == EAGAIN)					// Treat would block error as a timeout
                            return 1;   //Timeout
                        else
                            return 4;   //Error reading
                    }
                    else
                    {
//printf("RxLine: c=%c (0x%02x)\n",rxbuff[rxbufflen],rxbuff[rxbufflen]);
                        switch (rxbuff[rxbufflen])
                        {
                        case '\r':  break;
                        case '\n':
                            rxbuff[rxbufflen] = '\0';
                            return 0;
                        default:
                            rxbufflen += rstatus;
                            break;
                        }
                    }
                }
        }
        else if (pstatus == 0)                                  //Timeout
            return 1;
        else if (pstatus == -1)                                 //Error polling
            return 2;
    }
}

bool SerialDev::IsUp()
{
   return devfd != -1;
}

void SerialDev::TxData(const void *buf, size_t count)
{
    write(devfd,buf,count);
}
