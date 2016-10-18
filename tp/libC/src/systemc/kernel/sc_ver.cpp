/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2002 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License Version 2.3 (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.systemc.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

    sc_ver.cpp -- Version and copyright information.

    Original Author: Stan Y. Liao, Synopsys, Inc.

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/


#include "systemc/kernel/sc_ver.h"
#include "systemc/utils/sc_iostream.h"


static
const char copyright[] =
    "        Copyright (c) 1996-2002 by all Contributors\n"
    "                    ALL RIGHTS RESERVED";

static
const char systemc_version[] =
    "             SystemC 2.0.1 --- " __DATE__ " " __TIME__;

const char*
sc_copyright()
{
    return copyright;
}

const char*
sc_version()
{
    return systemc_version;
}


// Taf!
