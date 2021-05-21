from smbus import SMBus
import time
import pymysql

db = pymysql.connect(user='root',
                     password='1234',
                     host='localhost',
                     db='smart_factory',
                     charset = 'utf8')

cursor = db.cursor()  #dbconnect

#table = "CREATE TABLE RGBdata (RED int(100),GREEN int(100), BLUE int(100), TOTAL int(100))" #table create
sql = "INSERT INTO RGBdata(RED, GREEN, BLUE, TOTAL)VALUES(%s,%s,%s,%s)"  #table insert

addr = 0x8 # bus address
sensor = 0x29
bus = SMBus(1) # indicates /dev/ic2-1
r = 0
g = 0
b = 0
t = 0

      
while True:
    
    time.sleep(3)
    
    data = bus.read_byte(addr)
    
    print(data)
    
    sql = "INSERT INTO color (RED,GREEN,BLUE,TOTAL) VALUES (%s,%s,%s,%s)"
    
    if data == 82:
        r += 1
    elif data == 71:
        g += 1
    elif data == 66:
        b += 1

    t += r+g+b
        
    cursor.execute(sql,(r,g,b,t))  #insert data

    db.commit()