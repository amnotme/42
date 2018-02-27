require 'mysql2'  
  
#my = Mysql.new(hostname, username, password, databasename)  
con = Mysql2.new('localhost', 'root', '', 'mysql')  
rs = con.query('select * from student')  
rs.each_hash { |h| puts h['name']}  
con.close
