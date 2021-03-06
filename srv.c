/* Copyright 2011 Keith Rarick

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "t.h"
#include <stdlib.h>
#include <sys/socket.h>
#include <event.h>
#include "dat.h"


void
srv(int fd)
{
    int r;

    r = listen(fd, 1024);
    if (r == -1) {
        twarn("listen");
        return;
    }

    accept_handler = (evh)h_accept;
    unbrake();
    event_dispatch();
    twarnx("event_dispatch error");
    exit(1);
}
