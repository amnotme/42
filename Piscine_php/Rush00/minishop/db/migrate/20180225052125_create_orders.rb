class CreateOrders < ActiveRecord::Migration[5.1]
  def change
    create_table :orders do |t|
      t.float :subtotal
      t.float :total
      t.float :tax
      t.float :shipping

      t.timestamps
    end
  end
end
