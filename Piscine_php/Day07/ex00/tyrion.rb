require_relative 'lannister'

class Tyrion < Lannister
  def initialize
    super
    puts "My name is Tyrion"
  end

  def get_size
    return "Short"
  end

end
