class Jaime
  def sleep_with(person)
    puts "Not even if I'm drunk !" if person.class == Tyrion
    puts "Let's do this." if person.class == Sansa
    puts "With pleasure but only in a tower in Winterfell, then." if person.class == Cercei
  end
end
