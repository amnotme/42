require_relative 'house'

class HouseStark < House
  def get_house_name
    "Stark"
  end

  def get_house_motto
    "Winter is coming"
  end
  
  def get_house_seat
    "Witerfell"
  end
end

class HouseMartell < House
  def get_house_name
    "Martell"
  end

  def get_house_motto
    "Unbowed, Unbent, Unbroken"
  end

  def get_house_seat
    "Sunspear"
  end
end

houses = [HouseStark.new, HouseMartell.new]
houses.each do |h|
  puts h.introduce
end
