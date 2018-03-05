<?php
	require_once("Cell.class.php");

	class Obstacle implements Cell {

		const DEFAULT = 0;
		const FACE = 1;

		private $_type = self::DEFAULT;
		private $_width = 1;
		private $_height = 1;

		public function getWidth() { return $this->_width; }
		public function getHeight() { return $this->_height; }

		const ICONS = array(
			"http://www.pngmart.com/files/4/Asteroid-PNG-Clipart.png",
			"https://images-na.ssl-images-amazon.com/images/I/71xwHBvIB8L.png",
			"https://vignette.wikia.nocookie.net/astroempires/images/6/62/Astro_Asteroid_medium.png/revision/latest?cb=20110617211703",
			"https://dg-cms-uploads-production.s3.amazonaws.com/uploads/page_field/image_value/493/WV4_satellite_noFoil_05_ROTATION_00000.png",
			"http://icons.iconarchive.com/icons/aha-soft/free-global-security/512/Satellite-icon.png"
		);

		private $_icon;
		private $_rotation;

		public function setX(int $x) { }
		public function setY(int $y) { }

		public function onClickJS(array &$grid): String {
			return ("");
		}

		public function onPost(array &$grid) { }

		public function getTitle(): String {
			return ("Obstacle");
		}

		public function getIconURL(): String {
			return (Obstacle::ICONS[$this->_icon % sizeof(Obstacle::ICONS)]);
		}

		public function getRotation(): String {
			return ("{$this->_rotation}");
		}

		public function __construct(int $icon, int $rotation) {
			$this->_icon = $icon;
			$this->_rotation = ($rotation % 4) * 90;
		}

		public function setFace($width, $height)
		{
			$this->_width = $width;
			$this->_height = $height;
			$this->_type = self::FACE;
		}

		public function isFace()
		{
			if ($this->_type == self::FACE)
				return true;
			else
				return false;
		}
	}
?>
