require_relative 'targaryen'

class Viserys < Targaryen; end

class Daenerys < Targaryen
  def resists_fire
    true
  end
end

viserys = Viserys.new
daenerys = Daenerys.new

puts "Viserys #{viserys.get_burned}"
puts "Daenerys #{daenerys.get_burned}"
