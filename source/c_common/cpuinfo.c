/*
 * This file is part of RPIO.
 *
 * Copyright
 *
 *     Copyright (C) 2013 Chris Hager <chris@linuxuser.at>
 *
 * License
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published
 *     by the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details at
 *     <http://www.gnu.org/licenses/lgpl-3.0-standalone.html>
 *
 * Documentation
 *
 *     http://pythonhosted.org/RPIO
 */
#include <stdio.h>
#include <string.h>
#include "cpuinfo.h"

// Writes the hex revision str into the argument and returns:
//   2  (raspberry with revision 2 pin setup)
//   1  (raspberry with revision 1 pin setup)
//   0  (not a raspberry pi)
//   -1 (could not open /proc/cpuinfo)
//
// revision_hex will be four characters revision id (eg. '0004'),
// the over-voltage header, if present, is removed (since it is
// not consistently present on all overclocked boards).
int
get_cpuinfo_revision(char *revision_hex)
{
    FILE *fp;
    char buffer[1024];
    char hardware[1024];
    int  rpi_found = 0;
	int  bcm2709 = 0;
	int board_rev = 3;

    if ((fp = fopen("/proc/cpuinfo", "r")) == NULL)
        return -1;

    while(!feof(fp)) {
        fgets(buffer, sizeof(buffer) , fp);
        sscanf(buffer, "Hardware	: %s", hardware);
        if (strcmp(hardware, "BCM2708") == 0||
            strcmp(hardware, "BCM2709") == 0||
            strcmp(hardware, "BCM2835") == 0||
            strcmp(hardware, "BCM2836") == 0)
            rpi_found = 1;

        if (strcmp(hardware, "BCM2709") == 0)
            bcm2709 = 1;
        sscanf(buffer, "Revision	: %s", revision_hex);
    }
    fclose(fp);

    if (!rpi_found) {
        revision_hex = NULL;
        return 0;
    }

    // If over-voltage is present, remove it
    char* pos = strstr(revision_hex, "1000");
    if (pos && pos - revision_hex == 0 && strlen(revision_hex) > 5) {
        strcpy(revision_hex, revision_hex+(strlen(revision_hex) - 4));
    }

    // Returns revision
    if ((strcmp(revision_hex, "0002") == 0) ||
        (strcmp(revision_hex, "0003") == 0))
        board_rev = 1;
    else if ((strcmp(revision_hex, "0004") == 0)
        || (strcmp(revision_hex, "0005") == 0)
        || (strcmp(revision_hex, "0006") == 0)
        || (strcmp(revision_hex, "0007") == 0)
        || (strcmp(revision_hex, "0008") == 0)
        || (strcmp(revision_hex, "0009") == 0)
        || (strcmp(revision_hex, "000d") == 0)
        || (strcmp(revision_hex, "000e") == 0)
        || (strcmp(revision_hex, "000f") == 0))
        board_rev = 2;
    else   // We'll call Model A+, B+, Pi2, Pi3 and Zero rev3
        board_rev = 3;

    return (bcm2709 << 8) | board_rev;
}

uint32_t get_peri_base(void){
	uint32_t base = 0x20000000;
	FILE * filp;
	char buf[512];

	filp = fopen ("/proc/cpuinfo", "r");

	if (filp != NULL)
	{
		while (fgets(buf, sizeof(buf), filp) != NULL)
		{
			if (!strncasecmp("model name", buf, 10))
			{
				if (strstr (buf, "ARMv6") != NULL)
				{
					base = 0x20000000;
					break;
				}
				else if ((strstr (buf, "ARMv7") != NULL) | //
						(strstr (buf, "ARMv8") != NULL) | 
						(strstr (buf, "CPU architecture: 7") != NULL) | // aarch64 kernel may report this way
						(strstr (buf, "CPU architecture: 8") != NULL)) // aarch64 kernel may report this way
				{
					base = 0x3F000000;
					break;
				}
			}
		}

		fclose(filp);
	}
	return base;
}