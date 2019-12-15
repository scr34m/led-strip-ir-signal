
# Cheap LED strip IR remote fake signal
 
Goal is to replace the IR transmitter with a signal from Raspberry Pi 3. The IR receiver uses NEC IR protocol, decoded with a Saleae logic analyser.

- works from USB 5v
- two IC an EEPROM and a PIC12Fxxxx or PIC16Fxxxx
- 3 white wire desoldered from the board, left wire is the signal line

![enter image description here](/pcb.jpg)


Handy links:
- https://www.saleae.com
- https://github.com/kodizhuk/Salae-Logic-NEC-Analyzer
- https://github.com/LiveOverflow/NECAnalyzer
  
This is the strip
https://www.praktiker.hu/lakberendezes-vilagitas-butor/lampa-izzo/belteri-led-vilagitas/331868-global-rgb-led-szalag-szett-2m-max7-2w/m-ip65-usb-taviranyitoval-30xsmd5050

