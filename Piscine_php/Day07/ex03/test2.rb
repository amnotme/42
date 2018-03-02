require_relative 'house'

class DrHouse < House
  def diagnose
    puts "It's not lupus"
  end
end

house = DrHouse.new
puts house.introduce
