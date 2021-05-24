import pymysql

db = pymysql.connect(user='root',password='1234', host='localhost', db='smart_factory', charset = 'utf8')

cursor = db.cursor()  #dbconnect


#table = "CREATE TABLE RGBdata (RED int(100),GREEN int(100), BLUE int(100), TOTAL int(100))" #table create
init = "TRUNCATE TABLE RGBdata"  #initializtion
sql = "INSERT INTO RGBdata(RED, GREEN, BLUE, TOTAL) VALUES(%s,%s,%s,%s)"  #table insert
storage = "INSERT INTO storage(RED,GREEN,BLUE,TOTAL) SELECT * FROM RGBdata ORDER by total desc limit 1;" #stack last data 

t = 0
r = int(input())
g = int(input())
b = int(input())
t += r+g+b 
        
cursor.execute(init)
cursor.execute(sql,(r,g,b,t))
cursor.execute(storage)


db.commit()
    

 


