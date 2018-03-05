<?php
	require_once("Cell.class.php");
	require_once("Ship.class.php");

	class ShipFragment implements Cell {
		private $_ship;
		private $_icon;

		public $x;
		public $y;

		public $rotation;

		public function setX(int $x) { $this->x = $x; }
		public function setY(int $y) { $this->y = $y; }

		public function getShip(): Ship { return ($this->_ship); }

		public function onClickJS(array &$grid): String {
			return ($this->_ship->onClickJS($grid));
		}

		public function onPost(array &$grid) {
			return ($this->_ship->onPost($grid));
		}

		public function getTitle(): String {
			return ($this->_ship->getName());
		}

		public function getIconURL(): String {
			return ($this->_icon);
		}

		public function getRotation(): String {
			return ("{$this->rotation}");
		}

		public function rotateLeft() {
			$this->rotation -= 90;
			if ($this->rotation < 0)
				$this->rotation = 270;
		}

		public function rotateRight() {
			$this->rotation += 90;
			if ($this->rotation > 270)
				$this->rotation = 0;
		}

		public function __construct(Ship $ship, String $icon) {
			$this->_ship = $ship;
			$this->_icon = $icon;

			$this->x = -1;
			$this->y = -1;
			$this->maxWidth = 150;
			$this->maxHeight = 100;

			$this->rotation = 0;
		}
	}
?>
