===========================================================
        BU-69092 AceXtreme SDK and DDK for Windows(R)
                Copyright (c) 2000-2020
                Data Device Corporation
                  All Rights Reserved

Package Version: 4.4.1.4
Package Date:    05-Feb-2020
===========================================================

--------
OVERVIEW
--------
The E2MA ,EMA(Enhanced Mini-ACE)and AceXtreme Run Time Library provides an easy
to use software development platform for DDC's Enhanced Mini-ACE components
and AceXtreme Family of Products.

---------------------
Software Installation
---------------------
The software package is distributed in compressed form and is to be
installed by launching the 'setup.exe' program found in the software
distribution and following the prompts during the install process.

----------------
REVISION HISTORY
----------------
For up-to-date revision history of the BU-69092 SDK and DDK, please
see 'release-notes.txt', found in the selected installation folder.

-------------------
Ace Support Library
-------------------
Available in version 3.1.1 and greater.
This feature installs the Ace Library Support functions.  All functions and
APIs provided in this feature replace the functions and APIs provided in
DDC's BU-69082/83 software package.  These enhanced functions will now operate
using all E2MA, EMACE and AceXtreme drivers and APIs installed with the AceXtreme
package.   The BU-69092S0-AceXtreme Windows package must be installed if using
the functions and APIs in this feature.  Warning - any existing copies of
ace4.dll located in the C:\windows\system32 folder will be overwritten during
installation.

-------------------
VERSION INFORMATION
-------------------
DDC versioning mask is defined as X.Y.Z.  'X' is the major revision and
denotes a major change in design and functionality.  'Y' is the minor
revision and denotes an update or added functionality.  'Z' is the
engineering release number and is only present on non-validated
packages.  Please note that if the version of this package has a 'Z'
digit other than '0' (or not present), it is deemed an 'Engineering
Release' and has not passed DDC's internal software validation.

-------------
Device Driver
-------------
The device driver files are found in the base directory of the
software distribution.  Once the Multi-IO hardware has been
installed, the Plug and Play manager will prompt the user for the
relevant driver information file.  Traverse to the location of the
appropriate '.inf' file and continue as usual to complete the
installation of the desired driver.

-----------------------------------------
Run Time Library and Application Programs
-----------------------------------------
SDK

The RTL consists of a DLL file which is installed in the Windows
'system32' directory, a '.lib' file located in the 'libraries\emacepl\bin'
install directory, and a set of header files found in the 'include'
directory.  In order to build application programs utilizing the
E2MA,EMA or AceXtreme Family of devices, include the 'STDEMACE.H'
file in the application program source code and the 'emacepl.lib'
file in the project.  Refer to the EMACE PLUS SDK Software Manual for
further details regarding the Application Programming Interface.

DDK
The package contains all source code and Visual Studio Projects needed
to build the RTL DLL and Lib files for the RTL software.  During
installation, the emacepl.dll file is installed in the 'system32'
directory.  In order to build application programs utilizing the
E2MA,EMA or AceXtreme Family of devices, include the 'STDEMACE.H'
file in the application program source code and the 'emacepl.lib'
file in the project.  Refer to the EMACE PLUS SDK Software Manual for
further details regarding the Application Programming Interface.

Please note:  A build of the emacepl library project is required before
attempting to build any of the supplied sample projects.

---------------
Sample Programs
---------------
Sample programs are supplied in source code and executable form.
To run the installed binaries, open a command prompt window and
launch the desired program from the command line.  To build a
particular program from the available source files, create a project
including the desired sample program, and include the 'emacepl.lib'
file in the build.  Refer to the EMACE PLUS SDK Software Manual
for descriptions of the provided sample programs.

-------------
Control Panel
-------------
The DDC Card Manager program is used to associate a logical device
number with a particular DDC device installed in the user's system.
It can be launched from the Windows Start Menu under the
'Data Device Corporation' folder, or from within the system
control panel.

Under 64-Bit Windows Vista and Windows 7, the DDC Card Manager must be
run as administrator.

When using the DDC Card Manager to update a device driver, the
notification of a successful update will be displayed behind the card
manager.  The user will have to use the ALT+TAB keys to switch to the
hidden screen to complete the driver update.

----------------
Software Manuals
----------------
The software manuals for DD-42992D0,S0 and E2MA_Flash Utility Instructions
can be found on the DDC website in the following location:

http://www.ddc-web.com/Products/MIL-STD-1553/Cards.aspx

All manuals for the board selected on this webpage can be found and downloaded
from the documentations tab displayed when the board is clicked.

-------------------
Contact information
-------------------
Please direct any questions or comments about this software to
our Databus Applications Department in Bohemia NY.

Data Device Corporation
105 Wilbur Place
Bohemia, NY 11716
(631) 567-5600x7234
http://www.ddc-web.com/ContactUs/TechSupport.aspx
