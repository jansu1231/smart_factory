from smbus import SMBus
import time

import serial
import pymysql


#db connect
db = pymysql.connect( 
    host="localhost",
    user="root",
    password="1234",
    db="smart_factory",
    charset='utf8')
print(type(db))

cursor = db.cursor()
print(type(cursor))

call = db.fetchall()






addr = 0x8 # bus address
sensor = 0x29
bus = SMBus(1) # indicates /dev/ic2-1
R,G,B = 0


      
while True:
    
    time.sleep(3)
    
    data = bus.read_byte(addr)
    
    print(data)
    
    sql = "INSERT INTO color (RED,GREEN,BLUE,TOTAL) VALUES (%s,%s,%s,%s)"
    
    if data == 82:
        R+=1
    elif data == 71:
        G+=1
    elif data == 66:
        B+=1
        
    

    cursor.execute(sql,data)

    for x in call:
    print (x)
        
    db.commit()
    

    
    