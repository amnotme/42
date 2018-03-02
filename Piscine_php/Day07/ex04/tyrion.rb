class Tyrion
  def sleep_with(person)
    puts "Not even if I'm drunk !" if person.class == Jaime
    puts "Let's do this." if person.class == Sansa
    puts "Not even if I'm drunk !" if person.class == Cercei
  end
end
