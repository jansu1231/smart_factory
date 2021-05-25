from smbus import SMBus
import time
import pymysql

db = pymysql.connect(user='root',
                     password='1234',
                     host='localhost',
                     db='smart_factory',
                     charset = 'utf8')

cursor = db.cursor()  #dbconnect

init = "TRUNCATE TABLE RGBdata"  #initializtion
sql = "INSERT INTO RGBdata(RED, GREEN, BLUE, TOTAL)VALUES(%s,%s,%s,%s)"  #table insert
storage = "INSERT INTO storage(RED,GREEN,BLUE,TOTAL) SELECT * FROM RGBdata ORDER BY total desc limit 1" #stack last data


addr = 0x8 # bus address
sensor = 0x29
bus = SMBus(1) # indicates /dev/ic2-1
r = 0
g = 0
b = 0
t = 0




try :
    while True:
    
        time.sleep(3)
        
        data = bus.read_byte(addr)
        
        print(data)  #Show sensor data
        
        if data == 82:
            r += 1
        elif data == 71:
            g += 1
        elif data == 66:
            b += 1

        t = r+g+b
         
        cursor.execute(init) 
        cursor.execute(sql,(r,g,b,t))  #insert data
        
        db.commit()
        
except KeyboardInterrupt:

    cursor.execute(storage)
    db.commit()
    