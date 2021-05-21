import pymysql

db = pymysql.connect(user='root',password='1234', host='localhost', db='smart_factory', charset = 'utf8')

cursor = db.cursor()  #dbconnect



#table = "CREATE TABLE RGBdata (RED int(100),GREEN int(100), BLUE int(100), TOTAL int(100))" #table create
sql = "INSERT INTO RGBdata(RED, GREEN, BLUE, TOTAL) VALUES(%s,%s,%s,%s)"  #table insert

t = 0

for i in range(5):
    
    r = int(input())
    g = int(input())
    b = int(input())
    t += r+g+b 
        
    cursor.execute(sql,(r,g,b,t))
    
    db.commit()
    
    for row in 
    
    rs = cursor.fetchall()
    
    print(rs)

    

