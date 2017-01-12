# UNDER CONSTRUCT
# WE WILL RELEASE IN A WEEK



# Self-Driving Learning Environment(SDLE)
This is the Self-Driving Learning Environment(SDLE), a platform designed for AI research. SDLE is based on PCSX2, an PlayStation2 emulator.

We encourage you to use Self-Driving Learning Environment in your research. In return, we would appreciate if you cited SDLE in publications that rely on it (BibTeX entry at the end of this document).

Feedback and suggestions are welcome and may be addressed to any active member of the SDLE team.

Enjoy, The SDLE team

# Quick Start
If you meet the all following conditions, you don't need to follow the all "step by step" instruction.
* You are already able to run Gran Turismo 4 on 64bit Windows system 
* Your PCSX2 is in the "C:\Program Files (x86)\PCSX2 1.4.0" folder,
* You aleady have Visual Studio Community 2015

Here is the short version of instruction to see SDLE.
1. Double click "client_server/SDLE.sln"
2. Press "F7" at VS2015 to build solution
3. Double click "client_server/PCX2_plugin/install_plugin.bat"
4. Double click "client_server/PCX2_agent_server/execute_server.bat"
5. Run PCSX2
6. Click "Config => Plugin/BIOS selector" menu to change controller plugin
7. Select "XPad - modified by Nexell for SDLE" at PAD plugin 
8. Click "OK" button
9. Boot PCSX2 with Gran Turismo 4 image
10. Press 'x' key repeatedly until racing start
11. Press 'Insert' key to activate pre-trained agent
12. Press 'Home' key to diactivate pre-trained agent


# Step by step

1.Dependencies
* 64bit Windows
Currently, Tensorflow supports only 64bit windows.

* PlayStation2 emulator.(PCSX2 for 32bit Windows) : http://pcsx2.net/download/releases/windows/category/40-windows.html
Unfortunately, PCSX2 officially supports only 32bit windows. So we've built our PCSX2 plugin for 32bit Windows.

* Visual Studio Community 2015 : https://www.visualstudio.com/downloads/

* Tensorflow (Optional) : https://www.tensorflow.org/
If you have a machine for Tensorflow, you don't need to install Tensorflow. SDLE already have pre-compiled tensorflow static library(binary) for 64bit windows. But if you want to build by yourself refer to the following.


*Needless to say, you should have Gran Turismo 4 image file and be able to run on your Windows system.

2.Build
* Open solution (client_server/SDLE.sln)
* Build **Release**
Unfortunately again, Tensorflow C/C++ API does not support Debug build currently.
* Copy PCSX2 plugin into your system.
If your PCSX2 is in "C:\Program Files (x86)\PCSX2 1.4.0", then just execute "client_server/PCX2_plugin/install_plugin.bat" Otherwise you should copy the plugin file(client_server/PCX2_plugin/Win32Release/nexell_xpad.dll) into your system, manually.
    copy /y client_server/PCX2_plugin/Win32Release/nexell_xpad.dll "C:\Program Files (x86)\PCSX2 1.4.0\Plugins"

3.Select controller plugin
* Run PCSX2
* Click "Config => Plugin/BIOS selector" menu to change controller plugin
* Select "XPad - modified by Nexell for SDLE" at PAD plugin 
* Click "OK" button

4.Run sample pre-trained agent
* Execute server
Press "Ctrl+F5" at Visual Studio Community 2015
or
Double click "client_server/PCX2_agent_server/execute_server.bat"
* Now boot PCSX2 with Gran Turismo 4 image
* Press 'x' key repeatedly until racing start
* Press 'Insert' key to activate pre-trained agent
* Press 'Home' key to diactivate pre-trained agent

# Capture data for your tranning
* Execute server
* Boot PCSX2 with Gran Turismo 4 image
* Press 'Delete' key to begin capturing
* Press 'End' key to keep the captured data
* Press 'PageDown' key to cencel the captured data
Your captured data is in "client_server/PCX2_agent_server/captured" folder
xxxxxx_xxxx_f_####.gz : RGB pixel data ( unsigned char [####][ CAPTURE_WIDTH * CAPTURE_HEIGHT * 3 ] )
xxxxxx_xxxx_v_####.gz : velocity ( float [####] )
xxxxxx_xxxx_s_####.gz : steering value ( float [####] )
You can modify steering method and captured data format, refer to main_game_interface.h and main_game_capture.cc

# Program your own agent
You can program your own game agent, refer to main_game_interface.h and main_game_agent.cc
You can see sample agent implemented by using Tensorflow C/C++ API.
It just a simple sample, We want to encourage you to make your own Self-Driving agent.









