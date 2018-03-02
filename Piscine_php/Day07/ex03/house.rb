class House
  def introduce
    if !get_house_name.nil?
      "House #{get_house_name} of #{get_house_seat} : #{get_house_motto}"
    else
      raise 'error'
    end
  end

  def get_house_name; end

  def get_house_motto; end

  def get_house_seat; end
end
