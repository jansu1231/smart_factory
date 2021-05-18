from smbus import SMBus
import time

addr = 0x8 # bus address
sensor = 0x29
bus = SMBus(1) # indicates /dev/ic2-1

numb = 1


print ( "1 for START or 0 STOP")

while 1:
    
    conveyor = input(">>>>   ")
    
    if conveyor == "1":
        bus.write_byte(addr,1)
    elif conveyor == "2":
        bus.write_byte(addr,2)
    
    time.sleep(5)
    
    result = bus.read_byte(addr)
    
    print(chr(result))
    
    
    