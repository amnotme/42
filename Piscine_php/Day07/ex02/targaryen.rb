class Targaryen
  def resists_fire
    false
  end

  def get_burned
    return "emerges naked but unharmed" if resists_fire
    return "burs alive" if !resists_fire
  end
end
