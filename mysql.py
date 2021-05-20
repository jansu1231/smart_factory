import pymysql

db = pymysql.connect(host='localhost', user='root',password='1234', db='smart_factory', charset = 'utf8')

cursor = db.cursor()  #dbconnect


#table = "CREATE TABLE RGBdata (RED int(100),GREEN int(100), BLUE int(100), TOTAL int(100))" #table create
sql = "INSERT INTO RGBdata(RED, GREEN, BLUE, TOTAL) VALUES (%d,%d,%d,%d)"  #table insert



    #cursor.execute(table)

cursor.execute(sql,1,2,3,4)




db.commit()

