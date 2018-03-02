require_relative 'lannister'
require_relative 'jaime'
require_relative 'tyrion'

class Stark; end
class Cercei < Lannister; end
class Sansa < Stark; end

j = Jaime.new
c = Cercei.new
t = Tyrion.new
s = Sansa.new

j.sleep_with(t)
j.sleep_with(s)
j.sleep_with(c)

t.sleep_with(j)
t.sleep_with(s)
t.sleep_with(c)
